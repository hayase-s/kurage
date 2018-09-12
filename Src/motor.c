///*
// * motor.c
// *
// *  Created on: 2018/09/09
// *      Author: kanako
// */
//#include <stdint.h>
//#include <math.h>
//#include "gpio.h"
//#include "myassign.h"
//#include "motor.h"
//
//
//
//tarparameter g_targetTrans;
//
//uint16_t calPWMCount(float vel) {
//	uint16_t PWMCount;
//	if ((fabs(g_targetTrans.vel) > 0.0)
//			&& (94247.77961 / fabs(g_targetTrans.vel) * 52 < UINT16_MAX)) {
//		PWMCount = (uint16_t) (94247.77961 / fabs(g_targetTrans.vel) * 52) - 1;
//	} else {
//		PWMCount = UINT16_MAX - 1;
//	}
//	return PWMCount;
//}
//
//void rightCWCCW(float vel) {
//	if (fabs(g_targetTrans.vel) > 0.0) {
//		HAL_GPIO_WritePin(GPIOA, GPIO_PIN_10, LOW);
//	} else {
//		HAL_GPIO_WritePin(GPIOA, GPIO_PIN_10, HIGH);
//	}
//}//MAEUSHIRO
//
//void leftCWCCW(float vel) {
//	if (fabs(g_targetTrans.vel) > 0.0) {
//		HAL_GPIO_WritePin(GPIOA, GPIO_PIN_11, LOW);
//	} else {
//		HAL_GPIO_WritePin(GPIOA, GPIO_PIN_11, HIGH);
//	}
//}//MAEUSHIRO
//
//const float DT = 0.001;
//
//void calPara(tarparameter *para) {
//	para->dis += para->vel * DT + para->acc * DT * DT / 2.0;
//	para->vel += para->acc * DT;
//}//SEKIBUNKANSUU
