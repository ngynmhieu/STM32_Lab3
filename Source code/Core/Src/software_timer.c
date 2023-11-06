/*
 * software_timer.c
 *
 *  Created on: Oct 22, 2023
 *      Author: Minh Hieu
 */


#include "software_timer.h"

int timer1_counter = 0;
int timer1_flag = 0;
int timer2_counter = 0;
int timer2_flag = 0;
int timer3_counter = 0;
int timer3_flag = 0;
int timer4_counter = 0;
int timer4_flag = 0;
TIM_HandleTypeDef htim2;

// Declare the variables
uint32_t prescaler_value;
uint32_t counter_period_value;
int Timer;
void initialize_issue()
{
    HAL_TIM_Base_Start(&htim2);

    prescaler_value = htim2.Instance->PSC;
    counter_period_value = htim2.Instance->ARR;
    Timer = 1000*(prescaler_value + 1)*(counter_period_value)/8000000;
}



void setTimer1(int duration){
	timer1_counter = duration*10/Timer;
	timer1_flag = 0;
}
void setTimer2(int duration){
	timer2_counter = duration*10/Timer;
	timer2_flag = 0;
}
void setTimer3(int duration){
	timer3_counter = duration*10/Timer;
	timer3_flag = 0;
}
void setTimer4(int duration){
	timer4_counter = duration*10/Timer;
	timer4_flag = 0;
}

void timerRun(){
	if (timer1_counter>0){
		timer1_counter--;
		if (timer1_counter ==0 ){
			timer1_flag = 1;
		}
	}
	if (timer2_counter>0){
		timer2_counter--;
		if (timer2_counter ==0 ){
			timer2_flag = 1;
		}
	}
	if (timer3_counter>0){
		timer3_counter--;
		if (timer3_counter ==0 ){
			timer3_flag = 1;
		}
	}
	if (timer4_counter>0){
		timer4_counter--;
		if (timer4_counter ==0 ){
			timer4_flag = 1;
		}
	}
}
