/* USER CODE BEGIN Header */
/**
  **************************************************************************************************
  * @file           : export_dossier_sd.c
  * @brief          : Interface pour l’exportation de tous les fichiers .gto d’un dossier vers un CSV.
  *
  * Ce module utilise FatFS pour parcourir un dossier de la carte SD,
  * lit chaque fichier .gto, et produit un fichier CSV.
  *
  * Format final : [ID_Etudiant, ID_QCM, Q1...Q20, Note] + moyenne
  *
  * Auteur : Matthieu
  **************************************************************************************************
  */
/* USER CODE END Header */


/** A utiliser dans le main.c

#include "gto_reader.h"

void app_main(void) {
    MX_FATFS_Init();  // Si tu as généré via STM32CubeMX
    exporter_dossier_sd("Mathematiques");
}

**/

#include "export_dossier_sd.h"
// #include "ff.h"
#include "gto_reader.h"

//void export_dossier_sd(const char *nom_dossier) {
//    DIR dir;
//    FILINFO fno;
//    FIL file, csv_file;
//    char chemin[128];
//    char csv_path[64];
//    int total = 0, somme = 0;
//
//    snprintf(csv_path, sizeof(csv_path), "%s.csv", nom_dossier);
//    f_open(&csv_file, csv_path, FA_WRITE | FA_CREATE_ALWAYS);
//    f_printf(&csv_file, "ID_Etudiant%sID_QCM", CSV_SEPARATOR);
//    for (int i = 1; i <= MAX_REPONSES; i++)
//        f_printf(&csv_file, "%sQ%d", CSV_SEPARATOR, i);
//    f_printf(&csv_file, "%sNote\n", CSV_SEPARATOR);
//
//    if (f_opendir(&dir, nom_dossier) == FR_OK) {
//        while (f_readdir(&dir, &fno) == FR_OK && fno.fname[0]) {
//            if (strstr(fno.fname, ".gto")) {
//                snprintf(chemin, sizeof(chemin), "%s/%s", nom_dossier, fno.fname);
//                if (f_open(&file, chemin, FA_READ) == FR_OK) {
//                    int note = traiter_gto_sd(&file, &csv_file);
//                    total++;
//                    somme += note;
//                    f_close(&file);
//                }
//            }
//        }
//        f_closedir(&dir);
//    }
//
//    if (total > 0) {
//        float moyenne = (float)somme / total;
//        f_printf(&csv_file, "\nMoyenne%s%s", CSV_SEPARATOR, CSV_SEPARATOR);
//        for (int i = 0; i < MAX_REPONSES; i++)
//            f_printf(&csv_file, "%s", CSV_SEPARATOR);
//        f_printf(&csv_file, "%.2f\n", moyenne);
//    }
//
//    f_close(&csv_file);
//}
