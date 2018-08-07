/*
 * myassign.h
 *
 *  Created on: 2018/07/05
 *      Author: shun
 */

#ifndef MYASSIGN_H_
#define MYASSIGN_H_

enum ONOFF {
	HIGH = 1, LOW = 0
};

void lcdRS(uint8_t onOff);
void lcdCS(uint8_t onOff);


#endif /* MYASSIGN_H_ */
