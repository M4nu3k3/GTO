
#include "main.h"
#include "st7789v.h"
#include "stm32g4_gpio.h"  // pour BSP_GPIO_pin_config()
#include "fonts.h"

void SystemClock_Config(void);
void MX_SPI1_Init(void);
void MX_ST7789_GPIO_Init(void);


int main(void)
{   HAL_Init();
    SystemClock_Config();

    MX_ST7789_GPIO_Init();

	HAL_GPIO_WritePin(GPIOB, GPIO_PIN_8, GPIO_PIN_RESET); // LED éteinte
	HAL_Delay(100);
	HAL_GPIO_WritePin(GPIOB, GPIO_PIN_8, GPIO_PIN_SET);   // LED allumée
	HAL_Delay(100);
	HAL_GPIO_WritePin(GPIOB, GPIO_PIN_8, GPIO_PIN_RESET); // LED éteinte
	HAL_Delay(100);

    MX_SPI1_Init();

    // Initialisation de l'écran
    ST7789_Init();

    // Allume le rétroéclairage (si câblé)
    HAL_GPIO_WritePin(ST7789_BL_PORT, ST7789_BL_PIN, GPIO_PIN_SET);

    // Change la couleur de fond (ex : rouge)
//  ST7789_FillColor(ST7789_YELLOW);
    uint16_t colors[] = {
        ST7789_BLACK,
        ST7789_CYAN,
        ST7789_YELLOW,
        ST7789_MAGENTA,
        ST7789_GREEN,
        ST7789_RED,
        ST7789_BLUE,
        ST7789_WHITE
    };

    uint8_t num_colors = sizeof(colors) / sizeof(colors[0]);

    ST7789_SetRotation(ST7789_ROTATION_LANDSCAPE_INVERT);
    ST7789_FillColor(ST7789_BLUE);
    HAL_Delay(1000);
    ST7789_WriteString("Ca fonctionne!", Font_5x7, 20, 10, ST7789_WHITE, ST7789_BLACK);
    ST7789_FillColor(ST7789_MAGENTA);

    while (1)
    {
        for (uint8_t i = 0; i < num_colors; i++)
        {
           // ST7789_FillColor(colors[i]); // Affiche une couleur
            HAL_GPIO_TogglePin(GPIOB, GPIO_PIN_8); // Blink LED en même temps
            HAL_Delay(1000); // Délai d'une seconde
        }
    }
}
