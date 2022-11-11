/*
 * registers.h
 *
 * Created: 11/11/2022 4:53:40 PM
 *  Author: Ahmed
 */ 


#ifndef REGISTERS_H_
#define REGISTERS_H_

#include "types.h"

/************************************/
/*DIO Registers*/
/************************************/

#define PORTA *((volatile uint8_t*)0x3B)
#define DDRA *((volatile uint8_t*)0x3A)
#define PINA *((volatile uint8_t*)0x39)

#define PORTB *((volatile uint8_t*)0x38)
#define DDRB *((volatile uint8_t*)0x37)
#define PINB *((volatile uint8_t*)0x36)

#define PORTC *((volatile uint8_t*)0x35)
#define DDRC *((volatile uint8_t*)0x34)
#define PINC *((volatile uint8_t*)0x33)

#define PORTD *((volatile uint8_t*)0x32)
#define DDRD *((volatile uint8_t*)0x31)
#define PIND *((volatile uint8_t*)0x30)


#define TIFR *((volatile uint8_t*)0x58)
// timer 0
#define TCCR0 *((volatile uint8_t*)0x53)
#define TCNT0 *((volatile uint8_t*)0x52)

#endif /* REGISTERS_H_ */