/*
 * application.h
 *
 * Created: 11/11/2022 4:42:32 PM
 *  Author: Ahmed
 */ 


#ifndef APPLICATION_H_
#define APPLICATION_H_

#include "../MCAL/DIO/dio.h"
#include "../MCAL/TIMER/timer.h"
#include "../ECUAL/BUTTON/button.h"
#include "../ECUAL/LED/led.h"

void APP_init();
void APP_start();

#endif /* APPLICATION_H_ */