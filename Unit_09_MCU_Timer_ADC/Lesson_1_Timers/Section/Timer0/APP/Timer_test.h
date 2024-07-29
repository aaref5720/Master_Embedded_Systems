/*
 * Timer_test.h
 *
 * Created: 6/14/2023 3:11:03 PM
 *  Author: Abdelrahman Aref
 */ 


#ifndef TIMER_TEST_H_
#define TIMER_TEST_H_


/*******************************************************************************
                                      Includes                                   
 *******************************************************************************/
#include "Timer0.h"

/*******************************************************************************
                                  Application APIs                                 
 *******************************************************************************/
void Timer_test(void);

void Timer_OverFlow_Interrupt_Handler(void);
void Timer_CompareMatch_Interrupt_Handler(void);


#endif /* TIMER_TEST_H_ */