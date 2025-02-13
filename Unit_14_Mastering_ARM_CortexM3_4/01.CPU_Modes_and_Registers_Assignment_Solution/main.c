/* USER CODE BEGIN Header */
/**
  ******************************************************************************
  * @file           : main.c
  * @brief          : Main program body
  ******************************************************************************
  * @attention
  *
  * <h2><center>&copy; Copyright (c) 2024 STMicroelectronics.
  * All rights reserved.</center></h2>
  *
  * This software component is licensed by ST under BSD 3-Clause license,
  * the "License"; You may not use this file except in compliance with the
  * License. You may obtain a copy of the License at:
  *                        opensource.org/licenses/BSD-3-Clause
  *
  ******************************************************************************
  */
 /*******************************************************************************
                             Includes
*******************************************************************************/
#include "STM32F103x6.h"
#include "GPIO.h"
#include "EXIT.h"


uint8_t IRQ_Flag = 0;

void EXTI9_CALLBACK(void)
{
  MCAL_GPIO_WritePin(GPIOB, GPIO_PIN_9, LOW);
}

void Clock_INIT(GPIO_t* GPIOx)
{
  if (GPIOx == GPIOA)
    RCC->APB2ENR.IOPAEN = TRUE;
  else if (GPIOx == GPIOB)
    RCC->APB2ENR.IOPBEN = TRUE;
  else if (GPIOx == GPIOC)
    RCC->APB2ENR.IOPCEN = TRUE;
  else if (GPIOx == GPIOD)
    RCC->APB2ENR.IOPDEN = TRUE;
  else if (GPIOx == GPIOE)
    RCC->APB2ENR.IOPEEN = TRUE;
  else //Enable all ports
    RCC->APB2ENR.APB2ENR;
}

void AFIO_Clock_EN()
{
  RCC->APB2ENR.AFIOEN = TRUE;
}


int main(void)
{
  Clock_INIT(GPIOA);
  Clock_INIT(GPIOB);
  AFIO_Clock_EN();

  EXTI_PinConfig_t EXTIConfig;
  EXTIConfig.EXTI_Pin = EXTI9PB9;
  EXTIConfig.Trigger_case = EXTI_Trigger_RISING;
  EXTIConfig.P_IRQ_CallBack = EXTI9_CALLBACK;
  EXTIConfig.IRQ_EN = EXTI_IRQ_ENABLE;
  MCAL_EXTI_Init(&EXTIConfig);


  while (1)
  {

  }
}
