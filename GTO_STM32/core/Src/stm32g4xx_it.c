/**
  ******************************************************************************
  * @file    stm32g4xx_it.c
  * @brief   Interrupt Service Routines.
  ******************************************************************************
  * @attention
  *
  * Copyright (c) 2024 STMicroelectronics.
  * All rights reserved.
  *
  * This software is licensed under terms that can be found in the LICENSE file
  * in the root directory of this software component.
  * If no LICENSE file comes with this software, it is provided AS-IS.
  *
  ******************************************************************************
  */

#include "config.h"
#include "stm32g4xx_it.h"



extern DMA_HandleTypeDef hdma_spi1_tx;
extern DMA_HandleTypeDef hdma_spi1_rx;
extern SPI_HandleTypeDef hspi1;

void DMA1_Channel2_IRQHandler(void)
{
    HAL_DMA_IRQHandler(&hdma_spi1_tx);
}

void DMA1_Channel3_IRQHandler(void)
{
    HAL_DMA_IRQHandler(&hdma_spi1_rx);
}

void SPI1_IRQHandler(void)
{
    HAL_SPI_IRQHandler(&hspi1);
}

void NMI_Handler(void)
{

  while (1)
  {
  }
}

/**
  * @brief This function handles Hard fault interrupt.
  */
void HardFault_Handler(void)
{

  while (1)
  {
  }
}

/**
  * @brief This function handles Memory management fault.
  */
void MemManage_Handler(void)
{

  while (1)
  {
  }
}

/**
  * @brief This function handles Prefetch fault, memory access fault.
  */
void BusFault_Handler(void)
{

  while (1)
  {
  }
}

/**
  * @brief This function handles Undefined instruction or illegal state.
  */
void UsageFault_Handler(void)
{

  while (1)
  {
  }
}

/**
  * @brief This function handles System service call via SWI instruction.
  */
void SVC_Handler(void)
{


}

/**
  * @brief This function handles Debug monitor.
  */
void DebugMon_Handler(void)
{


}

/**
  * @brief This function handles Pendable request for system service.
  */
void PendSV_Handler(void)
{


}

/**
  * @brief This function handles System tick timer.
  */
/* Since the use of HAL_SYSTICK_IRQHandler() has been discontinued by ST, implementation
 * of Systick_Handler is transfered to stm32g4_systick.c in order to manage callback functions
void SysTick_Handler(void)
{

  HAL_IncTick();

}*/

/******************************************************************************/
/* STM32G4xx Peripheral Interrupt Handlers                                    */
/* Add here the Interrupt Handlers for the used peripherals.                  */
/* For the available peripheral interrupt handler names,                      */
/* please refer to the startup file (startup_stm32g4xx.s).                    */
/******************************************************************************/

