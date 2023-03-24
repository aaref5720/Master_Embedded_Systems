/*
 * USART.c
 *
 * Created: 3/24/2023 9:20:53 PM
 *  Author: Abdelrahman Aref
 */ 

/*******************************************************************************
                                  Includes                                   
 *******************************************************************************/
#include "Inc/USART.h"


/*******************************************************************************
                                    APIs                                  
 *******************************************************************************/
char strin[50];

void UART_INIT(void)
{
	// transmission speed
	Reset_Bit(UCSRA,U2X);   // Normal Speed
		
	// BaudRate 9600 F_cpu = 8MHZ
	UBRRH = 0;
	UBRRL = 51;
	
	//Asynchronous mode 
	Reset_Bit(UCSRC,UMSEL);
	
	//B- 8-Bit data
	Set_Bit(UCSRC,UCSZ0);
	Set_Bit(UCSRC,UCSZ1);
	Reset_Bit(UCSRB,UCSZ2);
		
	//NO parity
	Reset_Bit(UCSRC,UPM0);
	Reset_Bit(UCSRC,UPM1);
	
	// One stop bit
	Reset_Bit(UCSRC,USBS);
	
	//enable UART  receiver.
	Set_Bit(UCSRB,RXEN);

	//enable UART  transmitter .
	Set_Bit(UCSRB,TXEN);
}

void UART_Send(uint8_t data )
{	while(!(Read_Bit(UCSRA,UDRE)));
	UDR = data;
}

uint8_t UART_Receive(void)
{
	while(!(Read_Bit(UCSRA,RXC)));
	return UDR;
}

void UART_SendNumberU32(uint32_t num)
{
	// UART_Send(num);
	// UART_Send(num>>8);
	// UART_Send(num>>16);
	// UART_Send(num>>24);

	uint8_t  *ptr = (uint8_t*)&num;
	UART_Send(ptr[0]);
	UART_Send(ptr[1]);
	UART_Send(ptr[2]);
	UART_Send(ptr[3]);
}

uint32_t UART_ReceiveNumberU32(void)
{
	//uint8_t b1= UART_Receive();
	//uint8_t b2= UART_Receive();
	//uint8_t b3= UART_Receive();
	//uint8_t b4= UART_Receive();

	//uint32_t num1=0;
	//num = b1| (uint32_t)b2<<8 | (uint32_t)b3<<16 | (uint32_t)b4<<24;

	uint32_t num;
	uint8_t *p = (uint8_t*)&num;
	p[0] = UART_Receive();
	p[1] = UART_Receive();
	p[2] = UART_Receive();
	p[3] = UART_Receive();
	return num;
}

void UART_Send_String(char* str)
{
	while (*str != '\0')
	{
		UART_Send(*str);
		str++;
	}	
}
char*  UART_Receive_String(void)
{	
	uint8_t i = 0;
	uint8_t data =UART_Receive();
	while(data !='#')
	{
		strin[i]=data;
		data =UART_Receive();
		i++;
	}
	strin[i]='\0';
	return strin;
}