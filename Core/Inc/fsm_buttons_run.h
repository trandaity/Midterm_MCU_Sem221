/*
 * fsm_buttons_run.h
 *
 *  Created on: Nov 5, 2022
 *      Author: trand
 */

#ifndef INC_FSM_BUTTONS_RUN_H_
#define INC_FSM_BUTTONS_RUN_H_

#define ButtonRESET 		0
#define ButtonINC 			1
#define ButtonDEC			2
#define NoButtonsPressed 	3

#include "main.h"
#include "display7SEG.h"


void fsm_buttons_run(int buttonStatus, int counter);

#endif /* INC_FSM_BUTTONS_RUN_H_ */
