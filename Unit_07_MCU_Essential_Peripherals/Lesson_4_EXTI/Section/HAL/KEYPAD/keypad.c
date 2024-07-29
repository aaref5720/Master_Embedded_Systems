/*
 * keypad.c
 *
 * Created: 12/28/2022 10:11:18 PM
 *  Author: Abdelrahman Aref
 */ 

#include "keypad.h"

unsigned int keypad_R[] = { 0, 1, 2, 3};
unsigned int keypad_C[] = { 4, 5, 6, 7};

void KEYPAD_INIT()
{
	KEYPAD_DataDir &= ~((1 << R0) | (1 << R1) | (1 << R2) | (1 << R3));
	KEYPAD_DataDir |=  ((1 << C0) | (1 << C1) | (1 << C2) | (1 << C3));
	
	KEYPAD_PORT |= 0xFF;
}

char KEYPAD_GET_KEY()
{
	unsigned int i , j;
	
	for (i = 0 ; i < 4 ; i++)
	{
		KEYPAD_PORT |=  ((1 << C0) | (1 << C1) | (1 << C2) | (1 << C3));
		KEYPAD_PORT &=  ~(1 << keypad_C[i]);
		
		for(j = 0 ; j < 4 ; j++)
		{
			if (Read_Bit(KEYPAD_PIN , keypad_R[j]) == 0)
			{
				while(Read_Bit(KEYPAD_PIN , keypad_R[j]) == 0);
				
				switch(i)
				{
					case 0 :
					if (j == 0)		return '7';
					else if(j == 1) return '4';
					else if(j == 2) return '1';
					else if(j == 3) return '?';
					break;
					
					case 1 :
					if (j == 0)		return '8';
					else if(j == 1) return '5';
					else if(j == 2) return '2';
					else if(j == 3) return '0';
					break;
					
					case 2 :
					if (j == 0)		return '9';
					else if(j == 1) return '6';
					else if(j == 2) return '3';
					else if(j == 3) return '=';
					break;
					
					case 3 :
					if (j == 0)		return '/';
					else if(j == 1) return '*';
					else if(j == 2) return '-';
					else if(j == 3) return '+';
					break;
				
					
				}
			}
		}
	}
	return '!';
	
}