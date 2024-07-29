/*
 * USART.h
 *
 * Created: 3/24/2023 9:20:36 PM
 *  Author: kinge
 */ 


#ifndef USART_H_
#define USART_H_

/*******************************************************************************
                                  Includes                                   
 *******************************************************************************/
#include "Atmega32.h"
#include "Utils.h"


/*******************************************************************************
                             APIs Prototypes                                   
 *******************************************************************************/
void	 UART_INIT(void);
void	 UART_Send(uint8_t data );
uint8_t  UART_Receive(void);

void     UART_SendNumberU32(uint32_t num);
uint32_t UART_ReceiveNumberU32(void);

void   UART_Send_String(char* str);
char*  UART_Receive_String(void);

/*Clock*/
#ifndef F_CPU
#define F_CPU 8000000UL  //frequency is 16MHz
#endif


#endif /* USART_H_ */