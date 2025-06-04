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
// Ajouter ici les autres headers générés utilisés dans ton projet

/* Exported types ------------------------------------------------------------*/

/* Exported constants --------------------------------------------------------*/

/* Exported macro ------------------------------------------------------------*/

/* Exported functions prototypes ---------------------------------------------*/

/**
  * @brief Fonction d'initialisation du système.
  */
void Error_Handler(void);

/* USER CODE BEGIN EFP */
// Tu peux ajouter ici tes fonctions exportées personnalisées
/* USER CODE END EFP */

/* Private defines -----------------------------------------------------------*/
// Définition des noms de broches GPIO utilisées, par exemple :
#define LED1_Pin         GPIO_PIN_5
#define LED1_GPIO_Port   GPIOA

#define SPI1_CS_Pin      GPIO_PIN_4
#define SPI1_CS_GPIO_Port GPIOA

// Ajoute ici les autres définitions utiles générées par STM32CubeMX

/* USER CODE BEGIN Private defines */
// Tes macros et définitions spécifiques ici
/* USER CODE END Private defines */

#ifdef __cplusplus
}
#endif

#endif /* __MAIN_H__ */
