/*
 * millis.c
 *
 * Created: 11/13/2022 2:58:36 PM
 *  Author: Ahmed
 */ 

#include "millis.h"

uint8_t volatile numberOfOverflows = 0;
unsigned long volatile ms = 0;

// works on timer 2 overflow
MILIS_ERR MILLIS_init(){
	TCCR2 = 0x00; // timer2 normal mode
	TCNT2 = 6; // timer2 initial value = 6(calculated)
	TCCR2 |= (1<<0); // start timer
	TIMSK |= (1 << 6); // TOIE2 = 1 enable overflow interrupt ISR
	return MILLIS_OK;
}

// return time from the beginning in milli seconds
unsigned long millis(){
	return ms;
}

// each 4 overflows = 1ms
ISR(TIMMER_OVF_INT_1){
	TCNT2 = 6; // overflows each 256-6= 250us
	numberOfOverflows++; // overflow tracker
	if(numberOfOverflows == 4){ // 4 overflows = 1ms
		numberOfOverflows = 0; // start counting from 0
		ms++; // time counter
	}
};