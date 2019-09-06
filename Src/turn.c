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
extern volatile uint32_t g_timCount;

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
	ome = (180.00 / 180.00) * 3.14;
	r = 50;
	th_rad = (fabsf(g_th) / 180.00) * 3.14;

	if(g_th>0) {
		v_R = v + ome * r;
		v_L = v - ome * r;
	} else {
		v_R = v - ome * r;
		v_L = v + ome * r;
	}


	g_targetTrans.vel_r = v_R;
	g_targetTrans.vel_l = v_L;

	HAL_TIM_Base_Start_IT(&htim1);
	HAL_TIM_PWM_Start_IT(&htim1, TIM_CHANNEL_1);
	HAL_TIM_Base_Start_IT(&htim2);
	HAL_TIM_PWM_Start_IT(&htim2, TIM_CHANNEL_3);

	g_timCount = 0;
	while (g_timCount < (th_rad / ome) * 1000) {
		tur = 1;
//		printf("%d\n\r", g_timCount);
	}
	tur = 1;

	HAL_TIM_Base_Stop_IT(&htim1);
	HAL_TIM_PWM_Stop_IT(&htim1, TIM_CHANNEL_1);
	HAL_TIM_Base_Stop_IT(&htim2);
	HAL_TIM_PWM_Stop_IT(&htim2, TIM_CHANNEL_3);
	tur = 0;

}

