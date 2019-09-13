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
#include <math.h>

float v_R;
float v_L;
float v;
float ome;
float r;
float g_th;
float th_rad;
int tur;
volatile uint32_t g_turcount;

void turn(void) {
	HAL_GPIO_WritePin(GPIOB, GPIO_PIN_6, HIGH);
	HAL_GPIO_WritePin(GPIOB, GPIO_PIN_7, SET);
	HAL_Delay(3);
	HAL_GPIO_WritePin(GPIOB, GPIO_PIN_7, RESET);

	HAL_TIM_Base_Stop_IT(&htim1);
	HAL_TIM_PWM_Stop_IT(&htim1, TIM_CHANNEL_1);
	HAL_TIM_Base_Stop_IT(&htim2);
	HAL_TIM_PWM_Stop_IT(&htim2, TIM_CHANNEL_3);

	v = 0;
	ome = (270.00 / 180.00) * 3.14159265;
	r = 49.0;
	th_rad = (fabsf(g_th) / 180.00) * 3.14159265;

	if (g_th > 0) {
		v_R = ome * r;
		v_L = -ome * r;
	} else {
		v_R = -ome * r;
		v_L = ome * r;
	}

	g_targetTrans.wvel_r = v_R;
	g_targetTrans.wvel_l = v_L;

	HAL_TIM_Base_Start_IT(&htim1);
	HAL_TIM_PWM_Start_IT(&htim1, TIM_CHANNEL_1);
	HAL_TIM_Base_Start_IT(&htim2);
	HAL_TIM_PWM_Start_IT(&htim2, TIM_CHANNEL_3);

	g_turcount = 0;
	tur = 1;
	while (g_turcount < (th_rad / ome) * 1000) {
	}
	HAL_TIM_Base_Stop_IT(&htim1);
	HAL_TIM_PWM_Stop_IT(&htim1, TIM_CHANNEL_1);
	HAL_TIM_Base_Stop_IT(&htim2);
	HAL_TIM_PWM_Stop_IT(&htim2, TIM_CHANNEL_3);
	tur = 0;

}

