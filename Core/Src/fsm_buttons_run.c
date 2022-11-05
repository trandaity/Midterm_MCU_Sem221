/*
 * fsm_buttons_run.c
 *
 *  Created on: Nov 5, 2022
 *      Author: trand
 */

#include "fsm_buttons_run.h"

void fsm_buttons_run(int buttonStatus, int counter){
	switch(buttonStatus)
	{
	case 0: //Press reset button
	{
		counter %= counter;
		break;
	}
	case 1: //Press increase button
	{
		counter++;
		if(counter >= 10)
		{
			counter = 0;
		}
		break;
	}
	case 2: //Press decrease button
	{
		counter--;
		if(counter < 0)
		{
			counter = 9;
		}
		break;
	}
	default: break;
	}
}
