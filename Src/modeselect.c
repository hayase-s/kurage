/*
 * modeselect.c
 *
 *  Created on: 2018/08/07
 *      Author: kanako
 */

#include "stm32f3xx_hal.h"
#include "spi.h"
#include "gpio.h"

#include "myassign.h"

#include "aqm1248a.h"
#include "font.h"

#include <stdio.h>
#include <string.h>
#include <stdarg.h>

void mode1(void){
	printfLCD(0,0,BLACK,"mode1");
	printfLCD(1,2,WHITE,"adachi");
}

void mode2(void){
	printfLCD(0,0,BLACK,"mode2");
	printfLCD(1,2,WHITE,"hidarite");
}
