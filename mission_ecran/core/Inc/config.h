/**
 ******************************************************************************
 * @file    config.h
 * @brief   Configuration principale du projet STM32G431KB + écran ST7789V.
 ******************************************************************************
 */

#ifndef CONFIG_H_
#define CONFIG_H_

#include "stm32g4xx_hal.h"
#include "stm32g4_uart.h"

/* ==================== LED ==================== */
#define LED_GREEN_PIN   GPIO_PIN_8
#define LED_GREEN_GPIO  GPIOB

/* ==================== UART Configuration ==================== */
#define UART1_ON_PA10_PA9    // PA9 = TX, PA10 = RX
#define UART2_ON_PA3_PA2     // PA2 = TX, PA3 = RX

/* ==================== SPI Configuration ==================== */
#define USE_SPI             1
#define USE_SPI_DMA         1 // Active DMA pour SPI (utile pour l'écran)
#define ST7789_SPI_HANDLE   hspi1
#define ST7789_CS_PORT      GPIOA
#define ST7789_CS_PIN       GPIO_PIN_4

/* ==================== ST7789 Configuration ==================== */
#define USE_ST7789          1

#define ST7789_DC_PORT      GPIOA
#define ST7789_DC_PIN       GPIO_PIN_1

#define ST7789_RST_PORT     GPIOA
#define ST7789_RST_PIN      GPIO_PIN_0

#define ST7789_BL_PORT      GPIOA
#define ST7789_BL_PIN       GPIO_PIN_2

#define ST7789_WIDTH        240
#define ST7789_HEIGHT       320

/* ==================== Autres périphériques (désactivés ici) ==================== */
#define USE_ADC             0
#define USE_DAC             0
#define USE_I2C             0
#define USE_RTC             0
#define USE_BSP_EXTIT       0
#define USE_BSP_TIMER       0

/* ==================== Timeout / Sécurité ==================== */
#define I2C_TIMEOUT         5 // ms

void MX_ST7789_GPIO_Init(void);


#endif /* CONFIG_H_ */
