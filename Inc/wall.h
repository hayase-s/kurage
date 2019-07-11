/*
 * wall.h
 *
 *  Created on: May 13, 2019
 *      Author: kanako
 */

#ifndef WALL_H_
#define WALL_H_
#include "gpio.h"
#include "AD.h"
#include <stdint.h>
#include "myassign.h"

typedef struct {
	float value; //センサの値
	float ref; //真ん中に置いた時のセンサの値
	float val;
	float thredhold;
	float diff;
	float old_val;
} senpara;

extern senpara sen_r, sen_l;

#endif /* WALL_H_ */
