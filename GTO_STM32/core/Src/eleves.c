/*
 * eleves.c
 *
 *  Created on: Jun 6, 2025
 *      Author: dijon
 */

#include "eleves.h"
#include "st7789v.h"

static const char* eleveNames[] = {
    "AXEL_A",
    "FLORIAN",
    "TIMEO",
    "MATHIEU",
    "HAMED",
    "MARC",
    "BASTIEN",
    "AXEL_B",
    "EMMANUEL",
    "HATIM",
    "MATTHIEU",
	"BENJAMIN",
	"MAXIME",
	"JULES",
	"MATIS",
	"HUGO",
	"ANTOINE_TC",
    "ANTOINE_V",
	"ELISE",
	"<===="
	"INCONNU"
};

const char* getEleveName(Eleve e)
{
    if (e >= AXEL_A && e <= RETOUR) {
        return eleveNames[e];
    }
    return eleveNames[ELEVE_UNKNOWN];
}

void displayEleve(Eleve e, FontDef font, uint16_t x, uint16_t y, uint16_t color, uint16_t bgcolor)
{
	const char* text = getEleveName(e);
	ST7789_WriteString((char*)text, font, x, y, color, bgcolor);
}
