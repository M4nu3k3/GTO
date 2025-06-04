#include "config.h"
#include "spi.h"  // pour hspi1

void MX_ST7789_GPIO_Init(void)
{
    GPIO_InitTypeDef GPIO_InitStruct = {0};

    __HAL_RCC_GPIOA_CLK_ENABLE();

    GPIO_InitStruct.Pin = ST7789_RST_PIN | ST7789_DC_PIN | ST7789_BL_PIN | ST7789_CS_PIN;
    GPIO_InitStruct.Mode = GPIO_MODE_OUTPUT_PP;
    GPIO_InitStruct.Pull = GPIO_NOPULL;
    GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_LOW;

    HAL_GPIO_Init(GPIOA, &GPIO_InitStruct);
}

__weak void Error_Handler(void)
{
    while (1)
    {
        HAL_GPIO_TogglePin(LED_GREEN_GPIO, LED_GREEN_PIN);
        HAL_Delay(200);
    }
}
