/*
 * global.h
 *
 *  Created on: Oct 22, 2023
 *      Author: Minh Hieu
 */

#ifndef INC_GLOBAL_H_
#define INC_GLOBAL_H_

#include "fsm_manual.h"
#include "fsm_auto.h"
#include "button.h"
#include "main.h"
#include "software_timer.h"

extern int status;


extern int red_time;
extern int yellow_time;
extern int green_time;




// status
#define init 11
#define red_green  12
#define red_yellow  13
#define green_red  14
#define yellow_red 15

#define mode_2 82
#define mode_3 83
#define mode_4 84

#endif /* INC_GLOBAL_H_ */
