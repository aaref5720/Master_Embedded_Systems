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

/******************************************************************************
                                   USART
******************************************************************************/
/* USART Baud Rate Register Low */
#define UBRRL   (*(volatile unsigned char*)0x29)

/* USART Control and Status Register B */
#define UCSRB   (*(volatile unsigned char*)0x2A)

/* USART Control and Status Register A */
#define UCSRA   (*(volatile unsigned char*)0x2B)

/* USART I/O Data Register */
#define UDR     (*(volatile unsigned char*)0x2C)

/* USART Baud Rate Register High */
#define UBRRH   (*(volatile unsigned char*)0x40)

/* USART Control and Status Register C */
#define UCSRC   (*(volatile unsigned char*)0x40)

/* USART Register C */
#define URSEL        7
#define UMSEL        6
#define UPM1         5
#define UPM0         4
#define USBS         3
#define UCSZ1        2
#define UCSZ0        1
#define UCPOL        0

/* USART Status Register A  */
#define RXC          7
#define TXC          6
#define UDRE         5
#define FE           4
#define DOR          3
#define UPE          2
#define U2X          1
#define MPCM         0
/* USART Control Register B  */
#define RXCIE        7
#define TXCIE        6
#define UDRIE        5
#define RXEN         4
#define TXEN         3
#define UCSZ         2
#define UCSZ2        2
#define RXB8         1
#define TXB8         0



#endif /* ATMEGA32_H_ */