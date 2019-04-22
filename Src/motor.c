/*
 * motor.c
 *
 *  Created on: 2018/09/09
 *      Author: kanako
 */
#include <stdint.h>
#include <math.h>
#include "myassign.h"
#include "gpio.h"
#include "motor.h"

tarparameter g_targetTrans;

uint16_t rightcalPWMCount(float vel_r) {
	uint16_t PWMCount;
	if ((fabs(g_targetTrans.vel_r) > 0.0)
			&& (6534512.719 / fabs(g_targetTrans.vel_r) < UINT16_MAX)) {
		PWMCount = (uint16_t) (6534512.719 / fabs(g_targetTrans.vel_r) ) - 1;
	} else {
		PWMCount = UINT16_MAX - 1;
	}
	return PWMCount;
}//SOKUDO_MIGI

uint16_t leftcalPWMCount(float vel_l) {
	uint16_t PWMCount;
	if ((fabs(g_targetTrans.vel_l) > 0.0)
			&& (6534512.719 / fabs(g_targetTrans.vel_l) < UINT16_MAX)) {
		PWMCount = (uint16_t) (6534512.719 / fabs(g_targetTrans.vel_l) ) - 1;
	} else {
		PWMCount = UINT16_MAX - 1;
	}
	return PWMCount;
}//SOKUDO_HIDARI

void rightCWCCW(float vel_r) {
	if (g_targetTrans.vel_r > 0.0) {
		HAL_GPIO_WritePin(GPIOA, GPIO_PIN_10, HIGH);
	} else {
		HAL_GPIO_WritePin(GPIOA, GPIO_PIN_10, LOW);
	}
}//MAEUSHIRO

void leftCWCCW(float vel_l) {
	if (g_targetTrans.vel_l > 0.0) {
		HAL_GPIO_WritePin(GPIOA, GPIO_PIN_11, LOW);
	} else {
		HAL_GPIO_WritePin(GPIOA, GPIO_PIN_11, HIGH);
	}
}//MAEUSHIRO

const float DT = 0.001;

void rightcalPara(tarparameter *para) {
	para->dis += para->vel_r * DT + para->acc * DT * DT / 2.0;
}//SEKIBUNKANSUU_MIGI

void leftcalPara(tarparameter *para) {
	para->dis += para->vel_l * DT + para->acc * DT * DT / 2.0;
}//SEKIBUNKANSUU_HIDARI

void motor_enable(){
	HAL_GPIO_WritePin(GPIOB,GPIO_PIN_6,HIGH);
	HAL_GPIO_WritePin(GPIOB, GPIO_PIN_7, SET);
	HAL_Delay(3);
	HAL_GPIO_WritePin(GPIOB, GPIO_PIN_7, RESET);
}
