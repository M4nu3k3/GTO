/*
 * notesMath.c
 *
 *  Created on: Jun 6, 2025
 *      Author: Matthieu
 */

#include "notesMath.h"
#include "st7789v.h"

Notes notes[] = {
    {"ANTOINE_B", 17},
    {"BASTIEN", 11},
    {"EMMANUEL", 10},
    {"MATTHIEU", 13},
    {"JORDAN_D", 17},
    {"ELEVE_UNKNOWN", 0}
};

#define NB_ELEVESNOTES (sizeof(notes)/sizeof(Notes))

// Optionnel : si tu veux garder une fonction qui retourne juste le nom
const char* getNomAvecNote(uint8_t index)
{
    if (index < NB_ELEVESNOTES)
        return notes[index].nom;
    return notes[NB_ELEVESNOTES - 1].nom; // ELEVE_UNKNOWN
}

uint8_t getNbEleveNote(void) {
    return NB_ELEVESNOTES;
}

void displayNote(uint8_t index, FontDef font, uint16_t x, uint16_t y, uint16_t color, uint16_t bgcolor)
{
    if (index >= NB_ELEVESNOTES) return;

    char buffer[32];
    sprintf(buffer, "%-12s %2d", notes[index].nom, notes[index].note);
    ST7789_WriteString(buffer, font, x, y, color, bgcolor);
}
