#ifndef __FONTS_H__
#define __FONTS_H__

#include <stdint.h>

// Structure de définition de police
typedef struct {
    const uint8_t* data;  // tableau bitmap de la police
    uint8_t width;        // largeur d’un caractère en pixels
    uint8_t height;       // hauteur d’un caractère en pixels
} FontDef;

// Exemple : police 5x7
extern FontDef Font_5x7;

// Fonctions d’affichage de texte (prototype)
void ST7789_WriteChar(char ch, FontDef font, uint16_t x, uint16_t y, uint16_t color, uint16_t bgcolor);
void ST7789_WriteString(char* str, FontDef font, uint16_t x, uint16_t y, uint16_t color, uint16_t bgcolor);

#endif // __FONTS_H__
