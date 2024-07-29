/*
 * keypad.h
 *
 * Created: 12/28/2022 10:11:43 PM
 *  Author: Abdelrahman Aref
 */ 


#ifndef KEYPAD_H_
#define KEYPAD_H_


#include "util/delay.h"
#include "GPIO.h"

// Keypad Information
#define R0 0
#define R1 1
#define R2 2
#define R3 3
#define C0 4
#define C1 5
#define C2 6
#define C3 7

#define KEYPAD_PORT PORTD
#define KEYPAD_PIN PIND
#define KEYPAD_DataDir DDRD

// Keypad Functions and global variables

void KEYPAD_INIT();
char KEYPAD_GET_KEY();

#endif /* KEYPAD_H_ */