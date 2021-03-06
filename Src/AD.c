/* * AD.c
 *
 *  Created on: 2018/09/09
 *      Author: kanako
 */

#include "stm32f3xx_hal.h"
#include "aqm1248a.h"
#include "adc.h"
#include "AD.h"
wallsenpara g_offWallSensorValue;
wallsenpara g_onWallSensorValue;
wallsenpara g_nowWallSensorValue;
int g_ADCcount;
uint8_t g_sensorLEDFlag;
float batf;

uint16_t g_ADCBuffer[4];

void HAL_ADC_ConvCpltCallback(ADC_HandleTypeDef* hadc) {
//	printf("%4d,%4d,%4d,%4d\n\r", g_ADCBuffer[0], g_ADCBuffer[1],
//			g_ADCBuffer[2], g_ADCBuffer[3]);
//	batf = 3.3 * (g_ADCBuffer[0] / 4095.0) * (100.0 + 22.0) / 22.0;
//	printf("%f\n\r", batf);

//	[0]=bat
//	[1]=left
//	[2]=center
//	[3]=right
}

void AD_bat(void) {
	HAL_Delay(10);
	batf = 1.066 * 3.3 * (g_ADCBuffer[0] / 4095.0) * (100.0 + 22.0) / 22.0;

	if (batf < 11.1) {
		printfLCD(0, 0, BLACK, "   ERROR!     ");
		printfLCD(1, 0, WHITE, "battery");
		printfLCD(2, 3, WHITE, "%.2fV\n\r", batf);
		while (1) {
		}
	} else {
		printfLCD(0, 0, BLACK, "    OK!    ");
		printfLCD(1, 0, WHITE, "battery");
		printfLCD(2, 3, WHITE, "%.2fV\n\r", batf);
	}
	volatile int i = 0;
	while (i == 0) {
		if (HAL_GPIO_ReadPin(GPIOB, GPIO_PIN_0) == HIGH) {
		} else {
			i = 1;
			HAL_Delay(100);
		}
	}
}

void getWallSensorValue(void) {
	volatile uint32_t onSENSORLEDWAITCOUNT;
	volatile uint32_t offSENSORLEDWAITCOUNT;
	onSENSORLEDWAITCOUNT = 250;
	offSENSORLEDWAITCOUNT = 250;

//消灯時の値を得る
	g_offWallSensorValue.left = g_ADCBuffer[1];
	g_offWallSensorValue.right = g_ADCBuffer[3];
	g_offWallSensorValue.center = g_ADCBuffer[2];

//左右のLEDを点灯
	if (g_sensorLEDFlag == 1) {
		sensorSideLED(HIGH);
		volatile uint16_t i;
		for (i = 0; i < onSENSORLEDWAITCOUNT; i++) {
		} //立ち上がり待ち
	}

//左右方向のセンサの値を得る
	g_onWallSensorValue.left = g_ADCBuffer[1];
	g_onWallSensorValue.right = g_ADCBuffer[3];

//左右のLEDを消灯
	if (g_sensorLEDFlag == 1) {
		sensorSideLED(LOW);
		volatile uint16_t i;
		for (i = 0; i < offSENSORLEDWAITCOUNT; i++) {
		} //立ち上がり待ち
	}

//前方向のLEDを点灯
	if (g_sensorLEDFlag == 1) {
		sensorFrontLED(HIGH);
		volatile uint16_t i;
		for (i = 0; i < onSENSORLEDWAITCOUNT; i++) {
		} //立ち上がり待ち
	}

//前方向のセンサの値を得る
	g_onWallSensorValue.center = g_ADCBuffer[2];

//前方向のLEDを消灯
	if (g_sensorLEDFlag == 1) {
		sensorFrontLED(LOW);
		volatile uint16_t i;
		for (i = 0; i < offSENSORLEDWAITCOUNT; i++) {
		} //立ち上がり待ち
	}

	g_nowWallSensorValue.center = g_onWallSensorValue.center
			- g_offWallSensorValue.center;
	g_nowWallSensorValue.left = g_onWallSensorValue.left
			- g_offWallSensorValue.left;
	g_nowWallSensorValue.right = g_onWallSensorValue.right
			- g_offWallSensorValue.right;

}

void getSensorvalue(void) {
	while (1) {
		printf("L=%d,C=%d,R=%d\n\r", g_nowWallSensorValue.left,
				g_nowWallSensorValue.center, g_nowWallSensorValue.right);
		HAL_Delay(200);
	}
}

