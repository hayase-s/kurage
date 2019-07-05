/*
 * motor.h
 *
 *  Created on: 2018/09/09
 *      Author: kanako
 */

#ifndef MOTOR_H_
#define MOTOR_H_

typedef struct{
	float dis;
	float vel_r;
	float vel_l;
	float wvel_r;
	float wvel_l;
	float acc;
} tarparameter;

extern tarparameter g_targetTrans;

#endif /* MOTOR_H_ */




