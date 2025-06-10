/*
 * matieres.c
 */

#include "matieres.h"
#include "st7789v.h"

const char* matieresStr[] = {
    "DS-GTO-1",
    "AUTOMATIQUE",
    "MATHEMATIQUES",
    "INFORMATIQUE",
    "ELECTRONIQUE",
    "PHYSIQUE",
    "VOLTAIRE",
    "TOEIC",
    "INCONNUE"
};

const char* getMatiereName(Matiere m) {
    if (m >= DEEP && m <= TOEIC)
        return matieresStr[m];
    return matieresStr[MATIERE_UNKNOWN];
}

void displayMatiere(Matiere m, FontDef font, uint16_t x, uint16_t y, uint16_t color, uint16_t bgcolor)
{
    const char* text = getMatiereName(m);
    ST7789_WriteString((char*)text, font, x, y, color, bgcolor);
}
