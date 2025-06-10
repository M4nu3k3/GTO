/**
  ******************************************************************************
  * @file    main.h
  * @author  [Ton Nom]
  * @brief   Header principal du projet.
  ******************************************************************************
  * @attention
  *
  * Ce fichier contient les déclarations des fonctions, définitions de broches
  * et inclusions communes nécessaires dans tout le projet STM32.
  *
  ******************************************************************************
  */

#ifndef __MAIN_H__
#define __MAIN_H__

#ifdef __cplusplus
extern "C" {
#endif

/* Includes ------------------------------------------------------------------*/
#include "stm32g4xx_hal.h"   // HAL de la série STM32G4
#include "dma.h"
#include "spi.h"
#include "stm32g4_gpio.h"
#include "stm32g4_uart.h"
#include "stm32g4_timer.h"

/**
  * @brief Fonction d'initialisation du système.
  */
void Error_Handler(void);

// Définition des noms de broches GPIO utilisées, par exemple :
#define LED1_Pin         GPIO_PIN_5
#define LED1_GPIO_Port   GPIOA

#define SPI1_CS_Pin      GPIO_PIN_4
#define SPI1_CS_GPIO_Port GPIOA


#ifdef __cplusplus
}
#endif

#endif /* __MAIN_H__ */
