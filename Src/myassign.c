/*
 * myassign.c
 *
 *  Created on: 2018/07/05
 *      Author: shun
 */

#include "stm32f3xx_hal.h"
#include "gpio.h"

#include "myassign.h"

//Output
void lcdRS(uint8_t onOff) {
	HAL_GPIO_WritePin(GPIOF, GPIO_PIN_1, onOff);
}
void lcdCS(uint8_t onOff) {
	HAL_GPIO_WritePin(GPIOA, GPIO_PIN_6, onOff);
}

//Input

