/*
 * button.c
 *
 *  Created on: Oct 22, 2023
 *      Author: Minh Hieu
 */


#include "button.h"

int KeyReg0_1 = NORMAL_STATE;
int KeyReg1_1 = NORMAL_STATE;
int KeyReg2_1 = NORMAL_STATE;
int KeyReg3_1 = NORMAL_STATE;

int KeyReg0_2 = NORMAL_STATE;
int KeyReg1_2 = NORMAL_STATE;
int KeyReg2_2 = NORMAL_STATE;
int KeyReg3_2 = NORMAL_STATE;

int KeyReg0_3 = NORMAL_STATE;
int KeyReg1_3 = NORMAL_STATE;
int KeyReg2_3 = NORMAL_STATE;
int KeyReg3_3 = NORMAL_STATE;

int button1_flag = 0;
int button2_flag = 0;
int button3_flag = 0;
int TimeOutForKeyPress =  200;

int isButton1Pressed(){
	if (button1_flag == 1){
		button1_flag = 0;
		return 1;
	}
	return 0;
}
int isButton2Pressed(){
	if (button2_flag == 1){
		button2_flag = 0;
		return 1;
	}
	return 0;
}
int isButton3Pressed(){
	if (button3_flag == 1){
		button3_flag = 0;
		return 1;
	}
	return 0;
}

void subKeyProcess(int i){
	if (i == 1) button1_flag = 1;
	if (i == 2) button2_flag = 1;
	if (i == 3) button3_flag = 1;
}
void getKeyinput(){
	KeyReg0_1 = KeyReg1_1;
	KeyReg1_1 = KeyReg2_1;
	KeyReg2_1 = HAL_GPIO_ReadPin(Button1_GPIO_Port, Button1_Pin);

	KeyReg0_2 = KeyReg1_2;
	KeyReg1_2 = KeyReg2_2;
	KeyReg2_2 = HAL_GPIO_ReadPin(Button2_GPIO_Port, Button2_Pin);

	KeyReg0_3 = KeyReg1_3;
	KeyReg1_3 = KeyReg2_3;
	KeyReg2_3 = HAL_GPIO_ReadPin(Button3_GPIO_Port, Button3_Pin);

	if ((KeyReg0_1 == KeyReg1_1) && (KeyReg1_1 == KeyReg2_1)){
		if (KeyReg3_1 != KeyReg2_1){
			KeyReg3_1 = KeyReg2_1;

			if (KeyReg3_1 == PRESSED_STATE){
				TimeOutForKeyPress= 200;
				subKeyProcess(1);
			}
		}
		else{
			TimeOutForKeyPress --;
			if (TimeOutForKeyPress ==0 ){
				KeyReg3_1 = NORMAL_STATE;
			}
		}
	}
	if ((KeyReg0_2 == KeyReg1_2) && (KeyReg1_2 == KeyReg2_2)){
		if (KeyReg3_2 != KeyReg2_2){
			KeyReg3_2 = KeyReg2_2;

			if (KeyReg3_2 == PRESSED_STATE){
				TimeOutForKeyPress= 200;
				subKeyProcess(2);
			}
		}
		else{
			TimeOutForKeyPress --;
			if (TimeOutForKeyPress ==0 ){
				KeyReg3_2 = NORMAL_STATE;
			}
		}
	}
	if ((KeyReg0_3 == KeyReg1_3) && (KeyReg1_3 == KeyReg2_3)){
		if (KeyReg3_3 != KeyReg2_3){
			KeyReg3_3 = KeyReg2_3;

			if (KeyReg3_3 == PRESSED_STATE){
				TimeOutForKeyPress= 200;
				subKeyProcess(3);
			}
		}
		else{
			TimeOutForKeyPress --;
			if (TimeOutForKeyPress ==0 ){
				KeyReg3_3 = NORMAL_STATE;
			}
		}
	}
}
