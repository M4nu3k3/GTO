/*
 * bouton.h
 *
 *  Created on: Jun 5, 2025
 *      Author: dijon
 */

#ifndef INC_BOUTON_H_
#define INC_BOUTON_H_

#include "stm32g4xx_hal.h"  // ou adapter selon ta série STM32

// Initialisation du bouton (PB7)
void MX_Button_Init(void);

// Lecture de l'état du bouton (renvoie 1 si appuyé, 0 sinon)
uint8_t Button_READ(void);

#endif /* INC_BOUTON_H_ */
