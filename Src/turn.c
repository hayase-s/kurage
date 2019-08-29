/*
 * turn.c
 *
 *  Created on: Apr 16, 2019
 *      Author: kanako
 */

#include "turn.h"
#include "tim.h"
#include "motor.h"
#include "myassign.h"
#include "wall.h"

float v_R;
float v_L;
float v;
float ome;
float r;
float th;
int tur;
extern volatile uint32_t g_timCount;

void turn(void) {
	HAL_GPIO_WritePin(GPIOB, GPIO_PIN_6, HIGH);
	HAL_GPIO_WritePin(GPIOB, GPIO_PIN_7, SET);
	HAL_Delay(3);
	HAL_GPIO_WritePin(GPIOB, GPIO_PIN_7, RESET);

	HAL_TIM_PWM_Stop(&htim1, TIM_CHANNEL_1);
	HAL_TIM_PWM_Stop(&htim2, TIM_CHANNEL_3);

	v = 0;
	ome = 20;
	r = 45;
	th = 1800;

	v_R = v + ome * r;
	v_L = v - ome * r;

	printf("R=%f L=%f\n\r", v_R, v_L);

	g_targetTrans.vel_r = v_R;
	g_targetTrans.vel_l = v_L;

	HAL_TIM_PWM_Start_IT(&htim1, TIM_CHANNEL_1);
	HAL_TIM_PWM_Start_IT(&htim2, TIM_CHANNEL_3);
	tur = 1;

	g_timCount = 0;
	while (g_timCount < th / ome) {
		rightcalPWMCount(g_targetTrans.wvel_r);
		leftcalPWMCount(g_targetTrans.wvel_l);
	}

	HAL_TIM_PWM_Stop(&htim1, TIM_CHANNEL_1);
	HAL_TIM_PWM_Stop(&htim2, TIM_CHANNEL_3);
	tur = 0;

}

