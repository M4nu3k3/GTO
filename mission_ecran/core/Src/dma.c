/**
  ******************************************************************************
  * @file    dma.c
  * @brief   Fichier source pour la configuration du contrôleur DMA.
  ******************************************************************************
  */

#include "dma.h"
#include "spi.h"  // pour le lien DMA avec hspi1

/* Définition des canaux DMA pour SPI1 */
DMA_HandleTypeDef hdma_spi1_tx;
DMA_HandleTypeDef hdma_spi1_rx;

/* Fonction d'initialisation du DMA */
void MX_DMA_Init(void)
{
    __HAL_RCC_DMA1_CLK_ENABLE();

    /* SPI1_TX DMA Init */
    hdma_spi1_tx.Instance = DMA1_Channel2;
    hdma_spi1_tx.Init.Request = DMA_REQUEST_SPI1_TX;
    hdma_spi1_tx.Init.Direction = DMA_MEMORY_TO_PERIPH;
    hdma_spi1_tx.Init.PeriphInc = DMA_PINC_DISABLE;
    hdma_spi1_tx.Init.MemInc = DMA_MINC_ENABLE;
    hdma_spi1_tx.Init.PeriphDataAlignment = DMA_PDATAALIGN_BYTE;
    hdma_spi1_tx.Init.MemDataAlignment = DMA_MDATAALIGN_BYTE;
    hdma_spi1_tx.Init.Mode = DMA_NORMAL;
    hdma_spi1_tx.Init.Priority = DMA_PRIORITY_LOW;
    HAL_DMA_Init(&hdma_spi1_tx);
    __HAL_LINKDMA(&hspi1, hdmatx, hdma_spi1_tx);

    /* SPI1_RX DMA Init */
    hdma_spi1_rx.Instance = DMA1_Channel3;
    hdma_spi1_rx.Init.Request = DMA_REQUEST_SPI1_RX;
    hdma_spi1_rx.Init.Direction = DMA_PERIPH_TO_MEMORY;
    hdma_spi1_rx.Init.PeriphInc = DMA_PINC_DISABLE;
    hdma_spi1_rx.Init.MemInc = DMA_MINC_ENABLE;
    hdma_spi1_rx.Init.PeriphDataAlignment = DMA_PDATAALIGN_BYTE;
    hdma_spi1_rx.Init.MemDataAlignment = DMA_MDATAALIGN_BYTE;
    hdma_spi1_rx.Init.Mode = DMA_NORMAL;
    hdma_spi1_rx.Init.Priority = DMA_PRIORITY_LOW;
    HAL_DMA_Init(&hdma_spi1_rx);
    __HAL_LINKDMA(&hspi1, hdmarx, hdma_spi1_rx);

    /* Interrupts */
    HAL_NVIC_SetPriority(DMA1_Channel2_IRQn, 1, 0);
    HAL_NVIC_EnableIRQ(DMA1_Channel2_IRQn);

    HAL_NVIC_SetPriority(DMA1_Channel3_IRQn, 1, 0);
    HAL_NVIC_EnableIRQ(DMA1_Channel3_IRQn);
}
