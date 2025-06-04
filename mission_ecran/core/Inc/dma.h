/**
  ******************************************************************************
  * @file    dma.h
  * @brief   En-tête pour la configuration du contrôleur DMA.
  ******************************************************************************
  */

#ifndef __DMA_H__
#define __DMA_H__

#ifdef __cplusplus
extern "C" {
#endif

#include "stm32g4xx_hal.h"

/* Externs pour les canaux DMA utilisés par SPI1 */
extern DMA_HandleTypeDef hdma_spi1_tx;
extern DMA_HandleTypeDef hdma_spi1_rx;

/* Fonction d'initialisation du DMA */
void MX_DMA_Init(void);

#ifdef __cplusplus
}
#endif

#endif /* __DMA_H__ */
