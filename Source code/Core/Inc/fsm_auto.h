/*
 * fsm_traffic_light.h
 *
 *  Created on: Oct 22, 2023
 *      Author: Minh Hieu
 */

#ifndef INC_FSM_AUTO_H_
#define INC_FSM_AUTO_H_

#include "global.h"




#define topbottom 122
#define leftright 123

#define red_led 90
#define yellow_led 91
#define green_led 92


//enable_trigger
extern int enable_trigger;
void enablechange();
//temp variable for timer
extern int tmp_red;
extern int tmp_yellow;
extern int tmp_green;

void display7SEGtopbottom(int number);
void display7SEGleftright(int number);
void timefortopbottom(int num0, int num1);
void timeforleftright(int num0, int num1);
void number_for2led(int duration, int *index_0, int *index_1);
void fsm_auto();
#endif /* INC_FSM_AUTO_H_ */
