/*
 * ADC.h
 *
 * Created: 6/30/2023 7:33:00 PM
 *  Author: Abdelrahman Aref
 */ 


#ifndef ADC_H_
#define ADC_H_


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
	uint8_t ADC_MODE;				       // specifies ADC Mode (Single conversion mode or Free running mode)
	                                   // This parameter must be set based on @ref ADC_MODE_DEFINE
	
	uint8_t ADC_Voltage_REF;			   // Selects ADC VREF source
	                           	       // This parameter must be set based on @ref ADC_Voltage_REF_DEFINE
	
	uint8_t ADC_Result_Presentation;	   // specifies ADC Output result presentation(right adjusted or left adjusted)
	                           	       // This parameter must be set based on @ref ADC_Result_Presentation_DEFINE
	
	uint8_t ADC_PRESCALER;			   // Selects the division factor between the XTAL frequency and the input clock to ADC
	                            	   // This parameter must be set based on @ref ADC_PRESCALER_DEFINE
	
	uint8_t IRQ_Enable;				   // Enable interrupt or Disable it and use polling mechanism
	                            	   // This parameter must be set based on @ref IRQ_ENABLE_DEFINE
	
	void (*P_CallBack)(void);		   //set the C Function which will be called once IRQ Happens when Conversion completed
	
}ADCConfig_t;

/******************************************************************************
                           User Define References Macros
*******************************************************************************/
/*************************** @ref ADC_MODE_DEFINE *****************************/
#define ADC_MODE_SINGLE_CONVERSION							  (uint8_t)(0)
#define ADC_MODE_FREE_RUNNING								  (uint8_t)(1<<ADSC)

/*********************** @ref ADC_Voltage_REF_DEFINE **************************/
#define ADC_Voltage_REF_AVCC							       (uint8_t)(1<<REFS0)
#define ADC_Voltage_REF_INTERNAL						       (uint8_t)(3<<REFS0)
#define ADC_Voltage_REF_EXTERNAL_AREF				           (uint8_t)(0)

/******************** @ref ADC_Result_Presentation_DEFINE *********************/
#define ADC_Result_Presentation_RIGHT_ADJUSTED			       (uint8_t)(0)
#define ADC_Result_Presentation_LEFT_ADJUSTED			       (uint8_t)(1<<ADLAR)

/************************* @ref ADC_PRESCALER_DEFINE **************************/
#define ADC_PRESCALER_DIVUDED_BY_2							   (uint8_t)(1<<ADPS0)
#define ADC_PRESCALER_DIVUDED_BY_4							   (uint8_t)(2<<ADPS0)
#define ADC_PRESCALER_DIVUDED_BY_8							   (uint8_t)(3<<ADPS0)
#define ADC_PRESCALER_DIVUDED_BY_16						       (uint8_t)(4<<ADPS0)
#define ADC_PRESCALER_DIVUDED_BY_32							   (uint8_t)(5<<ADPS0)
#define ADC_PRESCALER_DIVUDED_BY_64							   (uint8_t)(6<<ADPS0)
#define ADC_PRESCALER_DIVUDED_BY_128						   (uint8_t)(7<<ADPS0)

/************************** @ref IRQ_ENABLE_DEFINE ****************************/
#define ADC_IRQ_ENABLE_NONE									    (uint8_t)(0)
#define ADC_IRQ_ENABLE_ADIE										(uint8_t)(1<<ADIE)


typedef enum
{
	ADC0,
	ADC1,
	ADC2,
	ADC3,
	ADC4,
	ADC5,
	ADC6,
	ADC7
}Channel_Select_t;


typedef enum
{
	Polling_ENABLE,
	Polling_DISABLE
}Polling_Mechanism_t;

/*******************************************************************************
                       APIs Supported by "MCAL ADC DRIVER"
*******************************************************************************/
void MCAL_ADC_Init  (ADCConfig_t* ADC_Config);
void MCAL_ADC_DeInit(void);

void MCAL_ADC_Start_Conversion(void);
void MCAL_ADC_Get_Result_Data(Channel_Select_t channel, uint16_t* data, Polling_Mechanism_t Polling);




#endif /* ADC_H_ */