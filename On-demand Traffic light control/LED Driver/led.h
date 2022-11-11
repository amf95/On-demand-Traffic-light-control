

#ifndef LED_H_
#define LED_H_

#include "../DIO Driver/dio.h"
#include "../types.h"

void LED_init(uint8_t ledPin, uint8_t ledPort);
void LED_on(uint8_t ledPin, uint8_t ledPort);
void LED_off(uint8_t ledPin, uint8_t ledPort);
void LED_toggle(uint8_t ledPin, uint8_t ledPort);

#endif