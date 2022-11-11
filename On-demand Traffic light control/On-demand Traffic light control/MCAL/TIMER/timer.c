/*
 * timer.c
 *
 * Created: 11/11/2022 4:41:28 PM
 *  Author: Ahmed
 */ 

#include "timer.h"

void timer0_init(){
	TCCR0 = 0x00; // normal mode
	TCNT0 = 0x00; // initial values = 0
}

void delay(){
	static numberOfOverFlows = 0;
	TCCR0 |= (1<<0); // no prescaler CS00 = 1
	while((TIFR & (1<<0)) == 0); // wait till TOV0 overflow flag is set
	TIFR |= (1<<0); // clear TOV0 flag  by seting it to 1
	TCCR0 = 0x00; // stop timer
}