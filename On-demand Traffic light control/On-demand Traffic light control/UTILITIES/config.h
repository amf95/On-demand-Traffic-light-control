/*
 * config.h
 *
 * Created: 11/12/2022 1:34:27 PM
 *  Author: Ahmed
 */ 


#ifndef CONFIG_H_
#define CONFIG_H_

#define F_CPU 1000000UL // 1MHz

// pedestrian LEDs pins, port
#define P_GREEN_LED_PIN 0
#define P_YELLOW_LED_PIN 1
#define P_RED_LED_PIN 2

#define P_LEDS_PORT PORT_B

// cas LEDS pins, port
#define C_GREEN_LED_PIN 0
#define C_YELLOW_LED_PIN 1
#define C_RED_LED_PIN 2

#define C_LEDS_PORT PORT_A

// pedestrian BUTTON pins, port
#define P_BUTTON_PIN 2
#define P_BUTTON_PORT PORT_D

#endif /* CONFIG_H_ */