/* USER CODE BEGIN Header */
/**
  **************************************************************************************************
  * @file           : export_dossier_sd.h
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

#ifndef INC_EXPORT_DOSSIER_SD_H
#define INC_EXPORT_DOSSIER_SD_H

// #include "ff.h"           // FatFS
#include "gto_reader.h"   // traitement d’un fichier .gto

#ifdef __cplusplus
extern "C" {
#endif

/**
 * @brief Exporte tous les fichiers .gto d’un dossier SD dans un fichier CSV sur la carte SD.
 * @param nom_dossier nom du dossier à parcourir (ex: "Mathematiques")
 */
void export_dossier_sd(const char *nom_dossier);

#ifdef __cplusplus
}
#endif

#endif // INC_EXPORT_DOSSIER_SD_H
