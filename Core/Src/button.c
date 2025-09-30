/*
 * button.c
 *
 *  Created on: Sep 29, 2025
 *      Author: dinhh
 */

#include "button.h"

int KeyReg[10] = {0};
int TimeOutForKeyPress = 500;
int button_flag[10] = {0};
int button_long_pressed[10] = {0};

int isButtonPressed(int index){
	if (button_flag[index] == 1){
		button_flag[index] = 0;
		return 1;
	}
	return 0;
}

int isLongButtonPressed(int index){
	if (button_long_pressed[index] == 1){
		button_long_pressed[index] = 0;
		return 1;
	}
	return 0;
}

void getKeyInput(){

}
