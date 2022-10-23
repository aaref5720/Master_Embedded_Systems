#include "uart.h"

unsigned char string_buffer1[100] = "learn-in-depth:Abdelrahman";
unsigned const char string_buffer2[100] = "learn-in-depth:Abdelrahman";

void main(void)
{
	Uart_Send_String(string_buffer1);
}