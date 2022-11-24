/*
 * interrupt.c
 *
 * Created: 11/14/2022 1:24:38 PM
 *  Author: Ahmed
 */ 

#include "interrupt.h"

INT_ERR EXT_INT_0_FALLING_init(){
	// ISC01 = 1, ISC00 = 0, detect falling edge
	MCUCR |= (1<<1);
	//MCUCR = 0x00;
	// enable EXT_INT_0
	GICR |= (1<<6);
	return INT_OK;
}
