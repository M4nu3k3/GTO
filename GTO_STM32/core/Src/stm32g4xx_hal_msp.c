/**
  ******************************************************************************
  * @file    stm32g4xx_hal_msp.c
  * @brief   Code source pour les fonctions MSP (MCU Support Package)
  *          Initialise les périphériques au niveau matériel (clocks, GPIO, NVIC).
  ******************************************************************************
  */

#include "stm32g4xx_hal.h"

/**
  * @brief Initialisation globale du MSP.
  */
void HAL_MspInit(void)
{
    __HAL_RCC_SYSCFG_CLK_ENABLE();
    __HAL_RCC_PWR_CLK_ENABLE();

    HAL_NVIC_SetPriorityGrouping(NVIC_PRIORITYGROUP_4);
}

/**
  * @brief SPI MSP Initialization
  *        Cette fonction configure le hardware ressources pour SPI1 :
  *           - Clocks
  *           - GPIO Configuration pour SPI SCK/MISO/MOSI
  *           - DMA configuration si activée
  *           - NVIC configuration
  * @param hspi: SPI handle pointer
  */
void HAL_SPI_MspInit(SPI_HandleTypeDef* hspi)
{
    GPIO_InitTypeDef GPIO_InitStruct = {0};
    if (hspi->Instance == SPI1)
    {
        /* Enable peripheral clock */
        __HAL_RCC_SPI1_CLK_ENABLE();
        __HAL_RCC_GPIOA_CLK_ENABLE();

        /** SPI1 GPIO Configuration
        PA5 --> SPI1_SCK
        PA6 --> SPI1_MISO
        PA7 --> SPI1_MOSI
        */
        GPIO_InitStruct.Pin = GPIO_PIN_5 | GPIO_PIN_6 | GPIO_PIN_7;
        GPIO_InitStruct.Mode = GPIO_MODE_AF_PP;
        GPIO_InitStruct.Pull = GPIO_NOPULL;
        GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_VERY_HIGH;
        GPIO_InitStruct.Alternate = GPIO_AF5_SPI1;
        HAL_GPIO_Init(GPIOA, &GPIO_InitStruct);

#if USE_SPI_DMA
        /* SPI1 DMA Init */
        /* SPI1_TX Init */
        __HAL_RCC_DMA1_CLK_ENABLE();
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
        __HAL_LINKDMA(hspi, hdmatx, hdma_spi1_tx);

        /* SPI1_RX Init */
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
        __HAL_LINKDMA(hspi, hdmarx, hdma_spi1_rx);
#endif
    }
}

/**
  * @brief SPI MSP De-Initialization
  * @param hspi: SPI handle pointer
  */
void HAL_SPI_MspDeInit(SPI_HandleTypeDef* hspi)
{
    if (hspi->Instance == SPI1)
    {
        __HAL_RCC_SPI1_CLK_DISABLE();

        /* Deinitialize GPIO pins */
        HAL_GPIO_DeInit(GPIOA, GPIO_PIN_5 | GPIO_PIN_6 | GPIO_PIN_7);

#if USE_SPI_DMA
        HAL_DMA_DeInit(hspi->hdmatx);
        HAL_DMA_DeInit(hspi->hdmarx);
#endif
    }
}
