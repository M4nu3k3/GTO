/* USER CODE BEGIN Header */
/**
  ******************************************************************************
  * @file           : led.h
  * @brief          : Header for led.c file.
  *                   Pour allumer et eteindre une led (on s'est cassé le crane la dessus)
  ******************************************************************************
  */
/* USER CODE END Header */

#ifndef __LED_H
#define __LED_H

#include "main.h"  // Nécessaire pour les définitions GPIO

void allumer_led(void);
void eteindre_led(void);

#endif

