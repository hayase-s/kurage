/*
 * buzzer.c
 *
 *  Created on: 2018/09/09
 *      Author: kanako
 */

#include "tim.h"

void buzzer(void){
HAL_TIM_PWM_Start(&htim3, TIM_CHANNEL_2); //buzzer
}
