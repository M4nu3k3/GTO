/* USER CODE BEGIN Header */
/**
  ******************************************************************************
  * @file           : main.c
  * @brief          : Main program body
  ******************************************************************************
  */
/* USER CODE END Header */

#include "main.h"

void SystemClock_Config(void);

int main(void)
{
  /* MCU Configuration--------------------------------------------------------*/
  HAL_Init();                  // Init de HAL
  SystemClock_Config();        // Configuration de l'horloge système

  Board_Periph_Init();         // Activation des horloges GPIO et périphériques
  Board_GPIO_Init();           // Initialisation des broches

  /* Boucle principale */
  while (1)
  {
    // Exemple : toggle GPIO_OUT_1 toutes les secondes
    HAL_GPIO_TogglePin(GPIO_OUT_1_PORT, GPIO_OUT_1_PIN);
    HAL_Delay(1000);
  }
}

/**
  * @brief System Clock Configuration
  */
void SystemClock_Config(void)
{
  RCC_OscInitTypeDef RCC_OscInitStruct = {0};
  RCC_ClkInitTypeDef RCC_ClkInitStruct = {0};

  HAL_PWREx_ControlVoltageScaling(PWR_REGULATOR_VOLTAGE_SCALE1);

  RCC_OscInitStruct.OscillatorType = RCC_OSCILLATORTYPE_HSI;
  RCC_OscInitStruct.HSIState = RCC_HSI_ON;
  RCC_OscInitStruct.HSICalibrationValue = RCC_HSICALIBRATION_DEFAULT;
  RCC_OscInitStruct.PLL.PLLState = RCC_PLL_NONE;

  if (HAL_RCC_OscConfig(&RCC_OscInitStruct) != HAL_OK)
    Error_Handler();

  RCC_ClkInitStruct.ClockType = RCC_CLOCKTYPE_HCLK | RCC_CLOCKTYPE_SYSCLK |
                                RCC_CLOCKTYPE_PCLK1 | RCC_CLOCKTYPE_PCLK2;

  RCC_ClkInitStruct.SYSCLKSource = RCC_SYSCLKSOURCE_HSI;
  RCC_ClkInitStruct.AHBCLKDivider = RCC_SYSCLK_DIV1;
  RCC_ClkInitStruct.APB1CLKDivider = RCC_HCLK_DIV1;
  RCC_ClkInitStruct.APB2CLKDivider = RCC_HCLK_DIV1;

  if (HAL_RCC_ClockConfig(&RCC_ClkInitStruct, FLASH_LATENCY_0) != HAL_OK)
    Error_Handler();
}

/**
  * @brief  Gestion d’erreur simple.
  */
void Error_Handler(void)
{
  __disable_irq();
  while (1) {
    // Blink rapide sur GPIO_OUT_1 pour signaler erreur
    HAL_GPIO_TogglePin(GPIO_OUT_1_PORT, GPIO_OUT_1_PIN);
    HAL_Delay(100);
  }
}

#ifdef USE_FULL_ASSERT
void assert_failed(uint8_t *file, uint32_t line)
{
  // Debug print ici si tu veux
}
#endif
