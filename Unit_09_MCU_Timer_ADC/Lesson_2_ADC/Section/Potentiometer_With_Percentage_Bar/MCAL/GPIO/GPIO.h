/*
 * GPIO.h
 *
 * Created: 1/9/2023 7:38:47 PM
 *  Author: Abdelrahman Aref
 */ 

/*******************************************************************************
                                     Includes
 *******************************************************************************/
#include "Utils.h"
#include "Atmega32.h"
#include "stdlib.h"
#include "stdint.h"

#ifndef GPIO_H_
#define GPIO_H_

//@ref 1
#define INPUT			0
#define OUTPUT			1
#define INPUT_PULLUP	3

//@ref 2
#define LOW				0
#define HIGH			1

//@ref 3
typedef enum
{
	PIN_0 ,
	PIN_1 ,
	PIN_2 ,
	PIN_3 ,
	PIN_4 ,
	PIN_5 ,
	PIN_6 ,
	PIN_7 ,
	}PINS;
	
//@ref 4
typedef enum
{
	PORT_A ,
	PORT_B ,
	PORT_C ,
	PORT_D ,
}PORTS;

/********************************************************************************************
			 All ports and pins should be selected from @ref 3 & @ref 4
*********************************************************************************************/
   
void pinMode(PORTS PORT , PINS PIN , uint8_t mode); // Mode must be set from @ref 1
void digitalWrite(PORTS PORT , PINS PIN , uint8_t value); // Value must be set from @ref 1
void digitalToggle(PORTS PORT , PINS PIN);
uint8_t digitalRead(PORTS PORT , PINS PIN);

void portMode(PORTS PORT , uint8_t mode); // Mode must be set from @ref 1
void portWrite(PORTS PORT , uint8_t value); // Value must be set from @ref 1
void portToggle(PORTS PORT);
uint8_t portRead(PORTS PORT);

// For deal with 4 most bits or 4 lowest bits
void MSB_portMode(PORTS PORT , uint8_t mode); // Mode must be set from @ref 1
void MSB_portWrite(PORTS PORT , uint8_t value); // Value must be set from @ref 1
uint8_t MSB_portRead(PORTS PORT);

void LSB_portMode(PORTS PORT , uint8_t mode); // Mode must be set from @ref 1
void LSB_portWrite(PORTS PORT , uint8_t value); // Value must be set from @ref 1
uint8_t LSB_portRead(PORTS PORT);

#endif /* GPIO_H_ */