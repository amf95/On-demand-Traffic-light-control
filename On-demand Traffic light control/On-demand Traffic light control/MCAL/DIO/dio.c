/*
 * dio.c
 *
 * Created: 11/11/2022 4:40:34 PM
 *  Author: Ahmed
 */ 


#include "dio.h"
#include "../registers.h"

void DIO_init(uint8_t pinNumber, uint8_t portNumber, uint8_t direction){
	
	switch (portNumber)
	{
		case PORT_A:
		if(direction == INPUT){
			DDRA &= ~(1<<pinNumber); // input
		}
		else if(direction == OUTPUT){
			DDRA |= (1<<pinNumber);
		}
		else{
			// return error.
		}
		break;

		case PORT_B:
		if(direction == INPUT){
			DDRB &= ~(1<<pinNumber); // input
		}
		else if(direction == OUTPUT){
			DDRB |= (1<<pinNumber);
		}
		else{
			// return error.
		}
		break;

		case PORT_C:
		if(direction == INPUT){
			DDRC &= ~(1<<pinNumber); // input
		}
		else if(direction == OUTPUT){
			DDRC |= (1<<pinNumber);
		}
		else{
			// return error wrong direction
		}
		break;

		case PORT_D:
		if(direction == INPUT){
			DDRD &= ~(1<<pinNumber); // input
		}
		else if(direction == OUTPUT){
			DDRD |= (1<<pinNumber);
		}
		else{
			// return error.
		}
		break;

		default:
		// error port not found
		break;
	}
}

void DIO_write(uint8_t pinNumber, uint8_t portNumber, uint8_t value){
	
	switch (portNumber){
		
		case PORT_A:
		if(value == LOW){
			PORTA &= ~(1<<pinNumber); // LOW
		}
		else if(value == HIGH){
			PORTA |= (1<<pinNumber); // HIGH
		}
		else{
			// return error.
		}
		break;

		case PORT_B:
		if(value == LOW){
			PORTB &= ~(1<<pinNumber); // LOW
		}
		else if(value == HIGH){
			PORTB |= (1<<pinNumber); // HIGH
		}
		else{
			// return error.
		}
		break;
		
		case PORT_C:
		if(value == LOW){
			PORTC &= ~(1<<pinNumber); // LOW
		}
		else if(value == HIGH){
			PORTC |= (1<<pinNumber); // HIGH
		}
		else{
			// return error.
		}
		break;

		case PORT_D:
		if(value == LOW){
			PORTD &= ~(1<<pinNumber); // LOW
		}
		else if(value == HIGH){
			PORTD |= (1<<pinNumber); // HIGH
		}
		else{
			// return error.
		}
		break;
		default:
		// error port not found
		break;
	}
}

void DIO_toggle(uint8_t pinNumber, uint8_t portNumber){
	uint8_t value;
	DIO_read(pinNumber, portNumber, &value);
	DIO_write(pinNumber, portNumber, !value);
}

void DIO_read(uint8_t pinNumber, uint8_t portNumber, uint8_t *value){
	switch (portNumber)
	{
		case PORT_A:
		*value = (PINA & (1<<pinNumber)) >> pinNumber;
		break;
		
		case PORT_B:
		*value = (PINB & (1<<pinNumber)) >> pinNumber;
		break;
		
		case PORT_C:
		*value = (PINC & (1<<pinNumber)) >> pinNumber;
		break;

		case PORT_D:
		*value = (PIND & (1<<pinNumber)) >> pinNumber;
		break;

		default:
		break;
	}
}