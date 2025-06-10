/*
 * bouton.c
 *
 *  Created on: Jun 5, 2025
 *      Author: dijon
 */

#include "bouton.h"


uint8_t Button_READ(void)
{
    // Si le bouton est connecté à GND quand appuyé, on teste un niveau bas
    return (HAL_GPIO_ReadPin(GPIOB, GPIO_PIN_7) == GPIO_PIN_RESET) ? 1 : 0;
}

