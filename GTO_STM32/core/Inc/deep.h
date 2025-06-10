/*
 * deep.h
 *
 *  Created on: Jun 9, 2025
 *      Author: dijon
 */

#ifndef INC_DEEP_H_
#define INC_DEEP_H_

#include <stdint.h>
#include "fonts.h"

typedef enum {
    DIX,
    VINGT,
    TRENTE,
    QUARANTE,
    CINQUANTE,
    SOIXANTE,
    SOIXANTEDIX,
    QUATREVINGT,
    QUATREVINGTDIX,
	CENT,
	POURCENTAGEINCONNU
} Chargement;

const char* getPourcentage(Chargement c);
void displayPourcentage(Chargement c, FontDef font, uint16_t x, uint16_t y, uint16_t color, uint16_t bgcolor);

#define NB_MATIERES POURCENTAGEINCONNU

#endif /* INC_DEEP_H_ */
