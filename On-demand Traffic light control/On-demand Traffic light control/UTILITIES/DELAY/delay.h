/*
 * delay.h
 *
 * Created: 11/14/2022 1:02:33 PM
 *  Author: Ahmed
 */ 


#ifndef DELAY_H_
#define DELAY_H_

#include "../../MCAL/TIMER/timer.h"

typedef enum DELAY_ERR {DELAY_OK, DELAY_INIT_ERR} DELAY_ERR;

// init timer 0 no prescaler
DELAY_ERR DELAY_init();
// wait till delayTime_ms passes
DELAY_ERR delay_ms(unsigned long delayTime_ms);

#endif /* DELAY_H_ */