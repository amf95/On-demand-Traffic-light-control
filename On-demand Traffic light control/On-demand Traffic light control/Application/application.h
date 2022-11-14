/*
 * application.h
 *
 * Created: 11/11/2022 4:42:32 PM
 *  Author: Ahmed
 */ 


#ifndef APPLICATION_H_
#define APPLICATION_H_

#include "../MCAL/TIMER/timer.h"
#include "../ECUAL/BUTTON/button.h"
#include "../ECUAL/LED/led.h"
#include "../MCAL/INTERRUPT/interrupt.h"
#include "../UTILITIES/config.h"
#include "../UTILITIES/MILLIS/millis.h"

void APP_init();
void APP_start();

/************************************************************************/
/* Helper Functions                                                     */
/************************************************************************/
void carsCurretLED(uint8_t color);
void pedestriansCurretLED(uint8_t color);
#endif /* APPLICATION_H_ */