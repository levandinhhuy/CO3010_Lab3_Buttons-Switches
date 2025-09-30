/*
 * button.h
 *
 *  Created on: Sep 29, 2025
 *      Author: dinhh
 */

#ifndef INC_BUTTON_H_
#define INC_BUTTON_H_

#include "main.h"

#define NORMAL_STATE SET
#define PRESSED_STATE RESET

extern int KeyReg[10];
extern int TimeOutForKeyPress;
extern int button_flag[10];
extern int button_long_pressed[10];

int isButtonPressed(int index);
int isButtonLongPressed(int index);
void getKeyInput();

#endif /* INC_BUTTON_H_ */
