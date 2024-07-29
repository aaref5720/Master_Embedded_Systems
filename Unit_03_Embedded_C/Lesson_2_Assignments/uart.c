#include "uart.h"

#define UATR0DR  *((volatile unsigned int* const)((unsigned int*)0x101f1000))

void Uart_Send_String(unsigned char* P_tx_string)
{
	while(*P_tx_string != '\0')
	{
		UATR0DR = (unsigned int) (*P_tx_string);
		P_tx_string++;
	}
}