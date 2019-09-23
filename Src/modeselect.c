/*
 * modeselect.c
 *
 *  Created on: 2018/08/07
 *      Author: kanako
 */

#include "modeselect.h"
#include "aqm1248a.h"
#include "myassign.h"
#include "gpio.h"
#include "stm32f3xx_hal.h"
#include "hidarite.h"
#include "stm32f3xx_hal_gpio.h"


//void modeSelect(void) {
//	uint8_t mode;
//	uint8_t select;
//	for (uint8_t i = 0; i <= 3; i++) {
//		select = 0;
//		if (i % 4 == 0) { //モードセレクト
//			printfLCD(1, 0, WHITE, "MODE SELECT");
//			if (HAL_GPIO_ReadPin(GPIOB, GPIO_PIN_0) == LOW) { //次のモード画面に
//				HAL_Delay(100);
//				i = 0;
//				select = 1;
//			} else if (HAL_GPIO_ReadPin(GPIOB, GPIO_PIN_1) == LOW) { //次のモード画面に
//				HAL_Delay(100);
//				i = 0;
//				select = 1;
//			} else {
//			}
//		} else if (i % 4 == 1) { //足立法
//			printfLCD(1, 0, WHITE, "ADACHI");
//
//			while (select == 0) {
//				if (HAL_GPIO_ReadPin(GPIOB, GPIO_PIN_0) == LOW) { //次のモード画面に
//					HAL_Delay(100);
//					select = 1;
//				} else if (HAL_GPIO_ReadPin(GPIOB, GPIO_PIN_1) == LOW) { //足立法スタート
//					HAL_Delay(100);
//					mode = 1;
//					i = 3;
//					select = 1;
//				} else {
//				}
//			}
//
//		} else if (i % 4 == 2) {
//			printfLCD(1, 0, WHITE, "MAP");
//			while (select == 0) {
//				if (HAL_GPIO_ReadPin(GPIOB, GPIO_PIN_0) == LOW) { //次のモード画面に
//					HAL_Delay(100);
//					select = 1;
//				} else if (HAL_GPIO_ReadPin(GPIOB, GPIO_PIN_1) == LOW) { //マップ表示
//					HAL_Delay(100);
//					mode = 2;
//					i = 3;
//					select = 1;
//				} else {
//				}
//			}
//
//		} else { //左手法
//			printfLCD(1, 0, WHITE, "HIDARITE");
//			while (select == 0) {
//				if (HAL_GPIO_ReadPin(GPIOB, GPIO_PIN_0) == LOW) { //次のモード画面に
//					HAL_Delay(100);
//					select = 1;
//				} else if (HAL_GPIO_ReadPin(GPIOB, GPIO_PIN_1) == LOW) { //マップ表示
//					HAL_Delay(100);
//					mode = 3;
//					i = 3;
//					select = 1;
//				} else {
//				}
//			}
//		}
//	}
//
//	if (mode == 1) { //ADACH
//		printfLCD(1, 0, WHITE, "ADACHI START!");
//	} else if (mode == 2) { //MAP
//		printfLCD(1, 0, WHITE, "MAP START!");
//	} else { //HIDARITE
//		printfLCD(1, 0, WHITE, "HIDARITE START!");
//		hidarite();
//	}
//
//}
