/*
 * PWM.c
 *
 * Created: 6/14/2023 4:02:35 PM
 *  Author: Abdelrahman Aref
 *
  *
 *******************************************************************************
                                       Includes
 *******************************************************************************/
  #include "PWM.h"
  
/*******************************************************************************
                                  Application APIs                                 
 *******************************************************************************/
void PWM_Test(void)
{
	/* Configure PIND0 as Output */
	Set_Bit(DDRB, 3);
	
	/* Set timer configuration */
	TIMER0Config_t TIMER0_Config;
	TIMER0_Config.Timer_Mode = TIMER0_MODE_Fast_PWM_Inverting;
	TIMER0_Config.Clock_Source = TIMER0_CLOCK_SOURCE_INTERNAL_PRESCALER_8;
	TIMER0_Config.IRQ_Enable = TIMER0_IRQ_ENABLE_NONE;
	TIMER0_Config.P_IRQ_CallBack = NULL;
	
	MCAL_TIMER0_Init(&TIMER0_Config);
	
	while (1)
	{
		MCAL_PWM_DutyCycle(100);
	}
}
