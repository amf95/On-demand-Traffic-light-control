/*
 * led.c
 *
 * Created: 11/11/2022 4:39:58 PM
 *  Author: Ahmed
 */ 

#include "led.h"

void LED_init(uint8_t ledPin, uint8_t ledPort){
	DIO_init(ledPin, ledPort, OUTPUT);
}

void LED_on(uint8_t ledPin, uint8_t ledPort){ // active HIGH
	DIO_write(ledPin, ledPort, HIGH);
}

void LED_off(uint8_t ledPin, uint8_t ledPort){ // active HIGH
	DIO_write(ledPin, ledPort, LOW);
}

void LED_toggle(uint8_t ledPin, uint8_t ledPort){
	DIO_toggle(ledPin, ledPort);
}