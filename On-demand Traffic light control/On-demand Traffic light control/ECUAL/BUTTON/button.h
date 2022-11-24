/*
 * button.h
 *
 * Created: 11/11/2022 4:39:34 PM
 *  Author: Ahmed
 */ 


#ifndef BUTTON_H_
#define BUTTON_H_

#include "../../UTILITIES/types.h"
#include "../../MCAL/DIO/dio.h"
#include "../../MCAL/INTERRUPT/interrupt.h"

DIO_ERR BUTTON_init(uint8_t pinNumber, uint8_t portNumber);
DIO_ERR BUTTON_read(uint8_t pinNumber, uint8_t portNumber, uint8_t *value);
INT_ERR BUTTON_EXT_INT_0_init();

#endif /* BUTTON_H_ */