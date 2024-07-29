/*
 * Task_1.c
 *
 * Created: 12/24/2022 8:36:44 PM
 * Author : Abdelrahman Aref
 */ 

#include "MEMMAP.h"
#include <util/delay.h>
#define F_CPU 8000000UL

int main(void)
{
    DDRA  =	0xff;
	DDRC  =	0x00;
	PORTC = 0x01;
    while (1) 
    {
		if(Read_Bit(PINC,0) == 0)
		{
			//LEDs ON
			Set_Bit(PORTA,0);
			_delay_ms(200);
			Set_Bit(PORTA,1);
			_delay_ms(200);
			Set_Bit(PORTA,2);
			_delay_ms(200);
			Set_Bit(PORTA,3);
			_delay_ms(200);
			Set_Bit(PORTA,4);
			_delay_ms(200);
			Set_Bit(PORTA,5);
			_delay_ms(200);
			Set_Bit(PORTA,6);
			_delay_ms(200);
			Set_Bit(PORTA,7);
			_delay_ms(200);
			Set_Bit(PORTA,8);
			_delay_ms(200);
			
			//LEDs OFF
			Reset_Bit(PORTA,8);
			_delay_ms(200);
			Reset_Bit(PORTA,7);
			_delay_ms(200);
			Reset_Bit(PORTA,6);
			_delay_ms(200);
			Reset_Bit(PORTA,5);
			_delay_ms(200);
			Reset_Bit(PORTA,4);
			_delay_ms(200);
			Reset_Bit(PORTA,3);
			_delay_ms(200);
			Reset_Bit(PORTA,2);
			_delay_ms(200);
			Reset_Bit(PORTA,1);
			_delay_ms(200);
			Reset_Bit(PORTA,0);
			_delay_ms(200);
		}

    }
}

