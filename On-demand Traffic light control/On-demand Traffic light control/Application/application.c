/*
 * application.c
 *
 * Created: 11/11/2022 4:42:19 PM
 *  Author: Ahmed
 */ 

#include "application.h"

// colors
enum colors {GREEN, YELLOW, RED, OFF};

// state control
//C:CAR, P:PEDESTRIAN, G:GREEN, Y:YELLOW, R:RED
enum states {START, PEDESTRIAN, NORMAL_MODE, C_GREEN, C_YELLOW, 
	C_RED, P_CR_PG, P_CG_PR, P_PG_BOTH_Y_BLINK, P_PR_BOTH_Y_BLINK};
uint8_t volatile  nextState;
uint8_t volatile currentState;
uint8_t volatile prevState;

// time control
unsigned long timeCounter;
unsigned long yellowTimeCounter;
#define SIGN_WAIT_TIME 5000 // ms, 5s 
#define YELLOW_SIGN_WAIT_TIME 250 // ms 

unsigned long volatile buttonCounter;
uint8_t  buttonState;
// BUTTON, PORTD2, FALING
ISR(EXT_INT_0){
	if(currentState == C_GREEN
	|| currentState == C_YELLOW
	|| currentState == C_RED){
		nextState = PEDESTRIAN;
		prevState = currentState;
	}
}

void APP_init(){
	
	// init Pedestrian leds
	LED_init(P_GREEN_LED_PIN, P_LEDS_PORT);
	LED_init(P_YELLOW_LED_PIN, P_LEDS_PORT);
	LED_init(P_RED_LED_PIN, P_LEDS_PORT);
	pedestriansCurretLED(OFF);
	
	// init Cars leds
	LED_init(C_GREEN_LED_PIN, C_LEDS_PORT);
	LED_init(C_YELLOW_LED_PIN, C_LEDS_PORT);
	LED_init(C_RED_LED_PIN, C_LEDS_PORT);
	carsCurretLED(OFF);
	
	// init button
	BUTTON_init(P_BUTTON_PIN, P_BUTTON_PORT);
	
	sei(); // enable global interrupt
	
	// enable external interrupter 0 PORTD2
	EXT_INT_0_FALLING_init();
	
	MILLIS_init(); // timer 2 INT
	
	nextState = START;	
}

void APP_start(){
	
	while(1){		
		switch(nextState){
			case START:
				currentState = START;
				prevState = currentState;
				nextState = NORMAL_MODE;
				break;
				
			case PEDESTRIAN:
				/*BUTTON_read(P_BUTTON_PIN, P_BUTTON_PORT, &buttonState);
				if(buttonState == LOW){
					nextState = currentState;
					continue;
				}*/
				currentState = PEDESTRIAN;
				if((prevState == C_RED)){
					nextState = P_CR_PG;
				}
				else if((prevState == C_GREEN) || (prevState == C_YELLOW)){
					nextState = P_PR_BOTH_Y_BLINK;
					carsCurretLED(OFF); // sync both leds
					pedestriansCurretLED(OFF);  // sync both leds
					yellowTimeCounter = millis();
				}
				prevState = currentState;
				timeCounter = millis();
				break;
				
			case NORMAL_MODE:
				currentState = NORMAL_MODE;
				prevState = currentState;
				nextState = C_GREEN;
				pedestriansCurretLED(OFF);
				timeCounter = millis();
				break;
				
			case C_GREEN:
				currentState = C_GREEN;
				carsCurretLED(GREEN);
				pedestriansCurretLED(RED);
				if(millis() >= timeCounter + SIGN_WAIT_TIME){
					timeCounter = millis();
					yellowTimeCounter = timeCounter;
					//if((prevState == NORMAL_MODE) || (prevState == YELLOW)){
						nextState = C_YELLOW;
						prevState = currentState;
					//}
				}
				break;
			case C_YELLOW:
				currentState = C_YELLOW;
				// Blink YELLOW code
				if(millis() >= yellowTimeCounter + YELLOW_SIGN_WAIT_TIME){
					yellowTimeCounter = millis();
					carsCurretLED(YELLOW);
				}
				if(millis() >= timeCounter + SIGN_WAIT_TIME){
					timeCounter = millis();
					if((prevState == C_GREEN)){
						nextState = C_RED;
						prevState = currentState;
					} else if((prevState == C_RED)){
						nextState = C_GREEN;
						prevState = currentState;
					}
				}
				break;
				
			case C_RED:
				currentState = C_RED;
				carsCurretLED(RED);
				pedestriansCurretLED(OFF);
				if(millis() >= timeCounter + SIGN_WAIT_TIME){
					timeCounter = millis();
					//if((prevState == NORMAL_MODE) || (prevState == YELLOW)){
					nextState = C_YELLOW;
					prevState = currentState;
					//}
				}
				break;
				
			case P_CR_PG:
				currentState = P_CR_PG;
				carsCurretLED(RED);
				pedestriansCurretLED(GREEN);
				if(millis() >= timeCounter + SIGN_WAIT_TIME){
					timeCounter = millis();
					if((prevState == PEDESTRIAN)){
						nextState = NORMAL_MODE;
						prevState = currentState;
					}
					else if((prevState == P_PR_BOTH_Y_BLINK)){
						nextState = P_PG_BOTH_Y_BLINK;
						prevState = currentState;
						yellowTimeCounter = millis();
					}
				}
				break;
				
			case P_CG_PR:
				
				break;
			case P_PG_BOTH_Y_BLINK:
				currentState = P_PG_BOTH_Y_BLINK;
				//pedestriansCurretLED(GREEN);
				// Blink YELLOW code
				if(millis() >= yellowTimeCounter + YELLOW_SIGN_WAIT_TIME){
					yellowTimeCounter = millis();
					carsCurretLED(YELLOW);
					pedestriansCurretLED(YELLOW);
				}
				LED_on(P_GREEN_LED_PIN,P_LEDS_PORT);
				if(millis() >= timeCounter + SIGN_WAIT_TIME){
					timeCounter = millis();
					//if((prevState == NORMAL_MODE) || (prevState == YELLOW)){
					nextState = NORMAL_MODE;
					prevState = currentState;
					//}
				}
				break;
				
			case P_PR_BOTH_Y_BLINK:
				currentState = P_PR_BOTH_Y_BLINK;
				//pedestriansCurretLED(RED);
				// Blink YELLOW code
				if(millis() >= yellowTimeCounter + YELLOW_SIGN_WAIT_TIME){
					yellowTimeCounter = millis();
					carsCurretLED(YELLOW);
					pedestriansCurretLED(YELLOW);
				}
				LED_on(P_RED_LED_PIN, P_LEDS_PORT);
				if(millis() >= timeCounter + SIGN_WAIT_TIME){
					timeCounter = millis();
					//if((prevState == NORMAL_MODE) || (prevState == YELLOW)){
					nextState = P_CR_PG;
					prevState = currentState;
					//}
				}
				break;
			default:
				break;
		}
		/*switch(nextState){
			case START:
				nextState = GREEN;
				currentState = START;
				prevState = currentState;
				timeCounter = millis();
				break;
			case PEDESTRIAN:
				currentState = PEDESTRIAN;
				timeCounter = millis();
				if((prevState == GREEN) || (prevState == YELLOW) || (prevState == START)){
					yellowTimeCounter = millis();
					nextState = YELLOW;
					prevState = currentState;
				}
				else if(prevState == RED){
					nextState = RED;
					prevState = currentState;
				}
				break;
			case GREEN:
				currentState = GREEN;
				carsCurretLED(GREEN);
				pedestriansCurretLED(RED);
				if(millis() >= timeCounter + SIGN_WAIT_TIME){
					timeCounter = millis();
					yellowTimeCounter = timeCounter;
					if((prevState == RED) || (prevState == START) || (prevState == YELLOW)){
						nextState = YELLOW;
						prevState = currentState;
					}					
				}
				break;
			case YELLOW:
				currentState = YELLOW;
				// Blink YELLOW code
				if(millis() >= yellowTimeCounter + YELLOW_SIGN_WAIT_TIME){
					yellowTimeCounter = millis();
					carsCurretLED(YELLOW);
					pedestriansCurretLED(YELLOW);
				}
				LED_on(P_RED_LED_PIN, P_LEDS_PORT);
				if(millis() >= timeCounter + SIGN_WAIT_TIME){
					timeCounter = millis();
					if((prevState == GREEN) || (prevState == PEDESTRIAN)){
						nextState = RED;
					}
					else if(prevState == RED){
						nextState = GREEN;
					}
					prevState = currentState;
				}
				break;
			case RED:
				currentState = RED;
				carsCurretLED(RED);
				pedestriansCurretLED(GREEN);
				if(millis() >= timeCounter + SIGN_WAIT_TIME){
					timeCounter = millis();
					if((prevState == YELLOW) || (prevState == PEDESTRIAN)){
						nextState = YELLOW;
						prevState = currentState;
					}
				}
				break;
			default:
				break;
		}*/
	}
}

void carsCurretLED(uint8_t color){
	switch(color){
		case OFF:
			LED_off(C_GREEN_LED_PIN, C_LEDS_PORT);
			LED_off(C_YELLOW_LED_PIN, C_LEDS_PORT);
			LED_off(C_RED_LED_PIN, C_LEDS_PORT);
			break;
		case GREEN:
			LED_on(C_GREEN_LED_PIN, C_LEDS_PORT);
			LED_off(C_YELLOW_LED_PIN, C_LEDS_PORT);
			LED_off(C_RED_LED_PIN, C_LEDS_PORT);
			break;
		case YELLOW:
			LED_off(C_GREEN_LED_PIN, C_LEDS_PORT);
			LED_toggle(C_YELLOW_LED_PIN, C_LEDS_PORT);
			LED_off(C_RED_LED_PIN, C_LEDS_PORT);
			break;
		case RED:
			LED_off(C_GREEN_LED_PIN, C_LEDS_PORT);
			LED_off(C_YELLOW_LED_PIN, C_LEDS_PORT);
			LED_on(C_RED_LED_PIN, C_LEDS_PORT);
			break;
		default:
			return;
			break;
	}
}


void pedestriansCurretLED(uint8_t color){
	switch(color){
		case OFF:
			LED_off(P_GREEN_LED_PIN, P_LEDS_PORT);
			LED_off(P_YELLOW_LED_PIN, P_LEDS_PORT);
			LED_off(P_RED_LED_PIN, P_LEDS_PORT);
			break;
		case GREEN:
			LED_on(P_GREEN_LED_PIN, P_LEDS_PORT);
			LED_off(P_YELLOW_LED_PIN, P_LEDS_PORT);
			LED_off(P_RED_LED_PIN, P_LEDS_PORT);
			break;
		case YELLOW:
			LED_off(P_GREEN_LED_PIN, P_LEDS_PORT);
			LED_toggle(P_YELLOW_LED_PIN, P_LEDS_PORT);
			LED_off(P_RED_LED_PIN, P_LEDS_PORT);
			break;
		case RED:
			LED_off(P_GREEN_LED_PIN, P_LEDS_PORT);
			LED_off(P_YELLOW_LED_PIN, P_LEDS_PORT);
			LED_on(P_RED_LED_PIN, P_LEDS_PORT);
			break;
		default:
		break;
	}
}
