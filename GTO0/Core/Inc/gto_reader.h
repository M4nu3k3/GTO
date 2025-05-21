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

#ifndef GTO_READER_H
#define GTO_READER_H

#include <stdio.h>

// Configuration
#define MAX_REPONSES 20
#define OFFSET_ID_ETU 0x08
#define OFFSET_ID_QCM 0x0B
#define OFFSET_REPONSES 0x1A
#define CSV_SEPARATOR ";"  // Modifier pour "," ou "\t" selon votre besoin

#ifdef __cplusplus
extern "C" {
#endif

/**
 * @brief  Lit un fichier .gto et écrit une ligne dans un fichier CSV.
 * @param  filepath : chemin du fichier .gto
 * @param  csv : pointeur vers un fichier CSV ouvert en écriture (mode texte)
 * @retval la note (0 à MAX_REPONSES) ou -1 en cas d'erreur
 */
int traiteur_gto(const char *filepath, FILE *csv);

/**
 * @brief  Parcourt tous les fichiers .gto d’un dossier et génère un fichier CSV.
 * @param  nom_dossier : nom du dossier à analyser (ex. "DS1_Maths")
 *         => Le fichier CSV généré sera <nom_dossier>.csv
 */
void export_CSV(const char *nom_dossier);

#ifdef __cplusplus
}
#endif

#endif // GTO_READER_H
