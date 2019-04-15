/*
 * Traacceleration.c
 *
 *  Created on: 2018/09/08
 *      Author: kanako
 */

#include "tim.h"
#include "motor.h"
#include "myassign.h"

float a;
float v_start;
float v_max;
float v_end;
float x;
float x_acc;
float x_dec;
int s;
void Traacc(void) {

	HAL_GPIO_WritePin(GPIOB, GPIO_PIN_7, SET);
	HAL_Delay(3);
	HAL_GPIO_WritePin(GPIOB, GPIO_PIN_7, RESET);

	HAL_TIM_PWM_Stop(&htim1, TIM_CHANNEL_1);
	HAL_TIM_PWM_Stop(&htim2, TIM_CHANNEL_3);

	g_targetTrans.dis = 0;
	s = 1;
	a = 1000;
	v_start = 500.0;
	v_max = 1000.0;
	v_end = 500;
	x = 1500;
	x_acc = (v_max * v_max - v_start * v_start) / (2 * a);
	x_dec = (v_max * v_max - v_end * v_end) / (2 * a);
	printf("x_acc=%f  x_dec=%f\n\r",x_acc,x_dec);
	if ((x_acc + x_dec) > x) {
		x_acc = x / 2 + (v_end * v_end - v_start * v_start) / (4 * a);
		x_dec = x / 2 + (v_start * v_start - v_end * v_end) / (4 * a);
	}

	g_targetTrans.acc = a;
	g_targetTrans.vel = v_start;
	while (g_targetTrans.dis < x_acc) {
		HAL_TIM_PWM_Start_IT(&htim1, TIM_CHANNEL_1);
		HAL_TIM_PWM_Start_IT(&htim2, TIM_CHANNEL_3);
//		calPara(&g_targetTrans);
		calPWMCount(g_targetTrans.vel);
//		printf("%f \n\r", g_targetTrans.vel);
	}
	HAL_GPIO_WritePin(GPIOB, GPIO_PIN_3, HIGH);
	g_targetTrans.acc = 0;
	g_targetTrans.vel = v_max;
	while (g_targetTrans.dis < (x - x_dec)) {
//		calPara(&g_targetTrans);
		calPWMCount(g_targetTrans.vel);

//		printf("%f \n\r", g_targetTrans.vel);
	}
	g_targetTrans.acc = -a;
	g_targetTrans.vel = v_max;
	while (g_targetTrans.dis < x) {
//		calPara(&g_targetTrans);
		calPWMCount(g_targetTrans.vel);

//		printf("%f \n\r", g_targetTrans.vel);
	}
	HAL_TIM_PWM_Stop(&htim1, TIM_CHANNEL_1);
	HAL_TIM_PWM_Stop(&htim2, TIM_CHANNEL_3);
}

