/* USER CODE BEGIN Header */
/**
  **************************************************************************************************
  * @file           : gto_reader.h
  * @brief          : Interface pour la lecture d’un fichier .gto depuis une carte SD via FATFS.
  *
  * Ce module permet de :
  *   - Lire un fichier .gto au format binaire
  *   - Extraire les identifiants de l'étudiant et du QCM
  *   - Comparer correction et réponses
  *   - Écrire une ligne CSV dans un fichier ouvert
  *
  * Offsets :
  *   - 0x08 : ID Étudiant (3 caractères)
  *   - 0x0B : ID QCM (3 caractères)
  *   - 0x1A : Données réponses (20 paires de [corr, réponse])
  *
  * Auteur : Matthieu
  **************************************************************************************************
  */
/* USER CODE END Header */

#ifndef INC_GTO_READER_H
#define INC_GTO_READER_H

//#include "ff.h"     // FATFS
#include "stdio.h"

#define MAX_REPONSES 20
#define OFFSET_ID_ETU 0x08
#define OFFSET_ID_QCM 0x0B
#define OFFSET_REPONSES 0x1A
#define CSV_SEPARATOR ";"  // Modifier pour "," ou "\t" selon vos besoins

#ifdef __cplusplus
extern "C" {
#endif

/**
 * @brief Traite un fichier .gto et écrit une ligne CSV dans un fichier texte.
 * @param file pointeur vers le fichier .gto ouvert en lecture (FATFS)
 * @param csv_file pointeur vers le fichier CSV ouvert en écriture (FATFS)
 * @retval note obtenue (0-20)
 */
// int traiter_gto_sd(FIL *file, FIL *csv_file);

#ifdef __cplusplus
}
#endif

#endif // INC_GTO_READER_H
