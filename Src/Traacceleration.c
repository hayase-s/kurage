/*
 * Traacceleration.c
 *
 *  Created on: 2018/09/08
 *      Author: kanako
 */

#include "tim.h"
#include "motor.h"
#include "myassign.h"
#include "wall.h"

float a;
float v_start;
float v_max;
float v_end;
float x;
float x_acc;
float x_dec;
int Tra;

void Traacc(void) {
	HAL_GPIO_WritePin(GPIOB, GPIO_PIN_6, HIGH);
	HAL_GPIO_WritePin(GPIOB, GPIO_PIN_7, SET);
	HAL_Delay(3);
	HAL_GPIO_WritePin(GPIOB, GPIO_PIN_7, RESET);

	HAL_TIM_PWM_Stop(&htim1, TIM_CHANNEL_1);
	HAL_TIM_PWM_Stop(&htim2, TIM_CHANNEL_3);

	a = 1000;
	v_start = 200.0;
	v_max = 1000.0;
	v_end = 200;
	x = 180*2;
	g_targetTrans.dis = 0;
	g_targetTrans.acc = a;

	x_acc = (v_max * v_max - v_start * v_start) / (2 * a);
	x_dec = (v_max * v_max - v_end * v_end) / (2 * a);

	if ((x_acc + x_dec) > x) {
		x_acc = x / 2 + (v_end * v_end - v_start * v_start) / (4 * a);
		x_dec = x / 2 + (v_start * v_start - v_end * v_end) / (4 * a);
	}

	HAL_TIM_PWM_Start_IT(&htim1, TIM_CHANNEL_1);
	HAL_TIM_PWM_Start_IT(&htim2, TIM_CHANNEL_3);

	g_targetTrans.vel_r = v_start;
	g_targetTrans.vel_l = v_start;

	Tra = 1;
	while (g_targetTrans.dis < x) {
		rightcalPWMCount(g_targetTrans.wvel_r);
		leftcalPWMCount(g_targetTrans.wvel_l);
		printf("%f\n\r",g_targetTrans.dis);
	}

	HAL_TIM_PWM_Stop(&htim1, TIM_CHANNEL_1);
	HAL_TIM_PWM_Stop(&htim2, TIM_CHANNEL_3);
	Tra = 0;
}

