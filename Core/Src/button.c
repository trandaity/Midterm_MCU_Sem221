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

int KeyReg4 = NORMAL_STATE;
int KeyReg5 = NORMAL_STATE;
int KeyReg6 = NORMAL_STATE;
int KeyReg7 = NORMAL_STATE;

int KeyReg8 = NORMAL_STATE;
int KeyReg9 = NORMAL_STATE;
int KeyReg10 = NORMAL_STATE;
int KeyReg11 = NORMAL_STATE;

//int ButtonsArr[3] = {ResetButtonRead, IncButtonRead, DecButtonRead};

int TimeOutForResetKeyPress;
int TimeOutForIncKeyPress;
int TimeOutForDecKeyPress;
//int TimeOutForButtons[3] = {};
int ResetFlag = 0;
int IncFlag = 0;
int DecFlag = 0;

//void subKeyProcess(){
//	//TODO
//	button1_flag = 1;
//}

void ResetKeyActivate()
{
	ResetFlag = 1;
}

void IncKeyActivate()
{
	IncFlag = 1;
}

void DecKeyActivate()
{
	DecFlag = 1;
}

//int isButtonPressed(){
//	if(button1_flag == 1)
//	{
//		button1_flag = 0;
//		return 1;
//	}
//
//	return 0;
//}

int isResetPressed()
{
	if(ResetFlag)
	{
		ResetFlag = 0;
		return 1;
	}
	return 0;
}

int isIncPressed(){
	if(IncFlag)
	{
		IncFlag = 0;
		return 1;
	}
	return 0;
}

int isDecPressed(){
	if(DecFlag)
	{
		DecFlag = 0;
		return 1;
	}
	return 0;
}

void getResetKeyInput(){
  KeyReg0 = KeyReg1;
  KeyReg1 = KeyReg2;
  KeyReg2 = HAL_GPIO_ReadPin(Reset_GPIO_Port, Reset_Pin);
  if ((KeyReg1 == KeyReg0) && (KeyReg1 == KeyReg2)){
    if (KeyReg2 != KeyReg3){
    	KeyReg3 = KeyReg2;
    	if (KeyReg2 == PRESSED_STATE){
    		ResetKeyActivate();
    		TimeOutForResetKeyPress = 300;
      }
    }
    else
    {
    	TimeOutForResetKeyPress --;
    	if (TimeOutForResetKeyPress == 0){
    		KeyReg3 = NORMAL_STATE;
        }
    }
  }
}

void getIncKeyInput(){
  KeyReg4 = KeyReg5;
  KeyReg5 = KeyReg6;
  KeyReg6 = HAL_GPIO_ReadPin(Inc_GPIO_Port, Inc_Pin);
  if ((KeyReg5 == KeyReg4) && (KeyReg5 == KeyReg6)){
    if (KeyReg6 != KeyReg7){
    	KeyReg7 = KeyReg6;
    	if (KeyReg6 == PRESSED_STATE){
    		IncKeyActivate();
    		TimeOutForIncKeyPress = 300;
      }
    }
    else
    {
    	TimeOutForIncKeyPress --;
    	if (TimeOutForIncKeyPress == 0){
    		KeyReg7 = NORMAL_STATE;
        }
    }
  }
}

void getDecKeyInput(){
  KeyReg8 = KeyReg9;
  KeyReg9 = KeyReg10;
  KeyReg10 = HAL_GPIO_ReadPin(Dec_GPIO_Port, Dec_Pin);
  if ((KeyReg9 == KeyReg8) && (KeyReg9 == KeyReg10)){
    if (KeyReg10 != KeyReg11){
    	KeyReg11 = KeyReg10;
    	if (KeyReg10 == PRESSED_STATE){
    		DecKeyActivate();
    		TimeOutForDecKeyPress = 300;
      }
    }
    else
    {
    	TimeOutForDecKeyPress --;
    	if (TimeOutForDecKeyPress == 0){
    		KeyReg11 = NORMAL_STATE;
        }
    }
  }
}
//  KeyReg0 = KeyReg1;
//  KeyReg1 = KeyReg2;
//  for(int i = 0 ; i < 2 ; i++)
//  {
//	  if(ButtonsArr[i] == ResetButtonRead)
//	  {
//		  KeyReg2 = HAL_GPIO_ReadPin(Reset_GPIO_Port, Reset_Pin);
//	  }
//	  else if(ButtonsArr[i] == IncButtonRead)
//	  {
//		  KeyReg2 = HAL_GPIO_ReadPin(Inc_GPIO_Port, Inc_Pin);
//	  }
//	  else KeyReg2 =  HAL_GPIO_ReadPin(Dec_GPIO_Port, Dec_Pin);
//
//	  if ((KeyReg1 == KeyReg0) && (KeyReg1 == KeyReg2)){
//		  if (KeyReg2 != KeyReg3){
//			  KeyReg3 = KeyReg2;
//			  if (KeyReg2 == PRESSED_STATE){
//				  //subKeyProcess();
//				  switch(ButtonsArr[i])
//				  {
//				  case ResetButtonRead: // Upon pressing Reset button
//				  {
//					  ResetKeyActivate();
//					  break;
//				  }
//				  case IncButtonRead: // Upon pressing Inc button
//				  {
//					  IncKeyActivate();
//					  break;
//				  }
//				  case DecButtonRead: // Upon pressing Dec button
//				  {
//					  DecKeyActivate();
//					  break;
//				  }
//				  default: break;
//				  }
//				  TimeOutForButtons[i] = 300;
//			  }
//		  }
//	      else
//	      {
//	      	TimeOutForButtons[i]--;
//	      	if (TimeOutForButtons[i] == 0){
//	      		KeyReg3 = NORMAL_STATE;
//	          }
//	      }
//	    }
//  }
////  KeyReg2 = HAL_GPIO_ReadPin(Inc_GPIO_Port, Inc_Pin);
////  if ((KeyReg1 == KeyReg0) && (KeyReg1 == KeyReg2)){
////    if (KeyReg2 != KeyReg3){
////    	KeyReg3 = KeyReg2;
////    	if (KeyReg2 == PRESSED_STATE){
////    		subKeyProcess();
////    		TimeOutForKeyPress = 300;
////      }
////    }
////    else
////    {
////    	TimeOutForKeyPress --;
////    	if (TimeOutForKeyPress == 0){
////    		KeyReg3 = NORMAL_STATE;
////        }
////    }
////  }
//}

