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
#define EXTI_Base       0x40010400
#define AFIO_Base       0x40010000

//Clock Registers
#define APB2ENR			*(volatile uint32_t*)(RCC_Base + 0x18)
#define IOPAEN			(1<<2)  //For GPIOA
#define AFIOEN			(1<<0)	//For AFIO

//GPIOA Registers
#define GPIOA_CRH		*(volatile uint32_t*)(GPIOA_Base + 0x04)
#define GPIOA_ODR		*(volatile uint32_t*)(GPIOA_Base + 0x0C)
#define GPIOA_CRL   	*(volatile uint32_t*)(GPIOA_Base + 0x00)
#define PIN13			(1<<13) //For Pin 13

//AFIO Registers
#define AFIO_EXTICR1    *(volatile uint32_t*)(AFIO_Base + 0x08)

//EXIT0 Registers
#define EXTI_IMR    	*(volatile uint32_t*)(EXTI_Base + 0x00)
#define EXTI_RTSR		*(volatile uint32_t*)(EXTI_Base + 0x08)
#define EXTI_PR			*(volatile uint32_t*)(EXTI_Base + 0x14)
#define NVIC_ISER0  	*(volatile uint32_t*)(0xE000E100)

//APIs Declaration
void Clock_Init();
void GPIOA_Init();
void EXTI_Init();
void EXTI0_IRQHandler();

int main(void)
{
	Clock_Init();
	GPIOA_Init();
	EXTI_Init();

	while(1);

	return 0;
}

void Clock_Init()
{
	APB2ENR 	|= IOPAEN;
	APB2ENR 	|= AFIOEN;
}
void GPIOA_Init()
{
	GPIOA_CRH 	&= 0xFF0FFFFF;
	GPIOA_CRH 	|= 0x00200000;
	GPIOA_CRL 	|= (1<<2);
	AFIO_EXTICR1 = 0 ;
}
void EXTI_Init()
{
	EXTI_IMR 	|= (1<<0);
	EXTI_RTSR	|= (1<<0);
	NVIC_ISER0	|= (1<<6);


}
void EXTI0_IRQHandler()
{
	GPIOA_ODR 	^= PIN13 ;
	EXTI_PR 	|= (1<<0);
}
