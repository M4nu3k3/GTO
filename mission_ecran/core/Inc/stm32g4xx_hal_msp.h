/**
  ******************************************************************************
  * @file    stm32g4xx_hal_msp.h
  * @brief   Header pour les fonctions MSP (MCU Support Package)
  *          Ce fichier déclare les fonctions d'initialisation bas-niveau du matériel
  *          nécessaires aux périphériques utilisés dans ce projet (horloges, GPIO, NVIC...).
  *
  ******************************************************************************
  */

#ifndef __STM32G4xx_HAL_MSP_H
#define __STM32G4xx_HAL_MSP_H

#ifdef __cplusplus
extern "C" {
#endif

/* Includes ------------------------------------------------------------------*/
#include "stm32g4xx_hal.h"  // Inclusion de la HAL STM32G4

/* Exported functions prototypes ---------------------------------------------*/

/**
  * @brief Initialisation générale du système (horloge NVIC, etc.).
  */
void HAL_MspInit(void);

/* ---------- ADC ---------- */
void HAL_ADC_MspInit(ADC_HandleTypeDef* hadc);
void HAL_ADC_MspDeInit(ADC_HandleTypeDef* hadc);

/* ---------- DAC ---------- */
void HAL_DAC_MspInit(DAC_HandleTypeDef* hdac);
void HAL_DAC_MspDeInit(DAC_HandleTypeDef* hdac);

/* ---------- I2C ---------- */
void HAL_I2C_MspInit(I2C_HandleTypeDef* hi2c);
void HAL_I2C_MspDeInit(I2C_HandleTypeDef* hi2c);

/* ---------- SPI ---------- */
void HAL_SPI_MspInit(SPI_HandleTypeDef* hspi);
void HAL_SPI_MspDeInit(SPI_HandleTypeDef* hspi);

/* ---------- UART ---------- */
void HAL_UART_MspInit(UART_HandleTypeDef* huart);
void HAL_UART_MspDeInit(UART_HandleTypeDef* huart);

/* ---------- RNG ---------- */
void HAL_RNG_MspInit(RNG_HandleTypeDef* hrng);
void HAL_RNG_MspDeInit(RNG_HandleTypeDef* hrng);

/* ---------- RTC ---------- */
void HAL_RTC_MspInit(RTC_HandleTypeDef* hrtc);
void HAL_RTC_MspDeInit(RTC_HandleTypeDef* hrtc);

/* ---------- TIM (Timer Base) ---------- */
void HAL_TIM_Base_MspInit(TIM_HandleTypeDef* htim_base);
void HAL_TIM_Base_MspDeInit(TIM_HandleTypeDef* htim_base);

/* ---------- Autres modules à ajouter si activés ---------- */
/* Exemples :
void HAL_EXTI_MspInit(void);
void HAL_DMA_MspInit(DMA_HandleTypeDef* hdma);
*/

#ifdef __cplusplus
}
#endif

#endif /* __STM32G4xx_HAL_MSP_H */
