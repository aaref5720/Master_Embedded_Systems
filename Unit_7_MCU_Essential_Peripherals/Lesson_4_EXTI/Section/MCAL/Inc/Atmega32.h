/*
 * Atmega32.h
 *
 * Created: 1/9/2023 7:31:54 PM
 *  Author: Abdelrahman Aref
 */ 


#ifndef ATMEGA32_H_
#define ATMEGA32_H_

/*******************************************************************************
                                     Includes
*******************************************************************************/
#include "stdint.h"

/*******************************************************************************
                 General Purpose Input Output Peripheral (GPIO)
*******************************************************************************/

#define PORTA	*((uint8_t *)(0x3B))
#define DDRA	*((uint8_t *)(0x3A))
#define PINA	*((uint8_t *)(0x39))

#define PORTB	*((uint8_t *)(0x38))
#define DDRB	*((uint8_t *)(0x37))
#define PINB	*((uint8_t *)(0x36))

#define PORTC	*((uint8_t *)(0x35))
#define DDRC	*((uint8_t *)(0x34))
#define PINC	 *((uint8_t *)(0x33))

#define PORTD	 *((uint8_t *)(0x32))
#define DDRD	 *((uint8_t *)(0x31))
#define PIND	 *((uint8_t *)(0x30))

#endif /* ATMEGA32_H_ */