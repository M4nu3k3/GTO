/* USER CODE BEGIN Header */
/**
  *********************************************************************************************************************
  * @file           : gto_reader.c
  * @brief          : Transforme un fichier .gto en ligne CSV en un format : [EtudiantID, QCMID, Q1...Q20, NoteFinale]
  *********************************************************************************************************************
  */
#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>
#include <string.h>
#include <dirent.h>
#include <ctype.h>

#define MAX_REPONSES 20
#define OFFSET_REPONSES 0x1A

// Transforme un fichier .gto en ligne CSV
// Format : [EtudiantID, QCMID, Q1...Q20, NoteFinale]
int traiteur_gto(const char *filepath, FILE *csv) {
    FILE *fichier = fopen(filepath, "rb");
    if (!fichier) {
        perror("Erreur ouverture fichier");
        return 0;
    }

    // Lire les IDs dans le nom de fichier
    char nom[256];
    strcpy(nom, strrchr(filepath, '/') ? strrchr(filepath, '/') + 1 : filepath);
    char id_qcm[32], id_etudiant[32];
    if (sscanf(nom, "QCM_%[^_]_de_%[^.].gto", id_qcm, id_etudiant) != 2) {
        printf("Nom de fichier invalide : %s\n", nom);
        fclose(fichier);
        return 0;
    }

    // Lire données
    fseek(fichier, 0, SEEK_END);
    long taille = ftell(fichier);
    if (taille < OFFSET_REPONSES + 2 * MAX_REPONSES) {
        printf("Fichier trop court : %s\n", filepath);
        fclose(fichier);
        return 0;
    }
    fseek(fichier, OFFSET_REPONSES, SEEK_SET);
    uint8_t buffer[2 * MAX_REPONSES];
    fread(buffer, sizeof(uint8_t), 2 * MAX_REPONSES, fichier);
    fclose(fichier);

    // Calcul note + export
    int note = 0;
    fprintf(csv, "%s,%s", id_etudiant, id_qcm);
    for (int i = 0; i < MAX_REPONSES; i++) {
        char corr = buffer[2 * i];
        char etud = buffer[2 * i + 1];
        if (corr == etud) note++;
        fprintf(csv, ",%c", etud);  // On ne met que les réponses de l'étudiant
    }
    fprintf(csv, ",%d\n", note);
    return note;
}

// Transforme tous les fichiers .gto du dossier en un CSV
void export_CSV(const char *nom_dossier) {
    DIR *dir;
    struct dirent *entry;
    char chemin[512];
    char nom_csv[256];

    snprintf(nom_csv, sizeof(nom_csv), "%s.csv", nom_dossier);
    FILE *csv = fopen(nom_csv, "w");
    if (!csv) {
        perror("Impossible de créer le fichier CSV");
        return;
    }

    // Écriture en-tête
    fprintf(csv, "ID_Etudiant,ID_QCM");
    for (int i = 1; i <= MAX_REPONSES; i++)
        fprintf(csv, ",Q%d", i);
    fprintf(csv, ",Note\n");

    // Parcours des fichiers
    int total = 0, somme_notes = 0;
    dir = opendir(nom_dossier);
    if (!dir) {
        perror("Erreur ouverture dossier");
        fclose(csv);
        return;
    }

    while ((entry = readdir(dir)) != NULL) {
        if (strstr(entry->d_name, ".gto")) {
            snprintf(chemin, sizeof(chemin), "%s/%s", nom_dossier, entry->d_name);
            int note = traiteur_gto(chemin, csv);
            if (note >= 0) {
                total++;
                somme_notes += note;
            }
        }
    }
    closedir(dir);

    // Moyenne
    if (total > 0) {
        float moyenne = (float)somme_notes / total;
        fprintf(csv, "\nMoyenne,,");
        for (int i = 0; i < MAX_REPONSES; i++) fprintf(csv, ",");
        fprintf(csv, "%.2f\n", moyenne);
    }

    fclose(csv);
    printf("Export terminé : %s\n", nom_csv);
}

// Test d'utilisation
int main(void) {
    export_CSV("DS1_de_mathematiques");
    return 0;
}
