/*
 * button.c
 *
 * Created: 11/11/2022 4:39:21 PM
 *  Author: Ahmed
 */ 

#include "button.h"

DIO_ERR BUTTON_init(uint8_t pinNumber, uint8_t portNumber){
	return DIO_init(pinNumber, portNumber, INPUT);
}

DIO_ERR BUTTON_read(uint8_t pinNumber, uint8_t portNumber, uint8_t *vlaue){
	return DIO_read(pinNumber, portNumber, vlaue);
}