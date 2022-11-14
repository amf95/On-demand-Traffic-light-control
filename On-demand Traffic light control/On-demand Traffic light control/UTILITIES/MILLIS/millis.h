/*
 * millis.h
 *
 * Created: 11/13/2022 2:58:48 PM
 *  Author: Ahmed
 */ 


#ifndef MILLIS_H_
#define MILLIS_H_

#include "../registers.h"
#include "../types.h"
#include "../../MCAL/INTERRUPT/interrupt.h"

typedef enum MILIS_ERR {MILLIS_OK, MILLIST_INIT_ERR} MILIS_ERR;
	
MILIS_ERR MILLIS_init();
unsigned long millis();


#endif /* MILLIS_H_ */