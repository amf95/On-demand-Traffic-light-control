/*
 * test.c
 *
 * Created: 11/15/2022 10:29:25 PM
 *  Author: Ahmed
 */ 

#include "test.h"

void dio_on(){
	DIO_init(0, PORT_A, OUTPUT);
	DIO_init(5, PORT_B, OUTPUT);
	DIO_init(3, PORT_C, OUTPUT);
	DIO_init(4, PORT_D, OUTPUT);
	while(1){
		DIO_write(0, PORT_A, HIGH);
		DIO_write(5, PORT_B, HIGH);
		DIO_write(3, PORT_C, HIGH);
		DIO_write(4, PORT_D, HIGH);
	}
}

void dio_off(){
	DIO_init(0, PORT_A, OUTPUT);
	DIO_init(5, PORT_B, OUTPUT);
	DIO_init(3, PORT_C, OUTPUT);
	DIO_init(4, PORT_D, OUTPUT);
	
	while(1){
		DIO_write(0, PORT_A, LOW);
		DIO_write(5, PORT_B, LOW);
		DIO_write(3, PORT_C, LOW);
		DIO_write(4, PORT_D, LOW);
	}
}

unsigned long prevTime;
#define  waitTime 500
void test_millis_timer2(){
	sei();
	MILLIS_init();
	DIO_init(0, PORT_A, OUTPUT);
	DIO_write(0, PORT_A, HIGH);
	prevTime = millis();
	while(1){
		if(millis() >= prevTime + waitTime){
			DIO_toggle(0, PORT_A);
			prevTime = millis();
		}
	}
}

void test_button_led(){
	BUTTON_init(2, PORT_D);
	LED_init(0, PORT_A);
	static uint8_t buttonState = 0;
	
	while(1){
		BUTTON_read(2, PORT_D, &buttonState);
		if (buttonState == LOW){
			LED_on(0, PORT_A);
		}
		else{
			LED_off(0, PORT_A);
		}
	}
	 
}
