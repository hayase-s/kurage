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
	HAL_GPIO_WritePin(GPIOA, GPIO_PIN_4, onOff);
}
void lcdCS(uint8_t onOff) {
	HAL_GPIO_WritePin(GPIOA, GPIO_PIN_6, onOff);
}

//Input

void sensorFrontLED(uint8_t highlow) {
	HAL_GPIO_WritePin(GPIOB, GPIO_PIN_4, highlow);
}

void sensorSideLED(uint8_t highlow) {
	HAL_GPIO_WritePin(GPIOB, GPIO_PIN_5, highlow);
}
