/**
  ******************************************************************************
  * @file    spi.c
  * @brief   SPI1 driver pour STM32G431KB.
  ******************************************************************************
  */

#include "spi.h"
#include "config.h"

SPI_HandleTypeDef hspi1;

/**
  * @brief Initialise SPI1 (hors DMA).
  */
void MX_SPI1_Init(void)
{
    hspi1.Instance = SPI1;
    hspi1.Init.Mode = SPI_MODE_MASTER;
    hspi1.Init.Direction = SPI_DIRECTION_2LINES;
    hspi1.Init.DataSize = SPI_DATASIZE_8BIT;
    hspi1.Init.CLKPolarity = SPI_POLARITY_LOW;
    hspi1.Init.CLKPhase = SPI_PHASE_1EDGE;
    hspi1.Init.NSS = SPI_NSS_SOFT;
    hspi1.Init.BaudRatePrescaler = SPI_BAUDRATEPRESCALER_16;
    hspi1.Init.FirstBit = SPI_FIRSTBIT_MSB;
    hspi1.Init.TIMode = SPI_TIMODE_DISABLE;
    hspi1.Init.CRCCalculation = SPI_CRCCALCULATION_DISABLE;
    hspi1.Init.CRCPolynomial = 7;

    if (HAL_SPI_Init(&hspi1) != HAL_OK)
    {
        Error_Handler();
    }
}

HAL_StatusTypeDef SPI_Transmit(uint8_t *data, uint16_t size, uint32_t timeout)
{
    // Active CS (mettre à 0)
    HAL_GPIO_WritePin(GPIOA, ST7789_CS_PIN, GPIO_PIN_RESET);

    HAL_StatusTypeDef status = HAL_SPI_Transmit(&hspi1, data, size, timeout);

    // Désactive CS (remettre à 1)
    HAL_GPIO_WritePin(GPIOA, ST7789_CS_PIN, GPIO_PIN_SET);

    return status;
}

HAL_StatusTypeDef SPI_Receive(uint8_t *data, uint16_t size, uint32_t timeout)
{
    return HAL_SPI_Receive(&hspi1, data, size, timeout);
}

HAL_StatusTypeDef SPI_TransmitReceive(uint8_t *txData, uint8_t *rxData, uint16_t size, uint32_t timeout)
{
    return HAL_SPI_TransmitReceive(&hspi1, txData, rxData, size, timeout);
}
