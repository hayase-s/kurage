/*
 * AD.h
 *
 *  Created on: 2018/09/09
 *      Author: kanako
 */

#ifndef AD_H_
#define AD_H_

typedef struct {
	int center;
	int right;
	int left;
} wallsenpara;

extern wallsenpara g_offWallSensorValue, g_onWallSensorValue,
		g_nowWallSensorValue;

enum sen_change {
	OFFVALUE, SIDEVALUE, FRONTVALUE, END
};

#endif /* AD_H_ */
