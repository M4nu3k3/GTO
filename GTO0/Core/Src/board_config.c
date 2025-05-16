#include "board_config.h"
#include "stm32g4xx_hal.h"

void Board_Periph_Init(void)
{
    // Activer horloges GPIO
    __HAL_RCC_GPIOA_CLK_ENABLE();
    __HAL_RCC_GPIOB_CLK_ENABLE();

    // Activer horloges des périphériques
    __HAL_RCC_SPI1_CLK_ENABLE();
    __HAL_RCC_USART2_CLK_ENABLE();
    __HAL_RCC_TIM2_CLK_ENABLE();
}

void Board_GPIO_Init(void)
{
    GPIO_InitTypeDef GPIO_InitStruct = {0};

    // SPI1 GPIO Configuration : SCK et MOSI
    GPIO_InitStruct.Pin = SPI1_SCK_PIN | SPI1_MOSI_PIN;
    GPIO_InitStruct.Mode = GPIO_MODE_AF_PP;
    GPIO_InitStruct.Pull = GPIO_NOPULL;
    GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_VERY_HIGH;
    GPIO_InitStruct.Alternate = GPIO_AF5_SPI1;
    HAL_GPIO_Init(SPI1_SCK_PORT, &GPIO_InitStruct);

    // OLED CS pin en GPIO Output
    GPIO_InitStruct.Pin = OLED_CS_PIN;
    GPIO_InitStruct.Mode = GPIO_MODE_OUTPUT_PP;
    GPIO_InitStruct.Pull = GPIO_NOPULL;
    HAL_GPIO_Init(OLED_CS_PORT, &GPIO_InitStruct);

    // USART2 GPIO Configuration
    GPIO_InitStruct.Pin = USART2_TX_PIN | USART2_RX_PIN;
    GPIO_InitStruct.Mode = GPIO_MODE_AF_PP;
    GPIO_InitStruct.Pull = GPIO_NOPULL;
    GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_LOW;
    GPIO_InitStruct.Alternate = GPIO_AF7_USART2;
    HAL_GPIO_Init(USART2_TX_PORT, &GPIO_InitStruct);

    // TIM2 GPIO Configuration
    GPIO_InitStruct.Pin = TIM2_CH1_PIN | TIM2_CH2_PIN;
    GPIO_InitStruct.Mode = GPIO_MODE_AF_PP;
    GPIO_InitStruct.Pull = GPIO_NOPULL;
    GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_LOW;
    GPIO_InitStruct.Alternate = GPIO_AF1_TIM2;
    HAL_GPIO_Init(TIM2_CH1_PORT, &GPIO_InitStruct);

    // GPIO Outputs Configuration (DC, Reset, LEDs…)
    GPIO_InitStruct.Pin = GPIO_OUT_1_PIN | GPIO_OUT_2_PIN | GPIO_OUT_3_PIN;
    GPIO_InitStruct.Mode = GPIO_MODE_OUTPUT_PP;
    GPIO_InitStruct.Pull = GPIO_NOPULL;
    HAL_GPIO_Init(GPIO_OUT_1_PORT, &GPIO_InitStruct);

    GPIO_InitStruct.Pin = GPIO_OUT_4_PIN;
    HAL_GPIO_Init(GPIO_OUT_4_PORT, &GPIO_InitStruct);

    // (optionnel : si OLED_CS et GPIO_OUT_5_PIN sont la même, éviter double init)
    if (OLED_CS_PORT != GPIO_OUT_5_PORT || OLED_CS_PIN != GPIO_OUT_5_PIN) {
        GPIO_InitStruct.Pin = GPIO_OUT_5_PIN;
        HAL_GPIO_Init(GPIO_OUT_5_PORT, &GPIO_InitStruct);
    }
}
