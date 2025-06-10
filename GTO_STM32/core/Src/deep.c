/*
 * deep.c
 *
 *  Created on: Jun 9, 2025
 *      Author: dijon
 */

#include "deep.h"
#include "st7789v.h"

const char* pourcentAge[] = {
    "10",
    "20",
    "30",
    "40",
    "50",
    "60",
    "70",
    "80",
    "90",
	"100",
	"ERREUR"
};

const char* getPourcentage(Chargement c) {
    if (c >= DIX && c <= CENT)
        return pourcentAge[c];
    return pourcentAge[POURCENTAGEINCONNU];
}

void displayPourcentage(Chargement c, FontDef font, uint16_t x, uint16_t y, uint16_t color, uint16_t bgcolor)
{
    const char* texte = getPourcentage(c);
    ST7789_WriteString((char*)texte, font, x, y, color, bgcolor);
}
