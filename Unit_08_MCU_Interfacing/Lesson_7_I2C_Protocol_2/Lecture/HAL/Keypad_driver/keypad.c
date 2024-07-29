/*
 * keypad.c
 *
 * Created: 12/28/2022 10:11:18 PM
 *  Author: Abdelrahman Aref
 */

#include "keypad.h"

unsigned int keypad_R[] = { R0 , R1 , R2 , R3};
unsigned int keypad_C[] = { C0 , C1 , C2 , C3};

void KEYPAD_INIT()
{
//	KEYPAD_DataDir &= ~((1 << R0) | (1 << R1) | (1 << R2) | (1 << R3));
//	KEYPAD_DataDir |=  ((1 << C0) | (1 << C1) | (1 << C2) | (1 << C3));
//
//	KEYPAD_PORT |= 0xFF;

	KEYPAD_PINS.GPIO_PinNumber = R0;
	KEYPAD_PINS.GPIO_MODE = GPIO_MODE_Output_pp;
	KEYPAD_PINS.GPIO_OUTPUT_SPEED = GPIO_SPEED_10MHZ;
	MCAL_GPIO_Init(KEYPAD_PORT, &KEYPAD_PINS);

	KEYPAD_PINS.GPIO_PinNumber = R1;
	KEYPAD_PINS.GPIO_MODE = GPIO_MODE_Output_pp;
	KEYPAD_PINS.GPIO_OUTPUT_SPEED = GPIO_SPEED_10MHZ;
	MCAL_GPIO_Init(KEYPAD_PORT, &KEYPAD_PINS);

	KEYPAD_PINS.GPIO_PinNumber = R2;
	KEYPAD_PINS.GPIO_MODE = GPIO_MODE_Output_pp;
	KEYPAD_PINS.GPIO_OUTPUT_SPEED = GPIO_SPEED_10MHZ;
	MCAL_GPIO_Init(KEYPAD_PORT, &KEYPAD_PINS);

	KEYPAD_PINS.GPIO_PinNumber = R3;
	KEYPAD_PINS.GPIO_MODE = GPIO_MODE_Output_pp;
	KEYPAD_PINS.GPIO_OUTPUT_SPEED = GPIO_SPEED_10MHZ;
	MCAL_GPIO_Init(KEYPAD_PORT, &KEYPAD_PINS);

	KEYPAD_PINS.GPIO_PinNumber = C0;
	KEYPAD_PINS.GPIO_MODE = GPIO_MODE_Output_pp;
	KEYPAD_PINS.GPIO_OUTPUT_SPEED = GPIO_SPEED_10MHZ;
	MCAL_GPIO_Init(KEYPAD_PORT, &KEYPAD_PINS);

	KEYPAD_PINS.GPIO_PinNumber = C1;
	KEYPAD_PINS.GPIO_MODE = GPIO_MODE_Output_pp;
	KEYPAD_PINS.GPIO_OUTPUT_SPEED = GPIO_SPEED_10MHZ;
	MCAL_GPIO_Init(KEYPAD_PORT, &KEYPAD_PINS);

	KEYPAD_PINS.GPIO_PinNumber = C2;
	KEYPAD_PINS.GPIO_MODE = GPIO_MODE_Output_pp;
	KEYPAD_PINS.GPIO_OUTPUT_SPEED = GPIO_SPEED_10MHZ;
	MCAL_GPIO_Init(KEYPAD_PORT, &KEYPAD_PINS);

	KEYPAD_PINS.GPIO_PinNumber = C3;
	KEYPAD_PINS.GPIO_MODE = GPIO_MODE_Output_pp;
	KEYPAD_PINS.GPIO_OUTPUT_SPEED = GPIO_SPEED_10MHZ;
	MCAL_GPIO_Init(KEYPAD_PORT, &KEYPAD_PINS);

}

char KEYPAD_GET_KEY()
{
	unsigned int i , j;

	for (i = 0 ; i < 4 ; i++)
	{
//		KEYPAD_PORT |=  ((1 << C0) | (1 << C1) | (1 << C2) | (1 << C3));
//		KEYPAD_PORT &=  ~(1 << keypad_C[i]);

		MCAL_GPIO_WritePin(KEYPAD_PORT, C0, HIGH);
		MCAL_GPIO_WritePin(KEYPAD_PORT, C1, HIGH);
		MCAL_GPIO_WritePin(KEYPAD_PORT, C2, HIGH);
		MCAL_GPIO_WritePin(KEYPAD_PORT, C3, HIGH);

		MCAL_GPIO_WritePin(KEYPAD_PORT, keypad_C[i] , LOW);

		for(j = 0 ; j < 4 ; j++)
		{
			if (MCAL_GPIO_ReadPin(KEYPAD_PORT, keypad_R[j]) == 0)
			{
				while(MCAL_GPIO_ReadPin(KEYPAD_PORT, keypad_R[j]) == 0);

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
