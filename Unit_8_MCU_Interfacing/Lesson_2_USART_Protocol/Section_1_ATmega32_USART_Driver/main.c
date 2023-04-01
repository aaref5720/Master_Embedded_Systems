/*
 * ATmega32_UART_Driver.c
 *
 * Created: 3/24/2023 9:16:45 PM
 * Author : Abdelrahman Aref
 */ 

#include "HAL/lcd.h"
#include "MCAL/Inc/USART.h"

int main(void)
{
	//Initialize LCD
	LCD_INIT();
	LCD_WRITE_STRING("learn in depth");
	
	//Initialize UART
	UART_INIT();
	UART_Send_String("UART INIT");


	while (1)
	{
		uint8_t* str;
		str = UART_Receive_String();
		LCD_WRITE_STRING(str);
		
	}
}
