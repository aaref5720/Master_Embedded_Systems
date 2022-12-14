/**
 ******************************************************************************
 * @file           : main.c
 * @author         : Auto-generated by STM32CubeIDE
 * @brief          : Main program body
 ******************************************************************************
 * @attention
 *
 * <h2><center>&copy; Copyright (c) 2022 STMicroelectronics.
 * All rights reserved.</center></h2>
 *
 * This software component is licensed by ST under BSD 3-Clause license,
 * the "License"; You may not use this file except in compliance with the
 * License. You may obtain a copy of the License at:
 *                        opensource.org/licenses/BSD-3-Clause
 *
 ******************************************************************************
 */

#if !defined(__SOFT_FP__) && defined(__ARM_FP)
  #warning "FPU is not initialized, but the project is compiling for an FPU. Please initialize the FPU before use."
#endif

#include "stdint.h"

//Base Addresses
#define RCC_Base 		0x40021000
#define GPIOA_Base      0x40010800
#define GPIOB_Base		0x40010C00

//Clock Registers
#define APB2ENR			*(volatile uint32_t*)(RCC_Base + 0x18)
#define IOPAEN			(1<<2)  //For GPIOA
#define IOPBEN			(1<<3)	//For GPIOB

//GPIOA Registers
#define GPIOA_CRL		*(volatile uint32_t*)(GPIOA_Base + 0x00)
#define GPIOA_CRH		*(volatile uint32_t*)(GPIOA_Base + 0x04)
#define GPIOA_IDR		*(volatile uint32_t*)(GPIOA_Base + 0x08)

#define PINA1			(1<<1)	//For Pin 1
#define PINA13			(1<<13) //For Pin 13

//GPIOB Registers
#define GPIOB_CRL		*(volatile uint32_t*)(GPIOB_Base + 0x00)
#define GPIOB_CRH		*(volatile uint32_t*)(GPIOB_Base + 0x04)
#define GPIOB_ODR		*(volatile uint32_t*)(GPIOB_Base + 0x0C)

#define PINB1			(1<<1)	//For Pin 1
#define PINB13			(1<<13) //For Pin 13

//APIs Declaration
void Clock_Init();
void GPIO_Init();
void delay(int x);


int main(void)
{
	Clock_Init();
	GPIO_Init();

	while(1)
	{
		if(((GPIOA_IDR & PINA1) >> 1) == 0) //Single Press
		{
			GPIOB_ODR ^= PINB1;
			while(((GPIOA_IDR & PINA1) >> 1) == 0);
		}

		if(((GPIOA_IDR & PINA13) >> 13) == 1) //Multi Pressing
		{
			GPIOB_ODR ^= PINB13;
		}

		delay(1);
	}

	return 0;
}

void Clock_Init()
{
	APB2ENR |= IOPAEN;
	APB2ENR |= IOPBEN;
}

void GPIO_Init()
{
	//PINA1 as a high z input
	GPIOA_CRL &= ~(0b11 << 4);
	GPIOA_CRL |=  (0b01 << 6);

	//PINA13 as a high z input
	GPIOA_CRH &= ~(0b11 << 20);
	GPIOA_CRH |=  (0b01 << 22);

	//PINB1 as a Push/Pull output
	GPIOB_CRL |=  (0b01 << 4);
	GPIOB_CRL &= ~(0b11 << 6);

	//PINB13 as a Push/Pull output
	GPIOB_CRH |=  (0b01 << 20);
	GPIOB_CRH &= ~(0b11 << 22);
}

void delay(int x)
{
	int i , j ;
	for(i = 0 ; i < x ; i++)
		for(j = 0 ; j < 250 ; j++);
}

