/*
 * AD.c
 *
 *  Created on: 2018/09/09
 *      Author: kanako
 */

#include "stm32f3xx_hal.h"
#include "aqm1248a.h"
#include "adc.h"

	float batf;
void AD_bat(void){

	uint16_t bat;
	HAL_ADCEx_Calibration_Start(&hadc1, ADC_SINGLE_ENDED);
	HAL_ADC_Start(&hadc1);
	HAL_ADC_PollForConversion(&hadc1, 100);
	bat = HAL_ADC_GetValue(&hadc1);
	HAL_ADC_Stop(&hadc1);
	batf = 3.3 * (float) bat / 1023.0 * (100.0 + 22.0) / 22.0;
	printfLCD(0, 0, WHITE, "battery=");
	printfLCD(1, 2, WHITE, "%f\n\r", batf);
}
