#include "st7789v.h"
#include "main.h"
#include "fonts.h"

extern SPI_HandleTypeDef ST7789_SPI_HANDLE;

#define ST7789_MADCTL 0x36
uint16_t ST7789_Width = ST7789_WIDTH;
uint16_t ST7789_Height = ST7789_HEIGHT;

void ST7789_SendCommand(uint8_t cmd) {
    HAL_GPIO_WritePin(ST7789_CS_PORT, ST7789_CS_PIN, GPIO_PIN_RESET);
    HAL_GPIO_WritePin(ST7789_DC_PORT, ST7789_DC_PIN, GPIO_PIN_RESET);
    HAL_SPI_Transmit(&ST7789_SPI_HANDLE, &cmd, 1, HAL_MAX_DELAY);
    HAL_GPIO_WritePin(ST7789_CS_PORT, ST7789_CS_PIN, GPIO_PIN_SET);
}

void ST7789_SendData(uint8_t *data, uint16_t size) {
    HAL_GPIO_WritePin(ST7789_CS_PORT, ST7789_CS_PIN, GPIO_PIN_RESET);
    HAL_GPIO_WritePin(ST7789_DC_PORT, ST7789_DC_PIN, GPIO_PIN_SET);
    HAL_SPI_Transmit(&ST7789_SPI_HANDLE, data, size, HAL_MAX_DELAY);
    HAL_GPIO_WritePin(ST7789_CS_PORT, ST7789_CS_PIN, GPIO_PIN_SET);
}

void ST7789_Reset(void) {
    HAL_GPIO_WritePin(ST7789_RST_PORT, ST7789_RST_PIN, GPIO_PIN_RESET);
    HAL_Delay(50);
    HAL_GPIO_WritePin(ST7789_RST_PORT, ST7789_RST_PIN, GPIO_PIN_SET);
    HAL_Delay(50);
}

// Initialise le cran

void ST7789_Init(void) {
    ST7789_Reset();

    // Par défaut en portrait
    ST7789_SetRotation(ST7789_ROTATION_PORTRAIT);

    ST7789_SendCommand(0x3A); // COLMOD
    uint8_t colmod = 0x05;    // 16-bit color
    ST7789_SendData(&colmod, 1);

    ST7789_SendCommand(0x11); // Sleep out
    HAL_Delay(120);

    ST7789_SendCommand(0x29); // Display ON
}


void ST7789_SetAddressWindow(uint16_t x0, uint16_t y0, uint16_t x1, uint16_t y1) {
    uint8_t data[4];

    ST7789_SendCommand(0x2A);
    data[0] = x0 >> 8; data[1] = x0 & 0xFF;
    data[2] = x1 >> 8; data[3] = x1 & 0xFF;
    ST7789_SendData(data, 4);

    ST7789_SendCommand(0x2B);
    data[0] = y0 >> 8; data[1] = y0 & 0xFF;
    data[2] = y1 >> 8; data[3] = y1 & 0xFF;
    ST7789_SendData(data, 4);

    ST7789_SendCommand(0x2C); // Memory write
}

// Affichage ecran

void ST7789_DrawPixel(uint16_t x, uint16_t y, uint16_t color) {
    if (x >= ST7789_WIDTH || y >= ST7789_HEIGHT) return;
    ST7789_SetAddressWindow(x, y, x, y);
    uint8_t data[] = { color >> 8, color & 0xFF };
    HAL_GPIO_WritePin(ST7789_DC_PORT, ST7789_DC_PIN, GPIO_PIN_SET);
    HAL_GPIO_WritePin(ST7789_CS_PORT, ST7789_CS_PIN, GPIO_PIN_RESET);
    HAL_SPI_Transmit(&ST7789_SPI_HANDLE, data, 2, HAL_MAX_DELAY);
    HAL_GPIO_WritePin(ST7789_CS_PORT, ST7789_CS_PIN, GPIO_PIN_SET);
}

void ST7789_FillColor(uint16_t color) {
    ST7789_SetAddressWindow(0, 0, ST7789_WIDTH - 1, ST7789_HEIGHT - 1);
    uint8_t data[] = { color >> 8, color & 0xFF };
    HAL_GPIO_WritePin(ST7789_DC_PORT, ST7789_DC_PIN, GPIO_PIN_SET);
    HAL_GPIO_WritePin(ST7789_CS_PORT, ST7789_CS_PIN, GPIO_PIN_RESET);

    for (uint32_t i = 0; i < ST7789_WIDTH * ST7789_HEIGHT; i++) {
        HAL_SPI_Transmit(&ST7789_SPI_HANDLE, data, 2, HAL_MAX_DELAY);
    }

    HAL_GPIO_WritePin(ST7789_CS_PORT, ST7789_CS_PIN, GPIO_PIN_SET);
}

void ST7789_FillColor_Landscape(uint16_t color) {
    ST7789_SetAddressWindow(0, 0, ST7789_HEIGHT - 1, ST7789_WIDTH - 1);
    uint8_t data[] = { color >> 8, color & 0xFF };
    HAL_GPIO_WritePin(ST7789_DC_PORT, ST7789_DC_PIN, GPIO_PIN_SET);
    HAL_GPIO_WritePin(ST7789_CS_PORT, ST7789_CS_PIN, GPIO_PIN_RESET);

    for (uint32_t i = 0; i < ST7789_WIDTH * ST7789_HEIGHT; i++) {
        HAL_SPI_Transmit(&ST7789_SPI_HANDLE, data, 2, HAL_MAX_DELAY);
    }

    HAL_GPIO_WritePin(ST7789_CS_PORT, ST7789_CS_PIN, GPIO_PIN_SET);
}

// Rotation ecran

void ST7789_SetRotation(uint8_t rotation)
{
    uint8_t madctl = 0;

    switch(rotation) {
        case ST7789_ROTATION_PORTRAIT:         // 0°
            madctl = 0x00; // MY=0 MX=0 MV=0
            ST7789_Width = 240;
            ST7789_Height = 320;
            break;
        case ST7789_ROTATION_LANDSCAPE:        // 90°
            madctl = 0x60; // MV=1 MX=1 MY=0
            ST7789_Width = 320;
            ST7789_Height = 240;
            break;
        case ST7789_ROTATION_PORTRAIT_INVERT:  // 180°
            madctl = 0xC0; // MY=1 MX=1 MV=0
            ST7789_Width = 240;
            ST7789_Height = 320;
            break;
        case ST7789_ROTATION_LANDSCAPE_INVERT: // 270°
            madctl = 0xA0; // MV=1 MX=0 MY=1
            ST7789_Width = 320;
            ST7789_Height = 240;
            break;
        default:
            madctl = 0x00;
            ST7789_Width = 240;
            ST7789_Height = 320;
            break;
    }

    ST7789_SendCommand(ST7789_MADCTL);
    ST7789_SendData(&madctl, 1);
}
