/*
 * interrupt.h
 *
 * Created: 11/12/2022 12:02:19 PM
 *  Author: Ahmed
 */ 

#ifndef INTERRUPT_H_
#define INTERRUPT_H_

#include "../../UTILITIES/registers.h"

typedef enum INT_ERR {INT_OK, INT_INIT_ERR}INT_ERR;

// interrupt vector table
#define EXT_INT_0 __vector_1
#define EXT_INT_2 __vector_2
#define EXT_INT_3 __vector_3 
#define TIMMER_OVF_INT_0 __vector_11
#define TIMMER_OVF_INT_1 __vector_5

// enable global interrupt assembly code
#define sei() __asm__ __volatile__ ("sei" ::: "memory") 
// disable global interrupt assembly code
#define cli() __asm__ __volatile__ ("cli" ::: "memory") 

// ISR template
#define ISR(INT_VECT) void INT_VECT(void) __attribute__ ((signal, used));\
void INT_VECT(void)

// init EXT_INT functions
INT_ERR EXT_INT_0_FALLING_init();

#endif /* INTERRUPT_H_ */