/* USER CODE BEGIN Header */
/**
  *********************************************************************************************************************
  * @file           : gto_reader.h
  * @brief          : Déclarations des fonctions de lecture de fichiers .gto et génération d'un fichier CSV.
  *
  * Ce module permet de :
  *   - Lire des fichiers binaires au format .gto
  *   - Extraire les identifiants et réponses aux questions
  *   - Générer un fichier CSV à partir d'un dossier contenant ces fichiers
  *
  * Auteur : Matthieu
  *********************************************************************************************************************
  */
/* USER CODE END Header */

//#include "gto_reader.h"
//#include "FATFS_SD.h"  // FATFS
//
//int traiter_gto_sd(FIL *file, FIL *csv_file) {
//    UINT bytes_read;
//    char id_etud[4] = {0};
//    char id_qcm[4] = {0};
//    BYTE buffer[2 * MAX_REPONSES];
//
//    f_lseek(file, OFFSET_ID_ETU);
//    f_read(file, id_etud, 3, &bytes_read);
//    f_read(file, id_qcm, 3, &bytes_read);
//
//    f_lseek(file, OFFSET_REPONSES);
//    f_read(file, buffer, 2 * MAX_REPONSES, &bytes_read);
//
//    int note = 0;
//    f_printf(csv_file, "%s%s%s", id_etud, CSV_SEPARATOR, id_qcm);
//    for (int i = 0; i < MAX_REPONSES; i++) {
//        char corr = buffer[2 * i];
//        char etud = buffer[2 * i + 1];
//        if (corr == etud) note++;
//        f_printf(csv_file, "%s%c", CSV_SEPARATOR, etud);
//    }
//    f_printf(csv_file, "%s%d\n", CSV_SEPARATOR, note);
//    return note;
//}
//
