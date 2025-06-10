/*
 * eleves.h
 *
 *  Created on: Jun 6, 2025
 *      Author: dijon
 */

#ifndef ELEVES_H
#define ELEVES_H

#include <stdint.h>
#include "fonts.h"

// Déclaration de tous les élèves
typedef enum {
    AXEL_A,
	FLORIAN,
	TIMEO,
	MATHIEU,
	HAMED,
	MARC,
	BASTIEN,
	AXEL_B,
	EMMANUEL,
	HATIM,
	MATTHIEU,
	BENJAMIN,
	MAXIME,
	JULES,
	MATIS,
	HUGO,
	ANTOINE_TC,
	ANTOINE_V,
	ELISE,
	RETOUR,
	ELEVE_UNKNOWN

} Eleve;

// Renvoie le nom de l'élève (chaîne de caractères)
const char* getEleveName(Eleve e);

// Affiche la liste des élèves à l'écran
void displayEleve(Eleve e, FontDef font, uint16_t x, uint16_t y, uint16_t color, uint16_t bgcolor);

#define NB_ELEVES ELEVE_UNKNOWN

#endif // ELEVES_H
