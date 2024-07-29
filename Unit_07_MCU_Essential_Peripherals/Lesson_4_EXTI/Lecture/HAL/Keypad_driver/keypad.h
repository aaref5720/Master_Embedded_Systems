/*
 * keypad.h
 *
 * Created: 12/28/2022 10:11:43 PM
 *  Author: Abdelrahman Aref
 */


#ifndef KEYPAD_H_
#define KEYPAD_H_

#define F_CPU 1000000UL

#include "GPIO.h"

// Keypad Information
#define R0 GPIO_PIN_0
#define R1 GPIO_PIN_1
#define R2 GPIO_PIN_3
#define R3 GPIO_PIN_4
#define C0 GPIO_PIN_5
#define C1 GPIO_PIN_6
#define C2 GPIO_PIN_7
#define C3 GPIO_PIN_8

#define KEYPAD_PORT GPIOB

GPIO_PinConfig_t KEYPAD_PINS;

// Keypad Functions and global variables

void KEYPAD_INIT();
char KEYPAD_GET_KEY();

#endif /* KEYPAD_H_ */
