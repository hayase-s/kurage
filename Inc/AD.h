/*
 * AD.h
 *
 *  Created on: 2018/09/09
 *      Author: kanako
 */

#ifndef AD_H_
#define AD_H_
#include <stdint.h>

typedef struct {
	uint16_t center;
	uint16_t right;
	uint16_t left;
} wallsenpara;

extern wallsenpara g_offWallSensorValue, g_onWallSensorValue,
		g_nowWallSensorValue;

enum sen_change {
	OFFVALUE, SIDEVALUE, FRONTVALUE, END
};

void getWallSensorValue(void);
void AD_bat(void);
void getSensorvalue(void);

#endif /* AD_H_ */
