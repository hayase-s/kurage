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
float w;
int tur;
int th;

void turn(void) {
	HAL_GPIO_WritePin(GPIOB, GPIO_PIN_6, HIGH);
	HAL_GPIO_WritePin(GPIOB, GPIO_PIN_7, SET);
	HAL_Delay(3);
	HAL_GPIO_WritePin(GPIOB, GPIO_PIN_7, RESET);

	HAL_TIM_PWM_Stop(&htim1, TIM_CHANNEL_1);
	HAL_TIM_PWM_Stop(&htim2, TIM_CHANNEL_3);

	v = 0; //重心速度
	ome = 200; //角加速度
	w = 70; //ドレッド幅
	th = 0;

	v_R = v + ome * (w / 2);
	v_L = v - ome * (w / 2);

	printf("R=%f L=%f\n\r", v_R, v_L);

	HAL_TIM_PWM_Start_IT(&htim1, TIM_CHANNEL_1);
	HAL_TIM_PWM_Start_IT(&htim2, TIM_CHANNEL_3);
	g_targetTrans.vel_r = v_R;
	g_targetTrans.vel_l = v_L;

	tur = 1;
	while (th < 900) {
		rightcalPWMCount(g_targetTrans.wvel_r);
		leftcalPWMCount(g_targetTrans.wvel_l);
		th++;
	}

	HAL_TIM_PWM_Stop(&htim1, TIM_CHANNEL_1);
	HAL_TIM_PWM_Stop(&htim2, TIM_CHANNEL_3);
	tur = 0;

}

