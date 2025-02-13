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

#if !defined(__SOFT_FP__) && defined(__ARM_FP)
#warning "FPU is not initialized, but the project is compiling for an FPU. Please initialize the FPU before use."
#endif
/*******************************************************************************
                             Includes
 *******************************************************************************/
#include "STM32F103x6.h"
#include "GPIO.h"
#include "EXIT.h"

#define TaskA_StackSize   100
#define TaskB_StackSize   100
#define MainStack_StackSize 512
#define Task_StackMargin  8
extern uint32_t _estack;

uint32_t _S_MSP =(uint32_t) &_estack;
uint32_t _E_MSP;
uint32_t _S_PSP_TaskA;
uint32_t _E_PSP_TaskA;
uint32_t _S_PSP_TaskB;
uint32_t _E_PSP_TaskB;
uint8_t  InterruptRequestFlag;
uint8_t  TaskAFlag;
uint8_t  TaskBFlag;


static inline void OS_SWITCH_ACCESS_LEVEL_TO_UNPRIVILEGED(void)
{
  __asm("nop\n\tnop\n\tnop\n\t");
  __asm("MRS r0,CONTROL \n\t"
      "ORR r0,r0,#0x1 \n\t"
      "MSR CONTROL,r0\n\t"  // Write back to CONTROL
          "ISB \n\t");            // Instruction Synchronization Barrier
  __asm("nop\n\tnop\n\tnop\n\t");
}

static inline void OS_SWITCH_ACCESS_LEVEL_TO_PRIVILEGED(void)
{
  __asm("nop\n\tnop\n\tnop\n\t");
  __asm("SVC #0x2");
  __asm("nop\n\tnop\n\tnop\n\t");
}

static inline void OS_SET_PSP(uint32_t address)
{
  __asm("nop\n\tnop\n\tnop\n\t");
  __asm("MOV r0,%[input0] \n\t"
      "MSR PSP,r0"
      :
      :[input0]"r"(address));
  __asm("nop\n\tnop\n\tnop\n\t");
}

static inline void OS_SWITCH_SP_SHADOW_PSP(void)
{
  __asm("nop\n\tnop\n\tnop\n\t");
  __asm("MRS r0,CONTROL \n\t"
      "MOV r1,#0x2    \n\t"
      "ORR r0,r0,r1   \n\t"
      "MSR CONTROL,r0\n\t"  // Write back to CONTROL
          "ISB \n\t");            // Instruction Synchronization Barrier
  __asm("nop\n\tnop\n\tnop\n\t");
}

static inline void OS_SWITCH_SP_SHADOW_MSP(void)
{
  __asm("nop\n\tnop\n\tnop\n\t");
    __asm("MRS r0, CONTROL \n\t"  // Read CONTROL register
          "BIC r0, r0, #0x2 \n\t" // Clear bit 1 to select MSP
          "MSR CONTROL, r0 \n\t"  // Write back to CONTROL
          "ISB \n\t");            // Instruction Synchronization Barrier
  __asm("nop\n\tnop\n\tnop\n\t");

}

void SVC_Handler()
{
  __asm("nop\n\tnop\n\tnop\n\t");
  __asm("MRS r0,CONTROL \n\t"
      "LSR r0,r0,#0x1 \n\t"
      "LSL r0,r0,#0x1 \n\t"
      "MSR CONTROL,r0\n\t"  // Write back to CONTROL
          "ISB \n\t");            // Instruction Synchronization Barrier
  __asm("nop\n\tnop\n\tnop\n\t");
}

int TaskA (int a, int b, int c){
  return a+b+c;
}
int TaskB (int a, int b, int c){
  return a*b*c;
}
void OS_Scheduler(){

  // 01. Memory Layout Initialization
  _E_MSP      = (_S_MSP - MainStack_StackSize);
  _S_PSP_TaskA  = (_E_MSP - Task_StackMargin);
  _E_PSP_TaskA  = (_S_PSP_TaskA - TaskA_StackSize);
  _S_PSP_TaskB  = (_E_PSP_TaskA - Task_StackMargin);
  _E_PSP_TaskB  = (_S_PSP_TaskB - TaskB_StackSize);

  // 02. Scheduling Algorithm
  while(1)
  {
    __asm("nop\n\t nop\n\t nop\n\t");
    if(TaskAFlag == 1)
    {
      //2.1. Set the PSP register to point to the task A process stack top
      OS_SET_PSP(_S_PSP_TaskA);
      //2.2. Switch the SP to shadow the PSP instead of the MSP
      OS_SWITCH_SP_SHADOW_PSP();
      //2.3. Switch the access level from privileged to unprivileged
      OS_SWITCH_ACCESS_LEVEL_TO_UNPRIVILEGED();
      //2.4. Call the Task to Execute
      TaskA(1,2,3);
      //2.3. Switch the access level from unprivileged to privileged
      OS_SWITCH_ACCESS_LEVEL_TO_PRIVILEGED();
      //2.2. Switch the SP to shadow the MSP instead of the PSP
      OS_SWITCH_SP_SHADOW_MSP();
    }
    else if (TaskBFlag == 1)
    {
      //2.1. Set the PSP register to point to the task A process stack top
      OS_SET_PSP(_S_PSP_TaskB);
      //2.2. Switch the SP to shadow the PSP instead of the MSP
      OS_SWITCH_SP_SHADOW_PSP();
      //2.3. Switch the access level from privileged to unprivileged
      OS_SWITCH_ACCESS_LEVEL_TO_UNPRIVILEGED();
      //2.4. Call the Task to Execute
      TaskB(1,2,3);
      //2.3. Switch the access level from unprivileged to privileged
      OS_SWITCH_ACCESS_LEVEL_TO_PRIVILEGED();
      //2.2. Switch the SP to shadow the MSP instead of the PSP
      OS_SWITCH_SP_SHADOW_MSP();
    }
  }
}
void EXTI9_CALLBACK(void)
{
  if(InterruptRequestFlag == 0)
  {
    TaskAFlag = 1;
    TaskBFlag = 0;
    InterruptRequestFlag = 1;
  }
  else if(InterruptRequestFlag == 1)
  {
    TaskBFlag = 1;
    TaskAFlag = 0;
    InterruptRequestFlag = 0;
  }
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


  OS_Scheduler();

  while (1)
  {

  }
}

