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

static inline void ACCESS_LEVEL_SWITCH_TO_UNPRIVILEGED(void){
  __asm("nop\n\tnop\n\tnop\n\t");
  __asm("MRS r0,CONTROL \n\t"
      "ORR r0,r0,#0x1 \n\t"
      "MSR CONTROL,r0");
  __asm("nop\n\tnop\n\tnop\n\t");
}

static inline void ACCESS_LEVEL_SWITCH_TO_PRIVILEGED(void){
  __asm("nop\n\tnop\n\tnop\n\t");
  __asm("SVC #0x2");
  __asm("nop\n\tnop\n\tnop\n\t");
}

void SVC_Handler()
{
  __asm("nop\n\tnop\n\tnop\n\t");
  __asm("MRS r0,CONTROL \n\t"
      "LSR r0,r0,#0x1 \n\t"
      "LSL r0,r0,#0x1 \n\t"
      "MSR CONTROL,r0");
  __asm("nop\n\tnop\n\tnop\n\t");
}



int main(void)
{

  ACCESS_LEVEL_SWITCH_TO_UNPRIVILEGED();
  ACCESS_LEVEL_SWITCH_TO_PRIVILEGED();
  volatile int x = 0;

  while (1)
  {

  }
}

