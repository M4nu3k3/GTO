#ifndef __SPI_H__
#define __SPI_H__

#ifdef __cplusplus
extern "C" {
#endif

#include "stm32g4xx_hal.h"

extern SPI_HandleTypeDef hspi1;

void MX_SPI1_Init(void);
HAL_StatusTypeDef SPI_Transmit(uint8_t *data, uint16_t size, uint32_t timeout);
HAL_StatusTypeDef SPI_Receive(uint8_t *data, uint16_t size, uint32_t timeout);
HAL_StatusTypeDef SPI_TransmitReceive(uint8_t *txData, uint8_t *rxData, uint16_t size, uint32_t timeout);

#ifdef __cplusplus
}
#endif

#endif /* __SPI_H__ */
