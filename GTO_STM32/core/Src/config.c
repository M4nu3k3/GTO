#include "config.h"
#include "spi.h"  // pour hspi1

void MX_ST7789_GPIO_Init(void)
{
    GPIO_InitTypeDef GPIO_InitStruct = {0};

    __HAL_RCC_GPIOA_CLK_ENABLE();
    __HAL_RCC_GPIOB_CLK_ENABLE();

    GPIO_InitStruct.Pin = ST7789_RST_PIN | ST7789_DC_PIN | ST7789_BL_PIN | ST7789_CS_PIN;
    GPIO_InitStruct.Mode = GPIO_MODE_OUTPUT_PP;
    GPIO_InitStruct.Pull = GPIO_PULLUP;
    GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_LOW;

    HAL_GPIO_Init(GPIOA, &GPIO_InitStruct);
}

void MX_LED_GPIO_Init(void)
{
    GPIO_InitTypeDef GPIO_InitStruct = {0};

    // Activation de l'horloge pour le port B
    __HAL_RCC_GPIOB_CLK_ENABLE();

    // Configuration de PB0 en sortie push-pull (pour la LED)
    GPIO_InitStruct.Pin = GPIO_PIN_0;
    GPIO_InitStruct.Mode = GPIO_MODE_OUTPUT_PP;
    GPIO_InitStruct.Pull = GPIO_NOPULL;
    GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_LOW;

    HAL_GPIO_Init(GPIOB, &GPIO_InitStruct);
}

void MX_Button_Init(void)
{
    __HAL_RCC_GPIOB_CLK_ENABLE();  // Active l'horloge du port B

    GPIO_InitTypeDef GPIO_InitStruct = {0};
    GPIO_InitStruct.Pin = GPIO_PIN_7;
    GPIO_InitStruct.Mode = GPIO_MODE_INPUT;
    GPIO_InitStruct.Pull = GPIO_PULLDOWN; // Pull-up interne (GND quand appuyé)
    HAL_GPIO_Init(GPIOB, &GPIO_InitStruct);
}

__weak void Error_Handler(void)
{
    while (1)
    {

        HAL_Delay(200);
    }
}
