/*
 * matieres.h
 */

#ifndef MATIERES_H
#define MATIERES_H

#include <stdint.h>
#include "fonts.h"

typedef enum {
    DEEP,
    AUTOMATIQUE,
    MATHEMATIQUES,
    INFORMATIQUE,
    ELECTRONIQUE,
    PHYSIQUE,
    VOLTAIRE,
    TOEIC,
    MATIERE_UNKNOWN
} Matiere;

const char* getMatiereName(Matiere m);
void displayMatiere(Matiere m, FontDef font, uint16_t x, uint16_t y, uint16_t color, uint16_t bgcolor);

#define NB_MATIERES MATIERE_UNKNOWN

#endif // MATIERES_H
