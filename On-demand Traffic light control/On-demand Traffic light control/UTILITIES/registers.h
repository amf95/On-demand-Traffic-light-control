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
/*DIO Registers						*/
/************************************/

// Port_A Registers  
#define PORTA *((volatile uint8_t*)0x3B)
#define DDRA *((volatile uint8_t*)0x3A)
#define PINA *((volatile uint8_t*)0x39)

// Port_B Registers 
#define PORTB *((volatile uint8_t*)0x38)
#define DDRB *((volatile uint8_t*)0x37)
#define PINB *((volatile uint8_t*)0x36)

// Port_C Registers 
#define PORTC *((volatile uint8_t*)0x35)
#define DDRC *((volatile uint8_t*)0x34)
#define PINC *((volatile uint8_t*)0x33)

// Port_D Registers 
#define PORTD *((volatile uint8_t*)0x32)
#define DDRD *((volatile uint8_t*)0x31)
#define PIND *((volatile uint8_t*)0x30)

/************************************************************************/
/* Timer Registers                                                      */
/************************************************************************/
#define TIMSK *((volatile uint8_t*)0x59)
// Timer0 Registers 
#define TIFR *((volatile uint8_t*)0x58)
#define TCCR0 *((volatile uint8_t*)0x53)
#define TCNT0 *((volatile uint8_t*)0x52)

// Timer2 Registers
#define TIFR *((volatile uint8_t*)0x58)
#define TCCR2 *((volatile uint8_t*)0x45)
#define TCNT2 *((volatile uint8_t*)0x44)

/************************************************************************/
/* External Interrupt Registers                                         */
/************************************************************************/
#define GICR *((volatile uint8_t*)0x5B)
#define GIFR *((volatile uint8_t*)0x5A)
#define MCUCR *((volatile uint8_t*)0x55)
#define MCUCSR *((volatile uint8_t*)0x54)

#endif /* REGISTERS_H_ */