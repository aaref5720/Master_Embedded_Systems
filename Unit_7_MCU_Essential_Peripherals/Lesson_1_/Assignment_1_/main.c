/*
 * Task_1.c
 *
 * Created: 12/24/2022 8:36:44 PM
 * Author : Abdelrahman Aref
 */ 

#include "MEMMAP.h"
#define F_CPU 8000000UL

void Delay(int x);

int main(void)
{
    DDRD  =	0xf0;
	PORTD = 0x00;
    while (1) 
    {
		Set_Bit(PORTD,7);
		Set_Bit(PORTD,6);
		Set_Bit(PORTD,5);
		Set_Bit(PORTD,4);
		
		Delay(3);
		
		Reset_Bit(PORTD,7);
		Reset_Bit(PORTD,6);
		Reset_Bit(PORTD,5);
		Reset_Bit(PORTD,4);

    }
}

void Delay (int x)
{
	int i , j;
	for (i = 0 ; i < x ; i++)
		for (j = 0 ; j < 250 ; j++);
}

