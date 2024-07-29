/*
 * lcd.c
 *
 * Created: 12/28/2022 6:37:56 PM
 * Author : Abdelrahman Aref
 */ 
#include "MCAL/Inc/GPIO.h"
#include "HAL/LCD/lcd.h"
#define F_CPU 1000000UL

void wait(int t)
{
	int i , j;
	for(i = 0 ; i < t ; i++)
	for(j = 0 ; j < 255 ; j++);
}

int main(void)
{
	LCD_INIT();
	LCD_WRITE_STRING("Learn in depth");
    /* Replace with your application code */
    while (1) 
	{	
    }
}

