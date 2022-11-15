/*
 * delay.c
 *
 * Created: 11/14/2022 1:02:19 PM
 *  Author: Ahmed
 */ 


#include "delay.h"

DELAY_ERR DELAY_init(){
	TCCR0 |= (1<<0); // no prescaler CS00 = 1, Enable/start timer
	return DELAY_OK;
}

DELAY_ERR delay_ms(unsigned long delayTime_ms){
	static unsigned long numberOfOverFlows = 0;
	delayTime_ms *= 4; // need 4 times
	
	
	while(numberOfOverFlows < delayTime_ms){
		TCNT0 = 4; // to overflow after 1ms
		while((TIFR & (1<<0)) == 0); // wait for 1ms
		numberOfOverFlows++;
		TIFR |= (1<<0); // clear TOV0 flag  by seting it to 1
	}
	// wait till TOV0 overflow flag is set
	numberOfOverFlows = 0;
	TCCR0 = 0x00; // stop timer
	return DELAY_OK;
}