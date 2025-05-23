/* USER CODE BEGIN Header */
/**
  ******************************************************************************
  * @file           : main.c
  * @brief          : Main program body (SD card test with FATFS)
  ******************************************************************************
  */
/* USER CODE END Header */

#include "main.h"
// #include "FATFS_SD.h"
#include "string.h"
#include "board_config.h"

/* Private variables */
// FATFS fs;
// FIL fil;
// FRESULT fresult;
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
  MX_GPIO_Init();
  MX_SPI1_Init();              // SPI1 pour carte SD
  MX_FATFS_Init();             // FATFS

//  // Monter le système de fichiers
//  fresult = f_mount(&fs, "", 1);
//  if (fresult != FR_OK) {
//    Error_Handler();  // Erreur si carte non présente
//  }
//
//  // Créer / ouvrir un fichier
//  fresult = f_open(&fil, "log.txt", FA_CREATE_ALWAYS | FA_WRITE);
//  if (fresult == FR_OK) {
//    sprintf(buffer, "Hello from STM32G431!\r\n");
//    f_write(&fil, buffer, strlen(buffer), NULL);
//    f_close(&fil);
//  } else {
//    Error_Handler();  // Erreur ouverture fichier
//  }

  /* Boucle principale */
  while (1)
  {
	  allumer_led();
	  HAL_Delay(500);
	  eteindre_led();
	  HAL_Delay(500);
  }
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
