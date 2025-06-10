#include "main.h"
#include "st7789v.h"
#include "stm32g4_gpio.h"
#include "fonts.h"
#include "matieres.h"
#include "led.h"
#include "bouton.h"
#include "notesMath.h"
#include "eleves.h"
#include "gto.h"

void SystemClock_Config(void);
void MX_SPI1_Init(void);
void MX_ST7789_GPIO_Init(void);

static uint16_t compteur = 0;
static const uint16_t HAUTEUR_ECRAN = 240;
static const uint8_t PADDING_HAUTEUR = 30;
#define NB_COLONNES 3
static const uint8_t PADDING_COLONNES[NB_COLONNES] = {10, 110, 220};

typedef void (*AfficheurEnum)(uint8_t, FontDef, uint16_t, uint16_t, uint16_t, uint16_t);

void afficher_elements(uint8_t nb_elements, uint8_t selection, AfficheurEnum afficher) {
    uint8_t colonne = 0, compteur_local = 0;
    for (uint8_t i = 0; i < nb_elements; i++) {
        uint8_t y = PADDING_HAUTEUR * (i - compteur_local);
        if (y >= HAUTEUR_ECRAN) {
            colonne++;
            compteur_local = i;
            y = 0;
        }
        if (colonne >= NB_COLONNES) break;
        uint8_t x = PADDING_COLONNES[colonne];
        uint16_t bg = (i == selection) ? ST7789_BLUE : ST7789_BLACK;
        afficher(i, Font_5x7, x, y, ST7789_WHITE, bg);
    }
    HAL_Delay(100);
}

void animation_chargement(void) {
    for (int i = 0; i < 10; i++) {
        ST7789_FillColor_Landscape(ST7789_BLACK);
        HAL_Delay(50);
    	for (int k = 0 ; k<19 ; k++){
    		ST7789_WriteString(" ", Font_5x7, 115 + (5 * k), 140, ST7789_BLACK, ST7789_WHITE);
    	}
        HAL_Delay(50);
        ST7789_WriteString("Loading", Font_5x7, 120, 105, ST7789_YELLOW, ST7789_BLACK);
        ST7789_WriteString("%", Font_5x7, 200, 105, ST7789_YELLOW, ST7789_BLACK);
        char pourcentage[5];
        sprintf(pourcentage, "%d", 10 * (i + 1));
        ST7789_WriteString(pourcentage, Font_5x7, 175, 105, ST7789_YELLOW, ST7789_BLACK);
        for (int j=0 ; j<i+1; j++){
        ST7789_WriteString(" ", Font_5x7, 115 + (10 * j), 140, ST7789_BLACK, ST7789_MAGENTA);
        }
        HAL_Delay(100);
    }
    ST7789_FillColor_Landscape(ST7789_BLACK);
    ST7789_WriteString("COMPLETED", Font_5x7, 120, 105, ST7789_YELLOW, ST7789_BLACK);
    ST7789_WriteString("(^_^)", Font_5x7, 135, 130, ST7789_YELLOW, ST7789_BLACK);
    HAL_Delay(1000);
}

void afficher_matieres(uint8_t selectionnee) {
    for (uint8_t i = 0; i < 8; i++) {
        uint16_t bg = (i == selectionnee) ? ST7789_RED : ST7789_BLACK;
        displayMatiere((Matiere)i, Font_5x7, 10, 35 * i, ST7789_WHITE, bg);
    }
}

bool attendre_appui_long(uint32_t duree_ms) {
    uint32_t start = HAL_GetTick();
    while (Button_READ() == 0) {
        if (HAL_GetTick() - start >= duree_ms) {
            while (Button_READ() == 0) HAL_Delay(10); // attendre relâchement
            return true;
        }
        HAL_Delay(10);
    }
    return false;
}

void traitement_appui_long(void) {
    HAL_Delay(1250);
    if (compteur == 0) {
        HAL_Delay(50);
        allumer_led();
        animation_chargement();
    }
    eteindre_led();
    HAL_Delay(50);
    ST7789_FillColor_Landscape(ST7789_BLACK);
    HAL_Delay(50);

    // Choix des éléments à afficher
    uint8_t nb_elements = (compteur == 0) ? NB_ELEVESNOTES : NB_ELEVES;
    AfficheurEnum afficher = (compteur == 0) ? displayNote : displayEleve;
    uint8_t selection = 0;

    // Première affichage
    afficher_elements(nb_elements, selection, afficher);
    ST7789_WriteString(getMatiereName(compteur), Font_5x7, 150, 230, ST7789_YELLOW, ST7789_BLACK);

    // Boucle interactive
    while (1) {
        if (Button_READ() == 0) {
            uint32_t pressStart = HAL_GetTick();
            HAL_Delay(30); // Anti-rebond

            if (Button_READ() == 0) {
            	allumer_led();
                // Appui long : retour au menu matière
                if (attendre_appui_long(1000)) {
                    while (Button_READ() == 0) HAL_Delay(10); // attendre relâchement
                    ST7789_FillColor_Landscape(ST7789_BLACK);
                    afficher_matieres(compteur);
                    return;
                }

                // Appui court : changer de sélection
                selection = (selection + 1) % nb_elements;
                afficher_elements(nb_elements, selection, afficher);
                eteindre_led();

                // (optionnel) afficher le nom de l'élève/étudiant sélectionné
                // ST7789_WriteString(getEleveName(selection), Font_5x7, 10, 230, ST7789_YELLOW, ST7789_BLACK);
            }
        }
        HAL_Delay(10);
    }

}



int main(void) {
    HAL_Init();
    SystemClock_Config();
    MX_ST7789_GPIO_Init();
    MX_LED_GPIO_Init();
    MX_Button_Init();
    MX_SPI1_Init();
    ST7789_Init();
    HAL_GPIO_WritePin(ST7789_BL_PORT, ST7789_BL_PIN, GPIO_PIN_SET);
    ST7789_SetRotation(3);

    allumer_led();

    ST7789_FillColor_Landscape(ST7789_BLACK);
    eteindre_led();

    afficher_ecran_gto();
    HAL_Delay(2500);
    ST7789_FillColor_Landscape(ST7789_BLACK);
    afficher_matieres(compteur);
    HAL_Delay(1000);

    while (1) {
        if (Button_READ() == 0) {
            HAL_Delay(30);
            if (Button_READ() == 0) {
                if (attendre_appui_long(1000)) {
                    traitement_appui_long();
                    continue;
                }
                allumer_led();
                ST7789_WriteString("Bouton appuye", Font_5x7, 150, 300, ST7789_YELLOW, ST7789_BLACK);
                displayMatiere((Matiere)compteur, Font_5x7, 10, 35 * compteur, ST7789_WHITE, ST7789_BLACK);

                compteur = (compteur + 1) % 8;

                displayMatiere((Matiere)compteur, Font_5x7, 10, 35 * compteur, ST7789_WHITE, ST7789_RED);
                HAL_Delay(50);
                ST7789_WriteString("             ", Font_5x7, 150, 300, ST7789_YELLOW, ST7789_BLACK);
                eteindre_led();
            }
        }
    }
}
