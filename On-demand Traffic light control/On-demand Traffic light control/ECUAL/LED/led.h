/*
 * led.h
 *
 * Created: 11/11/2022 4:39:49 PM
 *  Author: Ahmed
 */ 


#ifndef LED_H_
#define LED_H_

#include "../../MCAL/DIO/dio.h"
#include "../../UTILITIES/types.h"

DIO_ERR LED_init(uint8_t ledPin, uint8_t ledPort);
DIO_ERR LED_on(uint8_t ledPin, uint8_t ledPort);
DIO_ERR LED_off(uint8_t ledPin, uint8_t ledPort);
DIO_ERR LED_toggle(uint8_t ledPin, uint8_t ledPort);

#endif /* LED_H_ */