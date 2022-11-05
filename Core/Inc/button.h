/*
 * button.h
 *
 *  Created on: Nov 5, 2022
 *      Author: trand
 */

#ifndef INC_BUTTON_H_
#define INC_BUTTON_H_

#include "main.h"

#define NORMAL_STATE 1
#define PRESSED_STATE 0

extern int ResetFlag;
extern int IncFlag;
extern int DecFlag;

int isResetPressed();
int isIncPressed();
int isDecPressed();
void getResetKeyInput();
void getIncKeyInput();
void getDecKeyInput();

#endif /* INC_BUTTON_H_ */
