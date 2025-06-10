/*
 * notesMath.h
 *
 *  Created on: Jun 6, 2025
 *      Author: Matthieu
 */

#ifndef NOTES_MATH_H
#define NOTES_MATH_H

#include <stdint.h>
#include "fonts.h"

typedef struct {
    char nom[20];
    uint8_t note;
} Notes;

extern Notes notes[];
#define NB_ELEVESNOTES 5

void displayNote(uint8_t index, FontDef font, uint16_t x, uint16_t y, uint16_t color, uint16_t bgcolor);
const char* getNomAvecNote(uint8_t index);
uint8_t getNbEleveNote();

#endif
