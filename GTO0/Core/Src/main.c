/* USER CODE BEGIN Header */
/**
  ******************************************************************************
  * @file           : main.c
  * @brief          : Main program body (SD card test with FATFS)
  ******************************************************************************
  */
/* USER CODE END Header */

#include "main.h"
#include "FATFS_SD.h"
#include "string.h"

/* Private variables */
FATFS fs;
FIL fil;
FRESULT fresult;
char buffer[100];

/* Function prototypes */
void SystemClock_Config(void);

int main(void)
{
  /* MCU Configuration--------------------------------------------------------*/
  HAL_Init();                  // Init HAL
  SystemClock_Config();        // Horloge système

  Board_Periph_Init();         // Horloges GPIO & périphériques
  Board_GPIO_Init();           // Broches
  MX_SPI1_Init();              // SPI1 pour carte SD
  MX_FATFS_Init();             // FATFS

  // Monter le système de fichiers
  fresult = f_mount(&fs, "", 1);
  if (fresult != FR_OK) {
    Error_Handler();  // Erreur si carte non présente
  }

  // Créer / ouvrir un fichier
  fresult = f_open(&fil, "log.txt", FA_CREATE_ALWAYS | FA_WRITE);
  if (fresult == FR_OK) {
    sprintf(buffer, "Hello from STM32G431!\r\n");
    f_write(&fil, buffer, strlen(buffer), NULL);
    f_close(&fil);
  } else {
    Error_Handler();  // Erreur ouverture fichier
  }

  /* Boucle principale */
  while (1)
  {
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
    HAL_GPIO_TogglePin(GPIO_OUT_1_PORT, GPIO_OUT_1_PIN);
    HAL_Delay(100);
  }
}

#ifdef USE_FULL_ASSERT
void assert_failed(uint8_t *file, uint32_t line)
{
  // Debug print ici
}
#endif
