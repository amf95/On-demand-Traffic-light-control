/*
 * timer.h
 *
 * Created: 11/11/2022 4:41:13 PM
 *  Author: Ahmed
 */ 


#ifndef TIMER_H_
#define TIMER_H_

#include "../../UTILITIES/registers.h"

typedef enum TIMER_ERR {TIMER_OK, TIMER_INIT_ERR} TIMER_ERR;
	
// normal mode init
TIMER_ERR TIMER0_NORMAL_MODE_init();

#endif /* TIMER_H_ */