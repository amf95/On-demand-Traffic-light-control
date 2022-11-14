/*
 * timer.c
 *
 * Created: 11/11/2022 4:41:28 PM
 *  Author: Ahmed
 */ 

#include "timer.h"

TIMER_ERR TIMER0_NORMAL_MODE_init(){
	TCCR0 = 0x00; // normal mode
	TCNT0 = 0x00; // initial value = 0
	return TIMER_OK;
}