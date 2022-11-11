/*
 * led.h
 *
 * Created: 11/11/2022 4:39:49 PM
 *  Author: Ahmed
 */ 


#ifndef LED_H_
#define LED_H_

#include "../../MCAL/DIO/dio.h"
#include "../../MCAL/types.h"

void LED_init(uint8_t ledPin, uint8_t ledPort);
void LED_on(uint8_t ledPin, uint8_t ledPort);
void LED_off(uint8_t ledPin, uint8_t ledPort);
void LED_toggle(uint8_t ledPin, uint8_t ledPort);

#endif /* LED_H_ */