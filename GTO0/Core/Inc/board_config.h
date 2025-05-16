#ifndef BOARD_CONFIG_H_
#define BOARD_CONFIG_H_

#include "stm32g4xx_hal.h"

// SPI1
#define SPI1_SCK_PIN        GPIO_PIN_5
#define SPI1_SCK_PORT       GPIOA
#define SPI1_MOSI_PIN       GPIO_PIN_7
#define SPI1_MOSI_PORT      GPIOA

// OLED Chip Select (CS)
#define OLED_CS_PIN         GPIO_PIN_6
#define OLED_CS_PORT        GPIOB

// USART2
#define USART2_TX_PIN       GPIO_PIN_2
#define USART2_TX_PORT      GPIOA
#define USART2_RX_PIN       GPIO_PIN_3
#define USART2_RX_PORT      GPIOA

// TIM2
#define TIM2_CH1_PIN        GPIO_PIN_0
#define TIM2_CH1_PORT       GPIOA
#define TIM2_CH2_PIN        GPIO_PIN_1
#define TIM2_CH2_PORT       GPIOA

// GPIO Outputs (pour d'autres fonctions : DC, Reset… ou LEDs)
#define GPIO_OUT_1_PIN      GPIO_PIN_12
#define GPIO_OUT_1_PORT     GPIOA
#define GPIO_OUT_2_PIN      GPIO_PIN_13
#define GPIO_OUT_2_PORT     GPIOA
#define GPIO_OUT_3_PIN      GPIO_PIN_8
#define GPIO_OUT_3_PORT     GPIOA
#define GPIO_OUT_4_PIN      GPIO_PIN_3
#define GPIO_OUT_4_PORT     GPIOB
#define GPIO_OUT_5_PIN      GPIO_PIN_6  // Note : utilisé ici pour OLED_CS, à adapter si besoin

void Board_Periph_Init(void);
void Board_GPIO_Init(void);

#endif /* BOARD_CONFIG_H_ */
