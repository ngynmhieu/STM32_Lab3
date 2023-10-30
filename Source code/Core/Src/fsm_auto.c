/*
 * fsm_traffic_light.c
 *
 *  Created on: Oct 22, 2023
 *      Author: Minh Hieu
 */

#include "fsm_auto.h"
int status = 11;

int red_time = 500;
int yellow_time = 200;
int green_time = 300;

int tmp_red = 0;
int tmp_yellow = 0;
int tmp_green = 0;

int enable_trigger = 0;

void display7SEGtopbottom(int num){
	  if (num == 0){
		  HAL_GPIO_WritePin(a1_GPIO_Port, a1_Pin, RESET);
		  HAL_GPIO_WritePin(b1_GPIO_Port, b1_Pin, RESET);
		  HAL_GPIO_WritePin(c1_GPIO_Port, c1_Pin, RESET);
		  HAL_GPIO_WritePin(d1_GPIO_Port, d1_Pin, RESET);
		  HAL_GPIO_WritePin(e1_GPIO_Port, e1_Pin, RESET);
		  HAL_GPIO_WritePin(f1_GPIO_Port, f1_Pin, RESET);
		  HAL_GPIO_WritePin(g1_GPIO_Port, g1_Pin, SET);
	  }
	  else if (num == 1){
		  HAL_GPIO_WritePin(a1_GPIO_Port, a1_Pin, SET);
		  HAL_GPIO_WritePin(b1_GPIO_Port, b1_Pin, RESET);
		  HAL_GPIO_WritePin(c1_GPIO_Port, c1_Pin, RESET);
		  HAL_GPIO_WritePin(d1_GPIO_Port, d1_Pin, SET);
		  HAL_GPIO_WritePin(e1_GPIO_Port, e1_Pin, SET);
		  HAL_GPIO_WritePin(f1_GPIO_Port, f1_Pin, SET);
		  HAL_GPIO_WritePin(g1_GPIO_Port, g1_Pin, SET);
	  }
	  else if (num == 2){
		  HAL_GPIO_WritePin(a1_GPIO_Port, a1_Pin, RESET);
		  HAL_GPIO_WritePin(b1_GPIO_Port, b1_Pin, RESET);
		  HAL_GPIO_WritePin(c1_GPIO_Port, c1_Pin, SET);
		  HAL_GPIO_WritePin(d1_GPIO_Port, d1_Pin, RESET);
		  HAL_GPIO_WritePin(e1_GPIO_Port, e1_Pin, RESET);
		  HAL_GPIO_WritePin(f1_GPIO_Port, f1_Pin, SET);
		  HAL_GPIO_WritePin(g1_GPIO_Port, g1_Pin, RESET);
	  }
	  else if (num == 3){
		  HAL_GPIO_WritePin(a1_GPIO_Port, a1_Pin, RESET);
		  HAL_GPIO_WritePin(b1_GPIO_Port, b1_Pin, RESET);
		  HAL_GPIO_WritePin(c1_GPIO_Port, c1_Pin, RESET);
		  HAL_GPIO_WritePin(d1_GPIO_Port, d1_Pin, RESET);
		  HAL_GPIO_WritePin(e1_GPIO_Port, e1_Pin, SET);
		  HAL_GPIO_WritePin(f1_GPIO_Port, f1_Pin, SET);
		  HAL_GPIO_WritePin(g1_GPIO_Port, g1_Pin, RESET);
	  }
	  else if (num == 4){
		  HAL_GPIO_WritePin(a1_GPIO_Port, a1_Pin, SET);
		  HAL_GPIO_WritePin(b1_GPIO_Port, b1_Pin, RESET);
		  HAL_GPIO_WritePin(c1_GPIO_Port, c1_Pin, RESET);
		  HAL_GPIO_WritePin(d1_GPIO_Port, d1_Pin, SET);
		  HAL_GPIO_WritePin(e1_GPIO_Port, e1_Pin, SET);
		  HAL_GPIO_WritePin(f1_GPIO_Port, f1_Pin, RESET);
		  HAL_GPIO_WritePin(g1_GPIO_Port, g1_Pin, RESET);
	  }
	  else if (num == 5){
		  HAL_GPIO_WritePin(a1_GPIO_Port, a1_Pin, RESET);
		  HAL_GPIO_WritePin(b1_GPIO_Port, b1_Pin, SET);
		  HAL_GPIO_WritePin(c1_GPIO_Port, c1_Pin, RESET);
		  HAL_GPIO_WritePin(d1_GPIO_Port, d1_Pin, RESET);
		  HAL_GPIO_WritePin(e1_GPIO_Port, e1_Pin, SET);
		  HAL_GPIO_WritePin(f1_GPIO_Port, f1_Pin, RESET);
		  HAL_GPIO_WritePin(g1_GPIO_Port, g1_Pin, RESET);
	  }
	  else if (num == 6){
		  HAL_GPIO_WritePin(a1_GPIO_Port, a1_Pin, RESET);
		  HAL_GPIO_WritePin(b1_GPIO_Port, b1_Pin, SET);
		  HAL_GPIO_WritePin(c1_GPIO_Port, c1_Pin, RESET);
		  HAL_GPIO_WritePin(d1_GPIO_Port, d1_Pin, RESET);
		  HAL_GPIO_WritePin(e1_GPIO_Port, e1_Pin, RESET);
		  HAL_GPIO_WritePin(f1_GPIO_Port, f1_Pin, RESET);
		  HAL_GPIO_WritePin(g1_GPIO_Port, g1_Pin, RESET);
	  }
	  else if (num == 7){
		  HAL_GPIO_WritePin(a1_GPIO_Port, a1_Pin, RESET);
		  HAL_GPIO_WritePin(b1_GPIO_Port, b1_Pin, RESET);
		  HAL_GPIO_WritePin(c1_GPIO_Port, c1_Pin, RESET);
		  HAL_GPIO_WritePin(d1_GPIO_Port, d1_Pin, SET);
		  HAL_GPIO_WritePin(e1_GPIO_Port, e1_Pin, SET);
		  HAL_GPIO_WritePin(f1_GPIO_Port, f1_Pin, SET);
		  HAL_GPIO_WritePin(g1_GPIO_Port, g1_Pin, SET);
	  }
	  else if (num == 8){
		  HAL_GPIO_WritePin(a1_GPIO_Port, a1_Pin, RESET);
		  HAL_GPIO_WritePin(b1_GPIO_Port, b1_Pin, RESET);
		  HAL_GPIO_WritePin(c1_GPIO_Port, c1_Pin, RESET);
		  HAL_GPIO_WritePin(d1_GPIO_Port, d1_Pin, RESET);
		  HAL_GPIO_WritePin(e1_GPIO_Port, e1_Pin, RESET);
		  HAL_GPIO_WritePin(f1_GPIO_Port, f1_Pin, RESET);
		  HAL_GPIO_WritePin(g1_GPIO_Port, g1_Pin, RESET);
	  }
	  else if (num == 9){
		  HAL_GPIO_WritePin(a1_GPIO_Port, a1_Pin, RESET);
		  HAL_GPIO_WritePin(b1_GPIO_Port, b1_Pin, RESET);
		  HAL_GPIO_WritePin(c1_GPIO_Port, c1_Pin, RESET);
		  HAL_GPIO_WritePin(d1_GPIO_Port, d1_Pin, RESET);
		  HAL_GPIO_WritePin(e1_GPIO_Port, e1_Pin, SET);
		  HAL_GPIO_WritePin(f1_GPIO_Port, f1_Pin, RESET);
		  HAL_GPIO_WritePin(g1_GPIO_Port, g1_Pin, RESET);
	  }
}
void display7SEGleftright(int num){
	  if (num == 0){
		  HAL_GPIO_WritePin(a2_GPIO_Port, a2_Pin, RESET);
		  HAL_GPIO_WritePin(b2_GPIO_Port, b2_Pin, RESET);
		  HAL_GPIO_WritePin(c2_GPIO_Port, c2_Pin, RESET);
		  HAL_GPIO_WritePin(d2_GPIO_Port, d2_Pin, RESET);
		  HAL_GPIO_WritePin(e2_GPIO_Port, e2_Pin, RESET);
		  HAL_GPIO_WritePin(f2_GPIO_Port, f2_Pin, RESET);
		  HAL_GPIO_WritePin(g2_GPIO_Port, g2_Pin, SET);
	  }
	  else if (num == 1){
		  HAL_GPIO_WritePin(a2_GPIO_Port, a2_Pin, SET);
		  HAL_GPIO_WritePin(b2_GPIO_Port, b2_Pin, RESET);
		  HAL_GPIO_WritePin(c2_GPIO_Port, c2_Pin, RESET);
		  HAL_GPIO_WritePin(d2_GPIO_Port, d2_Pin, SET);
		  HAL_GPIO_WritePin(e2_GPIO_Port, e2_Pin, SET);
		  HAL_GPIO_WritePin(f2_GPIO_Port, f2_Pin, SET);
		  HAL_GPIO_WritePin(g2_GPIO_Port, g2_Pin, SET);
	  }
	  else if (num == 2){
		  HAL_GPIO_WritePin(a2_GPIO_Port, a2_Pin, RESET);
		  HAL_GPIO_WritePin(b2_GPIO_Port, b2_Pin, RESET);
		  HAL_GPIO_WritePin(c2_GPIO_Port, c2_Pin, SET);
		  HAL_GPIO_WritePin(d2_GPIO_Port, d2_Pin, RESET);
		  HAL_GPIO_WritePin(e2_GPIO_Port, e2_Pin, RESET);
		  HAL_GPIO_WritePin(f2_GPIO_Port, f2_Pin, SET);
		  HAL_GPIO_WritePin(g2_GPIO_Port, g2_Pin, RESET);
	  }
	  else if (num == 3){
		  HAL_GPIO_WritePin(a2_GPIO_Port, a2_Pin, RESET);
		  HAL_GPIO_WritePin(b2_GPIO_Port, b2_Pin, RESET);
		  HAL_GPIO_WritePin(c2_GPIO_Port, c2_Pin, RESET);
		  HAL_GPIO_WritePin(d2_GPIO_Port, d2_Pin, RESET);
		  HAL_GPIO_WritePin(e2_GPIO_Port, e2_Pin, SET);
		  HAL_GPIO_WritePin(f2_GPIO_Port, f2_Pin, SET);
		  HAL_GPIO_WritePin(g2_GPIO_Port, g2_Pin, RESET);
	  }
	  else if (num == 4){
		  HAL_GPIO_WritePin(a2_GPIO_Port, a2_Pin, SET);
		  HAL_GPIO_WritePin(b2_GPIO_Port, b2_Pin, RESET);
		  HAL_GPIO_WritePin(c2_GPIO_Port, c2_Pin, RESET);
		  HAL_GPIO_WritePin(d2_GPIO_Port, d2_Pin, SET);
		  HAL_GPIO_WritePin(e2_GPIO_Port, e2_Pin, SET);
		  HAL_GPIO_WritePin(f2_GPIO_Port, f2_Pin, RESET);
		  HAL_GPIO_WritePin(g2_GPIO_Port, g2_Pin, RESET);
	  }
	  else if (num == 5){
		  HAL_GPIO_WritePin(a2_GPIO_Port, a2_Pin, RESET);
		  HAL_GPIO_WritePin(b2_GPIO_Port, b2_Pin, SET);
		  HAL_GPIO_WritePin(c2_GPIO_Port, c2_Pin, RESET);
		  HAL_GPIO_WritePin(d2_GPIO_Port, d2_Pin, RESET);
		  HAL_GPIO_WritePin(e2_GPIO_Port, e2_Pin, SET);
		  HAL_GPIO_WritePin(f2_GPIO_Port, f2_Pin, RESET);
		  HAL_GPIO_WritePin(g2_GPIO_Port, g2_Pin, RESET);
	  }
	  else if (num == 6){
		  HAL_GPIO_WritePin(a2_GPIO_Port, a2_Pin, RESET);
		  HAL_GPIO_WritePin(b2_GPIO_Port, b2_Pin, SET);
		  HAL_GPIO_WritePin(c2_GPIO_Port, c2_Pin, RESET);
		  HAL_GPIO_WritePin(d2_GPIO_Port, d2_Pin, RESET);
		  HAL_GPIO_WritePin(e2_GPIO_Port, e2_Pin, RESET);
		  HAL_GPIO_WritePin(f2_GPIO_Port, f2_Pin, RESET);
		  HAL_GPIO_WritePin(g2_GPIO_Port, g2_Pin, RESET);
	  }
	  else if (num == 7){
		  HAL_GPIO_WritePin(a2_GPIO_Port, a2_Pin, RESET);
		  HAL_GPIO_WritePin(b2_GPIO_Port, b2_Pin, RESET);
		  HAL_GPIO_WritePin(c2_GPIO_Port, c2_Pin, RESET);
		  HAL_GPIO_WritePin(d2_GPIO_Port, d2_Pin, SET);
		  HAL_GPIO_WritePin(e2_GPIO_Port, e2_Pin, SET);
		  HAL_GPIO_WritePin(f2_GPIO_Port, f2_Pin, SET);
		  HAL_GPIO_WritePin(g2_GPIO_Port, g2_Pin, SET);
	  }
	  else if (num == 8){
		  HAL_GPIO_WritePin(a2_GPIO_Port, a2_Pin, RESET);
		  HAL_GPIO_WritePin(b2_GPIO_Port, b2_Pin, RESET);
		  HAL_GPIO_WritePin(c2_GPIO_Port, c2_Pin, RESET);
		  HAL_GPIO_WritePin(d2_GPIO_Port, d2_Pin, RESET);
		  HAL_GPIO_WritePin(e2_GPIO_Port, e2_Pin, RESET);
		  HAL_GPIO_WritePin(f2_GPIO_Port, f2_Pin, RESET);
		  HAL_GPIO_WritePin(g2_GPIO_Port, g2_Pin, RESET);
	  }
	  else if (num == 9){
		  HAL_GPIO_WritePin(a2_GPIO_Port, a2_Pin, RESET);
		  HAL_GPIO_WritePin(b2_GPIO_Port, b2_Pin, RESET);
		  HAL_GPIO_WritePin(c2_GPIO_Port, c2_Pin, RESET);
		  HAL_GPIO_WritePin(d2_GPIO_Port, d2_Pin, RESET);
		  HAL_GPIO_WritePin(e2_GPIO_Port, e2_Pin, SET);
		  HAL_GPIO_WritePin(f2_GPIO_Port, f2_Pin, RESET);
		  HAL_GPIO_WritePin(g2_GPIO_Port, g2_Pin, RESET);
	  }
}

void led_turnon(int led, int position){
	if(position == topbottom){
		switch(led){
		case red_led:
			HAL_GPIO_WritePin(red1_GPIO_Port, red1_Pin, RESET);
			HAL_GPIO_WritePin(yellow1_GPIO_Port, yellow1_Pin, SET);
			HAL_GPIO_WritePin(green1_GPIO_Port, green1_Pin, SET);
			break;
		case yellow_led:
			HAL_GPIO_WritePin(red1_GPIO_Port, red1_Pin, SET);
			HAL_GPIO_WritePin(yellow1_GPIO_Port, yellow1_Pin, RESET);
			HAL_GPIO_WritePin(green1_GPIO_Port, green1_Pin, SET);
			break;
		case green_led:
			HAL_GPIO_WritePin(red1_GPIO_Port, red1_Pin, SET);
			HAL_GPIO_WritePin(yellow1_GPIO_Port, yellow1_Pin, SET);
			HAL_GPIO_WritePin(green1_GPIO_Port, green1_Pin, RESET);
			break;
		default: break;
		}
	}
	else if (position == leftright){
		switch(led){
		case red_led:
			HAL_GPIO_WritePin(red2_GPIO_Port, red2_Pin, RESET);
			HAL_GPIO_WritePin(yellow2_GPIO_Port, yellow2_Pin, SET);
			HAL_GPIO_WritePin(green2_GPIO_Port, green2_Pin, SET);
			break;
		case yellow_led:
			HAL_GPIO_WritePin(red2_GPIO_Port, red2_Pin, SET);
			HAL_GPIO_WritePin(yellow2_GPIO_Port, yellow2_Pin, RESET);
			HAL_GPIO_WritePin(green2_GPIO_Port, green2_Pin, SET);
			break;
		case green_led:
			HAL_GPIO_WritePin(red2_GPIO_Port, red2_Pin, SET);
			HAL_GPIO_WritePin(yellow2_GPIO_Port, yellow2_Pin, SET);
			HAL_GPIO_WritePin(green2_GPIO_Port, green2_Pin, RESET);
			break;
		default:break;
		}
	}
}
void number_for2led(int duration, int *index_0, int *index_1){
	*index_0 = duration/10;
	*index_1 = duration%10;
}

void update_countdown(int mode){
	if (mode == red_green){
		tmp_red = red_time/100 - 1;
		tmp_green = green_time/100 -1;
	}
	else if (mode == red_yellow){
		tmp_yellow = yellow_time/100 - 1;
	}
	else if (mode == green_red){
		tmp_green = green_time/100 - 1;
		tmp_red = red_time/100 - 1;
	}
	else if (mode == yellow_red){
		tmp_yellow = yellow_time/100 - 1;
	}
}

void enablechange(){
	if (timer2_flag == 1){
		if (enable_trigger == 1) enable_trigger = 0;
		else if (enable_trigger == 0) enable_trigger = 1;
		setTimer2(50);
	}
}


void timechange(int *time1, int *time2){
	if (timer3_flag == 1){
		*time1 = *time1 - 1;
		*time2 = *time2 - 1;
		setTimer3(100);
	}
}

void timefortopbottom(int num0, int num1){
	if (enable_trigger == 0){
		HAL_GPIO_WritePin(en0_GPIO_Port, en0_Pin, RESET);
		HAL_GPIO_WritePin(en1_GPIO_Port, en1_Pin, SET);
		display7SEGtopbottom(num0);
	}
	else if (enable_trigger == 1){
		HAL_GPIO_WritePin(en0_GPIO_Port, en0_Pin, SET);
		HAL_GPIO_WritePin(en1_GPIO_Port, en1_Pin, RESET);
		display7SEGtopbottom(num1);
	}
}
void timeforleftright(int num0, int num1){
	if (enable_trigger == 0){
		HAL_GPIO_WritePin(en2_GPIO_Port, en2_Pin, RESET);
		HAL_GPIO_WritePin(en3_GPIO_Port, en3_Pin, SET);
		display7SEGleftright(num0);
	}
	else if (enable_trigger == 1){
		HAL_GPIO_WritePin(en2_GPIO_Port, en2_Pin, SET);
		HAL_GPIO_WritePin(en3_GPIO_Port, en3_Pin, RESET);
		display7SEGleftright(num1);
	}
}
void fsm_auto(){
	int index_0 = 0; // used for 7seg topbottom
	int index_1 = 0; // used for 7seg topbottom
	int index_2 = 0; // used for 7seg leftright
	int index_3 = 0; // used for 7seg leftright
	switch(status){
	case init:
		status = red_green;
		update_countdown(red_green);
		setTimer1(green_time); //time duration for 7segleg
		setTimer2(50); // time duration for enable trigger
		setTimer3(100); // time duration for reducing 1 second

		enable_trigger = 0;
		break;
	case red_green:
		led_turnon(red_led, topbottom);
		led_turnon(green_led, leftright);
		if (timer1_flag == 1){
			status = red_yellow;
			setTimer1(yellow_time);
			update_countdown(red_yellow);
		}

		number_for2led(tmp_red, &index_0, &index_1);
		number_for2led(tmp_green, &index_2, &index_3);
		timefortopbottom(index_0, index_1);
		timeforleftright(index_2, index_3);
		enablechange();
		timechange(&tmp_red, &tmp_green);


		button1_check();
		break;
	case red_yellow:
		led_turnon(red_led, topbottom);
		led_turnon(yellow_led, leftright);
		if (timer1_flag == 1){
			status = green_red;
			setTimer1(green_time);
			update_countdown(green_red);
		}

		number_for2led(tmp_red, &index_0, &index_1);
		number_for2led(tmp_yellow, &index_2, &index_3);

		timefortopbottom(index_0, index_1);
		timeforleftright(index_2, index_3);

		enablechange();
		timechange(&tmp_red, &tmp_yellow);

		button1_check();
		break;
	case green_red:
		led_turnon(green_led, topbottom);
		led_turnon(red_led, leftright);
		if (timer1_flag == 1){
			status = yellow_red;
			setTimer1(yellow_time);
			update_countdown(yellow_red);
		}

		number_for2led(tmp_green, &index_0, &index_1);
		number_for2led(tmp_red, &index_2, &index_3);
		timefortopbottom(index_0, index_1);
		timeforleftright(index_2, index_3);

		enablechange();
		timechange(&tmp_green, &tmp_red);

		button1_check();
		break;
	case yellow_red:
		led_turnon(yellow_led, topbottom);
		led_turnon(red_led, leftright);
		if (timer1_flag == 1){
			status = red_green;
			setTimer1(yellow_time);
			update_countdown(red_green);
		}

		number_for2led(tmp_yellow, &index_0, &index_1);
		number_for2led(tmp_red, &index_2, &index_3);

		timefortopbottom(index_0, index_1);
		timeforleftright(index_2, index_3);

		enablechange();
		timechange(&tmp_yellow, &tmp_red);


		button1_check();
		break;

	}
}
