/*
 * led.c
 *
 * Created: 11/11/2022 4:39:58 PM
 *  Author: Ahmed
 */ 

#include "led.h"

DIO_ERR LED_init(uint8_t ledPin, uint8_t ledPort){
	return DIO_init(ledPin, ledPort, OUTPUT);
}

DIO_ERR LED_on(uint8_t ledPin, uint8_t ledPort){ // active HIGH
	return DIO_write(ledPin, ledPort, HIGH);
}

DIO_ERR LED_off(uint8_t ledPin, uint8_t ledPort){ // active HIGH
	return DIO_write(ledPin, ledPort, LOW);
}

DIO_ERR LED_toggle(uint8_t ledPin, uint8_t ledPort){
	return DIO_toggle(ledPin, ledPort);
}