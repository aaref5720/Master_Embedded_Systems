/*
 * Thermistor.h
 *
 * Created: 6/30/2023 8:27:05 PM
 *  Author: Abdelrahman Aref
 */ 

#ifndef THERMISTOR_H_
#define THERMISTOR_H_

/*******************************************************************************
                                      Includes                                   
 *******************************************************************************/
#include "ADC.h"

#define USING_POLLING
//#define USING_INTERRUPT

/*******************************************************************************
                                  Application APIs                                 
 *******************************************************************************/
void ADC_PERCENTAGE_WITH_PROGRESS_BAR(void);

void ADC_Interrupt_CallBack(void);



#endif /* THERMISTOR_H_ */