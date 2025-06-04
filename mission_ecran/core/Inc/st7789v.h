#ifndef __ST7789V_H__
#define __ST7789V_H__

#include "stm32g4xx_hal.h"
#include <stdint.h>
#include "fonts.h"
#include "config.h"

// ==== FUNCTION PROTOTYPES ==== //
void ST7789_Init(void);
void ST7789_Reset(void);
void ST7789_SetAddressWindow(uint16_t x0, uint16_t y0, uint16_t x1, uint16_t y1);
void ST7789_DrawPixel(uint16_t x, uint16_t y, uint16_t color);
void ST7789_FillColor(uint16_t color);
void ST7789_SetRotation(uint8_t rotation);

// ==== Rotation constants ====
#define ST7789_ROTATION_PORTRAIT          0
#define ST7789_ROTATION_LANDSCAPE         1
#define ST7789_ROTATION_PORTRAIT_INVERT   2
#define ST7789_ROTATION_LANDSCAPE_INVERT  3

// ==== Color defines ====
#define ST7789_BLACK    0xFFFF
#define ST7789_CYAN     0xF800
#define ST7789_YELLOW   0x001F
#define ST7789_MAGENTA  0x07E0
#define ST7789_GREEN    0xF81F
#define ST7789_RED      0x07FF
#define ST7789_BLUE     0xFFE0
#define ST7789_WHITE    0x0000

#define ST7789_BLACK    0xFFFF
#define ST7789_CYAN     0xF800
#define ST7789_YELLOW   0x001F
#define ST7789_MAGENTA  0x07E0
#define ST7789_GREEN    0xF81F
#define ST7789_RED 		0x07FF
#define ST7789_BLUE  	0xFFE0
#define ST7789_WHITE   	0x0000


#endif // __ST7789V_H__
