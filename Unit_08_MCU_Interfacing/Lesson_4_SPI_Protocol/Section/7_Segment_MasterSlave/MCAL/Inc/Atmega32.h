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

/******************************************************************************
                               GLOBAL INTERRUPT 
******************************************************************************/
#define SREG  (*(volatile unsigned char*)0x5F)
#define I     7

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

/******************************************************************************
                                  SPI
******************************************************************************/
/* SPI Control Register */
#define SPCR       (*(volatile unsigned char*)0x2D)
/* SPI Status Register */
#define SPSR       (*(volatile unsigned char*)0x2E)
/* SPI I/O Data Register */
#define SPDR       (*(volatile unsigned char*)0x2F)

/* SPI Status Register - SPSR */
#define SPIF         7
#define WCOL         6
#define SPI2X        0

/* SPI Control Register - SPCR */
#define SPIE         7
#define SPE          6
#define DORD         5
#define MSTR         4
#define CPOL         3
#define CPHA         2
#define SPR1         1
#define SPR0         0

/******************************************************************************
                              Interrupt vectors
******************************************************************************/
/* External Interrupt Request 0 */
#define INT0_vect			    __vector_1
/* External Interrupt Request 1 */
#define INT1_vect			    __vector_2
/* External Interrupt Request 2 */
#define INT2_vect			    __vector_3
/* Timer/Counter2 Compare Match */
#define TIMER2_COMP_vect		__vector_4
/* Timer/Counter2 Overflow */
#define TIMER2_OVF_vect			__vector_5
/* Timer/Counter1 Capture Event */
#define TIMER1_CAPT_vect		__vector_6
/* Timer/Counter1 Compare Match A */
#define TIMER1_COMPA_vect		__vector_7
/* Timer/Counter1 Compare Match B */
#define TIMER1_COMPB_vect		__vector_8
/* Timer/Counter1 Overflow */
#define TIMER1_OVF_vect			__vector_9
/* Timer/Counter0 Compare Match */
#define TIMER0_COMP_vect		__vector_10
/* Timer/Counter0 Overflow */
#define TIMER0_OVF_vect			__vector_11
/* Serial Transfer Complete */
#define SPI_STC_vect			__vector_12
/* USART, Rx Complete */
#define USART_RXC_vect			__vector_13
/* USART Data Register Empty */
#define USART_UDRE_vect			__vector_14
/* USART, Tx Complete */
#define USART_TXC_vect			__vector_15
/* ADC Conversion Complete */
#define ADC_vect			   __vector_16
/* EEPROM Ready */
#define EE_RDY_vect			   __vector_17
/* Analog Comparator */
#define ANA_COMP_vect			__vector_18
/* 2-wire Serial Interface */
#define TWI_vect			    __vector_19
/* Store Program Memory Ready */
#define SPM_RDY_vect			__vector_20



/*interrupt functions*/

#define sei()  __asm__ __volatile__ ("sei" ::)
#define cli()  __asm__ __volatile__ ("cli" ::)
#define reti()  __asm__ __volatile__ ("reti" ::)


#define ISR_NOBLOCK    __attribute__((interrupt))
#define ISR_NAKED      __attribute__((naked))


#define ISR(vector,...)            \
void vector (void) __attribute__ ((signal))__VA_ARGS__ ; \
void vector (void)




#endif /* ATMEGA32_H_ */