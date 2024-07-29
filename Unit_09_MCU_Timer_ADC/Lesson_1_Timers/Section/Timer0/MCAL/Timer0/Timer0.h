/*
 * Timer0.h
 *
 * Created: 6/14/2023 2:49:23 PM
 *  Author: Abdelrahman Aref
 */ 


#ifndef TIMER0_H_
#define TIMER0_H_

/*******************************************************************************
                                  Includes                                   
 *******************************************************************************/
#include "GPIO.h"

/*******************************************************************************
                             Generic Macros                                   
 *******************************************************************************/


/*******************************************************************************
                           User Configuration structures
*******************************************************************************/
typedef struct
{
	uint8_t Timer_Mode;				// specifies Timer Mode (Normal mode or CTC)
									// This parameter must be set based on @ref TIMER0_MODE_DEFINE
	
	uint8_t Clock_Source;				// specifies Timer Clock Source (External / Internal) and PreScaler with internal clock only
									// This parameter must be set based on @ref TIMER0_CLOCK_SOURCE_DEFINE
	
	uint8_t IRQ_Enable;				// Enable or Disable IRQ
									// This parameter must be set based on @ref TIMER0_IRQ_ENABLE_DEFINE
	
	void (*P_IRQ_CallBack)(void);	//set the C Function which will be called once IRQ Happens
	
}TIMER0Config_t;

/******************************************************************************
                           User Define References Macros
*******************************************************************************/
/************************** @ref TIMER0_MODE_DEFINE ***************************/
#define TIMER0_MODE_NORMAL									(uint8_t)(0x0<<WGM01)
#define TIMER0_MODE_CTC										(uint8_t)(0x1<<WGM01)
#define TIMER0_MODE_Fast_PWM_Inverting				     	(uint8_t)(0xF<<WGM01)
#define TIMER0_MODE_Fast_PWM_Noninverting		   			(uint8_t)(0xD<<WGM01)
#define TIMER0_MODE_Phase_Correct_PWM_Set_DC      	   		(uint8_t)(0x5<<WGM01)
#define TIMER0_MODE_Phase_Correct_PWM_Set_UC      	   		(uint8_t)(0x7<<WGM01)

/********************** @ref TIMER0_CLOCK_SOURCE_DEFINE ***********************/
#define TIMER0_CLOCK_SOURCE_INTERNAL_NO_PRESCALER			(uint8_t)(0b001<<CS00)
#define TIMER0_CLOCK_SOURCE_INTERNAL_PRESCALER_8			(uint8_t)(0b010<<CS00)
#define TIMER0_CLOCK_SOURCE_INTERNAL_PRESCALER_64			(uint8_t)(0b011<<CS00)
#define TIMER0_CLOCK_SOURCE_INTERNAL_PRESCALER_256			(uint8_t)(0b100<<CS00)
#define TIMER0_CLOCK_SOURCE_INTERNAL_PRESCALER_1024			(uint8_t)(0b101<<CS00)
#define TIMER0_CLOCK_SOURCE_EXTERNAL_FALLING_EDGE			(uint8_t)(0b110<<CS00)
#define TIMER0_CLOCK_SOURCE_EXTERNAL_RISING_EDGE			(uint8_t)(0b111<<CS00)

/*********************** @ref TIMER0_IRQ_ENABLE_DEFINE ************************/
#define TIMER0_IRQ_ENABLE_NONE								((uint8_t)(0))
#define TIMER0_IRQ_ENABLE_TOIE0								((uint8_t)(1<<TOIE0))
#define TIMER0_IRQ_ENABLE_OCIE0								((uint8_t)(1<<OCIE0))


/*******************************************************************************
                   APIs Supported by "MCAL Timer0 DRIVER"
*******************************************************************************/
void MCAL_TIMER0_Init(TIMER0Config_t* TIMER0_Config);
void MCAL_TIMER0_DeInit(void);

void MCAL_TIMER0_GetCounterValue(uint8_t* TicksNumber);
void MCAL_TIMER0_SetCompareValue(uint8_t  TicksNumber);

void MCAL_PWM_DutyCycle(uint8_t Duty_Cycle);

#endif /* TIMER0_H_ */
