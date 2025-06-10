/*
 * gto.c
 *
 *  Created on: Jun 10, 2025
 *      Author: dijon
 */
#include "gto.h"
#include "st7789v.h"

void afficher_ecran_gto(){
    for(int i = 0 ; i<40 ; i++){
    ST7789_WriteString(" ", Font_5x7, 155, 60 + 2.15*i, ST7789_BLACK, ST7789_RED);//T vertical
    ST7789_WriteString(" ", Font_5x7, 150, 60 + 2.15*i, ST7789_BLACK, ST7789_RED);
    ST7789_WriteString(" ", Font_5x7, 135 + i, 60, ST7789_BLACK, ST7789_RED);//T horizontal
    ST7789_WriteString(" ", Font_5x7, 130 + i, 60, ST7789_BLACK, ST7789_RED);
    ST7789_WriteString(" ", Font_5x7, 80, 60 + 2*i, ST7789_BLACK, ST7789_WHITE);//G vertical
    ST7789_WriteString(" ", Font_5x7, 75, 60 + 2*i, ST7789_BLACK, ST7789_WHITE);
    ST7789_WriteString(" ", Font_5x7, 80 + 0.75*i, 60, ST7789_BLACK, ST7789_WHITE);//G horizontal haut
    ST7789_WriteString(" ", Font_5x7, 75 + 0.75*i, 60, ST7789_BLACK, ST7789_WHITE);
    ST7789_WriteString(" ", Font_5x7, 80 + 0.75*i, 140, ST7789_BLACK, ST7789_WHITE);//G horizontal bas
    ST7789_WriteString(" ", Font_5x7, 75 + 0.75*i, 140, ST7789_BLACK, ST7789_WHITE);
    ST7789_WriteString(" ", Font_5x7, 105, 110 + 0.7*i, ST7789_BLACK, ST7789_WHITE);//G petit vertical
    ST7789_WriteString(" ", Font_5x7, 108, 110 + 0.7*i, ST7789_BLACK, ST7789_WHITE);
    ST7789_WriteString(" ", Font_5x7, 95 + 0.35*i, 105, ST7789_BLACK, ST7789_WHITE);//G mini horizontal
    ST7789_WriteString(" ", Font_5x7, 95 + 0.35*i, 105, ST7789_BLACK, ST7789_WHITE);
    ST7789_WriteString(" ", Font_5x7, 200, 60 + 2.1*i, ST7789_BLACK, ST7789_WHITE);//O vertical gauche
    ST7789_WriteString(" ", Font_5x7, 195, 60 + 2.1*i, ST7789_BLACK, ST7789_WHITE);
    ST7789_WriteString(" ", Font_5x7, 230, 60 + 2.1*i, ST7789_BLACK, ST7789_WHITE);//O vertical droite
    ST7789_WriteString(" ", Font_5x7, 235, 60 + 2.1*i, ST7789_BLACK, ST7789_WHITE);
    ST7789_WriteString(" ", Font_5x7, 195 + 0.75*i, 60, ST7789_BLACK, ST7789_WHITE);//O horizontal haut
    ST7789_WriteString(" ", Font_5x7, 200 + 0.75*i, 60, ST7789_BLACK, ST7789_WHITE);
    ST7789_WriteString(" ", Font_5x7, 200 + 0.75*i, 140, ST7789_BLACK, ST7789_WHITE);//O horizontal haut
    ST7789_WriteString(" ", Font_5x7, 195 + 0.75*i, 140, ST7789_BLACK, ST7789_WHITE);
    ST7789_WriteString("GRADING TEST OPERATOR", Font_5x7, 80, 180, ST7789_RED, ST7789_BLACK);
    }
}
