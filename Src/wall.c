/*
 * wall.c
 *
 *  Created on: May 13, 2019
 *      Author: kanako
 */

#include "wall.h"
#include <stdlib.h>
float Error;
float Kp; //制御定数0.1〜0.5ぐらい
float control;
float r_threshold;
float l_threshold;
float DIFF_THRESHOLD;
senpara sen_l;
senpara sen_r;

void KABE(void) {
	Kp = 0.6;
	sen_l.thredhold = 41;
	sen_r.thredhold = 77; //閾値
	sen_l.ref = 82;
	sen_r.ref = 270; //真ん中においた時のセンサの値
	DIFF_THRESHOLD = 30;

	sen_r.value = g_nowWallSensorValue.right;
	sen_l.value = g_nowWallSensorValue.left;
//	printf("l=%f,r=%f\n\r", sen_l.value, sen_r.value);
	if (abs(sen_r.diff) > DIFF_THRESHOLD) {
		r_threshold = sen_r.ref + 10;  //変化量が一定以上なら、閾値を引き上げる
	} else {
		r_threshold = sen_r.thredhold; //変化量が一定以下なら、設定通りの閾値
	}
	if (abs(sen_l.diff) > DIFF_THRESHOLD) {
		l_threshold = sen_l.ref + 10;  //変化量が一定以上なら、閾値を引き上げる
	} else {
		l_threshold = sen_l.thredhold; //変化量が一定以下なら、設定通りの閾値
	}

	if ((sen_r.value > r_threshold) && (sen_l.value > l_threshold)) {
		//両壁あり
		Error = (sen_l.value - sen_l.ref) - (sen_r.value - sen_r.ref); //右に寄ってたらマイナス
//		printf("両壁あり\n\r");
//		printf("l.val=%f,r.val=%f\n\r", sen_l.value, sen_r.value);
//		printf("%f\n\r", Error);
	} else if ((sen_r.value <= r_threshold) && (sen_l.value < l_threshold)) {
		//両壁なし
		Error = 0;
//		printf("両壁なし\n\r");
//		printf("l.val=%f,r.val=%f\n\r", sen_l.value, sen_r.value);
//		printf("%f\n\r", Error);
	} else if (sen_r.value > r_threshold) {
		//右壁のみあり
		Error = -2.0 * (sen_r.value - sen_r.ref); //右に寄ってたらマイナス
//		printf("右壁のみあり\n\r");
//		printf("r.val=%f,r.ref=%f\n\r", sen_r.value, sen_r.ref);
//		printf("%f\n\r", Error);
	} else {
		//左壁のみあり
		Error = 2.0 * (sen_l.value - sen_l.ref); //左に寄ってたらプラス
//		printf("左壁のみあり\n\r");
//		printf("l.val=%f,l.ref=%f\n\r", sen_l.value, sen_l.ref);
//		printf("%f\n\r", Error);
	}
	control = Kp * Error;

}
