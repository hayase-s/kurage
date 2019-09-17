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

int d;
tarparameter g_targetTrans;


uint16_t rightcalPWMCount(float wvel_r) {
	uint16_t PWMCount;
	d = 52;
	if ((fabs(g_targetTrans.wvel_r) > 0.0)
			&& ((8000000 * 0.9 * (3.141592653 / 180) * (d / 2))
					/ fabs(g_targetTrans.wvel_r) < UINT16_MAX)) {
		PWMCount = (uint16_t) ((8000000 * 0.9 * (3.141592653 / 180) * (d / 2))
				/ fabs(g_targetTrans.wvel_r)) - 1;
	} else {
		PWMCount = UINT16_MAX - 1;
	}
	return PWMCount;
} //SOKUDO_MIGI

uint16_t leftcalPWMCount(float wvel_l) {
	uint16_t PWMCount;
	if ((fabs(g_targetTrans.wvel_l) > 0.0)
			&& ((8000000 * 0.9 * (3.141592653 / 180) * (d / 2))
					/ fabs(g_targetTrans.wvel_l) < UINT16_MAX)) {
		PWMCount = (uint16_t) ((8000000 * 0.9 * (3.141592653 / 180) * (d / 2))
				/ fabs(g_targetTrans.wvel_l)) - 1;
	} else {
		PWMCount = UINT16_MAX - 1;
	}
	return PWMCount;
} //SOKUDO_HIDARI

void rightCWCCW(float wvel_r) {
	if (g_targetTrans.wvel_r > 0.0) {
		HAL_GPIO_WritePin(GPIOA, GPIO_PIN_10, HIGH);
	} else {
		HAL_GPIO_WritePin(GPIOA, GPIO_PIN_10, LOW);
	}
} //MAEUSHIRO

void leftCWCCW(float wvel_l) {
	if (g_targetTrans.wvel_l > 0.0) {
		HAL_GPIO_WritePin(GPIOA, GPIO_PIN_11, LOW);
	} else {
		HAL_GPIO_WritePin(GPIOA, GPIO_PIN_11, HIGH);
	}
} //MAEUSHIRO

const float DT = 0.001;

void rightcalPara(tarparameter *para) {
	para->dis += para->vel_r * DT;
} //SEKIBUNKANSUU_MIGI

void leftcalPara(tarparameter *para) {
	para->dis += para->vel_l * DT;
} //SEKIBUNKANSUU_HIDARI

