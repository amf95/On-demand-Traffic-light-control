/*
 * test.h
 *
 * Created: 11/15/2022 10:29:40 PM
 *  Author: Ahmed
 */ 


#ifndef TEST_H_
#define TEST_H_

#include "../MCAL/TIMER/timer.h"
#include "../ECUAL/BUTTON/button.h"
#include "../ECUAL/LED/led.h"
#include "../MCAL/INTERRUPT/interrupt.h"
#include "../UTILITIES/config.h"
#include "../UTILITIES/MILLIS/millis.h"
#include "../UTILITIES/DELAY/delay.h"
#include "../MCAL/DIO/dio.h"


void dio_on();
void dio_off();

void test_millis_timer2();

void test_button();

void test_button_led();

#endif /* TEST_H_ */