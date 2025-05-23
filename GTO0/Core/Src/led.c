/* USER CODE BEGIN Header */
/**
  ******************************************************************************
  * @file           : led.c
  * @brief          : Allumer et etiendre une led (dur non?)
  *
  * Auteur : Matthieu
  ******************************************************************************
  */
/* USER CODE END Header */

#include "Led.h"

void allumer_led(void) {
    HAL_GPIO_WritePin(GPIOB, GPIO_PIN_0, GPIO_PIN_SET);
}

void eteindre_led(void) {
    HAL_GPIO_WritePin(GPIOB, GPIO_PIN_0, GPIO_PIN_RESET);
}


