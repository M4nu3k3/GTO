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
#define OFFSET_ID_ETU 0x08
#define OFFSET_ID_QCM 0x0B
#define OFFSET_REPONSES 0x1A
#define CSV_SEPARATOR ";"  // Changer ici pour "," ou "\t"

int traiteur_gto(const char *filepath, FILE *csv) {
    FILE *fichier = fopen(filepath, "rb");
    if (!fichier) {
        perror("Erreur ouverture fichier");
        return 0;
    }

    char id_etud[4] = {0};
    char id_qcm[4] = {0};
    fseek(fichier, OFFSET_ID_ETU, SEEK_SET);
    fread(id_etud, sizeof(char), 3, fichier);
    fread(id_qcm, sizeof(char), 3, fichier);

    fseek(fichier, OFFSET_REPONSES, SEEK_SET);
    uint8_t buffer[2 * MAX_REPONSES];
    fread(buffer, sizeof(uint8_t), 2 * MAX_REPONSES, fichier);
    fclose(fichier);

    int note = 0;
    fprintf(csv, "%s%s%s", id_etud, CSV_SEPARATOR, id_qcm);
    for (int i = 0; i < MAX_REPONSES; i++) {
        char corr = buffer[2 * i];
        char etud = buffer[2 * i + 1];
        if (corr == etud) note++;
        fprintf(csv, "%s%c", CSV_SEPARATOR, etud);
    }
    fprintf(csv, "%s%d\n", CSV_SEPARATOR, note);
    return note;
}

void export_CSV(const char *nom_dossier) {
    DIR *dir;
    struct dirent *entry;
    char chemin[512], nom_csv[256];

    snprintf(nom_csv, sizeof(nom_csv), "%s.csv", nom_dossier);
    FILE *csv = fopen(nom_csv, "w");
    if (!csv) {
        perror("Impossible de créer le fichier CSV");
        return;
    }

    fprintf(csv, "ID_Etudiant%sID_QCM", CSV_SEPARATOR);
    for (int i = 1; i <= MAX_REPONSES; i++)
        fprintf(csv, "%sQ%d", CSV_SEPARATOR, i);
    fprintf(csv, "%sNote\n", CSV_SEPARATOR);

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

    if (total > 0) {
        float moyenne = (float)somme_notes / total;
        fprintf(csv, "\nMoyenne%s%s", CSV_SEPARATOR, CSV_SEPARATOR);
        for (int i = 0; i < MAX_REPONSES; i++)
            fprintf(csv, "%s", CSV_SEPARATOR);
        fprintf(csv, "%.2f\n", moyenne);
    }

    fclose(csv);
    printf("Export terminé : %s\n", nom_csv);
}

int main(void) {
    export_CSV("Mathematiques");
    return 0;
}
