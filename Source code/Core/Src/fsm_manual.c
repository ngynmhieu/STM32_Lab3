/*
 * fsm_mode.c
 *
 *  Created on: Oct 22, 2023
 *      Author: Minh Hieu
 */


#include "fsm_manual.h"

void turnoff_leds(){
	HAL_GPIO_WritePin(red1_GPIO_Port, red1_Pin, SET);
	HAL_GPIO_WritePin(yellow1_GPIO_Port, yellow1_Pin, SET);
	HAL_GPIO_WritePin(green1_GPIO_Port, green1_Pin, SET);
	HAL_GPIO_WritePin(red2_GPIO_Port, red2_Pin, SET);
	HAL_GPIO_WritePin(yellow2_GPIO_Port, yellow2_Pin, SET);
	HAL_GPIO_WritePin(green2_GPIO_Port, green2_Pin, SET);
}
void button1_check(){
	if (isButton1Pressed() == 1){
		tmp_red = 1;
		tmp_yellow= 1;
		tmp_green = 1;
		turnoff_leds();
		setTimer4(50); // time duration for blinking led (used for blinky led file)
		if (status == mode_2) status = mode_3;
		else if (status == mode_3) status = mode_4;
		else if (status == mode_4) status = init;
		else status = mode_2;

	}

}

void button2_check(){
	if (isButton2Pressed() == 1){
		if (status == mode_2){
			tmp_red ++;
			if (tmp_red > 99) tmp_red = 99;
		}
		else if (status == mode_3){
			tmp_yellow ++;
			if (tmp_yellow > 99) tmp_yellow = 99;
		}
		else if (status == mode_4){
			tmp_green ++;
			if (tmp_green > 99) tmp_green = 99;
		}
	}
}

void button3_check(){
	if (isButton3Pressed() == 1){
		if (status == mode_2){
			red_time = tmp_red*100;
		}
		else if (status == mode_3){
			yellow_time = tmp_yellow*100;
		}
		else if (status == mode_4){
			green_time = tmp_green*100;
		}
	}
}

void blinky_red_led(){
	if (timer4_flag == 1){
		setTimer4(50);
		HAL_GPIO_TogglePin(red1_GPIO_Port, red1_Pin);
		HAL_GPIO_TogglePin(red2_GPIO_Port, red2_Pin);
	}
}
void blinky_yellow_led(){
	if (timer4_flag == 1){
		setTimer4(50);
		HAL_GPIO_TogglePin(yellow1_GPIO_Port, yellow1_Pin);
		HAL_GPIO_TogglePin(yellow2_GPIO_Port, yellow2_Pin);
	}
}
void blinky_green_led(){
	if (timer4_flag == 1){
		setTimer4(50);
		HAL_GPIO_TogglePin(green1_GPIO_Port, green1_Pin);
		HAL_GPIO_TogglePin(green2_GPIO_Port, green2_Pin);
	}
}

void check_time_valid(){
	int red_t = red_time/100;
	int yellow_t = yellow_time/100;
	int green_t = green_time/100;
	if (red_t > (yellow_t + green_t)){
		int remainder = red_t - yellow_t - green_t;
		green_t = green_t + remainder/2;
		yellow_t = red_t - green_t;
	}
	else if (red_t < (yellow_t + green_t)){
		red_t  = yellow_t + green_t;
	}

	if (yellow_t > green_t){
		int tmp = green_t;
		green_t = yellow_t;
		yellow_t= tmp;
	}
	red_time = red_t*100;
	yellow_time = yellow_t*100;
	green_time = green_t*100;
}

void fsm_manual(){
	int index_0 = 0;
	int index_1 = 0;
	switch(status){
	case mode_2:
		blinky_red_led();
		number_for2led(tmp_red, &index_0, &index_1);
		timefortopbottom(0, 2);
		timeforleftright(index_0, index_1);

		enablechange();
		button1_check();
		button2_check();
		button3_check();
		break;
	case mode_3:
		blinky_yellow_led();
		number_for2led(tmp_yellow, &index_0, &index_1);
		timefortopbottom(0, 3);
		timeforleftright(index_0, index_1);

		enablechange();
		button1_check();
		button2_check();
		button3_check();
		break;
	case mode_4:
		blinky_green_led();
		number_for2led(tmp_green, &index_0, &index_1);
		timefortopbottom(0, 4);
		timeforleftright(index_0, index_1);

		enablechange();
		button1_check();
		button2_check();
		button3_check();

		check_time_valid();
		break;
	default:
		break;
	}
}
