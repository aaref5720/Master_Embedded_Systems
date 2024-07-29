/*
 * lcd.c
 *
 * Created: 12/28/2022 6:37:56 PM
 * Author : Abdelrahman Aref
 */ 

#include <avr/io.h>
#include "lcd/lcd.h"

int main(void)
{
    /* Replace with your application code */
	LCD_INIT();
	KEYPAD_INIT();
	char val ;
    while (1) 
    {
		val = KEYPAD_GET_KEY();
		switch(val)
		{
			case '!' :
			break;
			
			case '?' :
			LCD_CLEAR_SCREEN();
			break;
			
			default:
			LCD_WRITE_CHAR(val);
		}
    }
}

