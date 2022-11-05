/*
 * button.c
 *
 *  Created on: Sep 21, 2022
 *      Author: KAI
 */

#include "button.h"

int KeyReg0 = NORMAL_STATE;
int KeyReg1 = NORMAL_STATE;
int KeyReg2 = NORMAL_STATE;
int KeyReg3 = NORMAL_STATE;

int TimeOutForKeyPress =  300;
int button1_flag = 0;


void subKeyProcess(){
	//TODO
	button1_flag = 1;
}

int isButtonPressed(){
	if(button1_flag == 1)
	{
		button1_flag = 0;
		return 1;
	}

	return 0;
}

void getKeyInput(){
  KeyReg0 = KeyReg1;
  KeyReg1 = KeyReg2;
  KeyReg2 = HAL_GPIO_ReadPin(Inc_GPIO_Port, Inc_Pin);
  if ((KeyReg1 == KeyReg0) && (KeyReg1 == KeyReg2)){
    if (KeyReg2 != KeyReg3){
    	KeyReg3 = KeyReg2;
    	if (KeyReg2 == PRESSED_STATE){
    		subKeyProcess();
    		TimeOutForKeyPress = 300;
      }
    }
    else
    {
    	TimeOutForKeyPress --;
    	if (TimeOutForKeyPress == 0){
    		KeyReg3 = NORMAL_STATE;
        }
    }
  }
}

