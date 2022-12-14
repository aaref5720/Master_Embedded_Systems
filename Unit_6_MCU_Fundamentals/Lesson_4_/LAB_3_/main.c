/*
 * main.c
 *
 * Created: 12/14/2022 9:34:13 PM
 *  Author: Abdelrahmman Aref
 */ 

#include <avr/io.h>
#define F_CPU 16000000UL
#include <avr/interrupt.h>
#include <util/delay.h>

//Base Addresses
#define IO_Base  0x20


//IO Registers
#define IO_DDRB		*(unsigned volatile int*)(IO_Base + 0x17)
#define IO_DDRD		*(unsigned volatile int*)(IO_Base + 0x11)
#define IO_PORTD	*(unsigned volatile int*)(IO_Base + 0x12)

//Interrupts Registers
#define INT_MCUCR   *(unsigned volatile int*)(IO_Base + 0x35)
#define INT_MCUCSR  *(unsigned volatile int*)(IO_Base + 0x34)
#define INT_GICR	*(unsigned volatile int*)(IO_Base + 0x3B)

//APIs
void IO_Init();
void INT_Init();

int main(void)
{
	IO_Init();
	INT_Init();
    while(1)
	{
		//Turn LEDs off
			IO_PORTD &= ~(1<<5);
			IO_PORTD &= ~(1<<6);
			IO_PORTD &= ~(1<<7);
	}
}

void IO_Init()
{
	//All LEDs pins as output
	IO_DDRD |= (1<<7);
	IO_DDRD |= (1<<6);
	IO_DDRD |= (1<<5);	
}

void INT_Init()
{

	
	//Set INIT0 as logical change generates an interrupt request.
	INT_MCUCR |=  (1<<0);	
	INT_MCUCR &= ~(1<<1);

	//Set INIT1 as The rising edge.
	INT_MCUCR |=  (1<<2);
	INT_MCUCR |=  (1<<3);
	
	//Set INIT1 as The falling edge.
	INT_MCUCSR &= ~(1<<6);
	
	//Enable all interrupts
	INT_GICR |= (1<<5);
	INT_GICR |= (1<<6);
	INT_GICR |= (1<<7);	
	
	//To enable Global interrupt
	sei();
}

ISR(INT0_vect)
{
	IO_PORTD |= (1<<5);
	_delay_ms(500);
}

ISR(INT1_vect)
{
	IO_PORTD |= (1<<6);
	_delay_ms(500);
}

ISR(INT2_vect)
{
	IO_PORTD |= (1<<7);
	_delay_ms(500);
}