/* USER CODE BEGIN Header */
/**
  ******************************************************************************
  * @file           : led.h
  * @brief          : Gestion de la LED utilisateur
  *
  * Auteur : Matthieu
  ******************************************************************************
  */
/* USER CODE END Header */

#ifndef __LED_H
#define __LED_H

#ifdef __cplusplus
extern "C" {
#endif

#include "stm32g4xx_hal.h"


void MX_LED_GPIO_Init(void);  // Initialisation du GPIO de la LED
void allumer_led(void);       // Allume la LED
void eteindre_led(void);      // Éteint la LED

#ifdef __cplusplus
}
#endif

#endif /* __LED_H */
