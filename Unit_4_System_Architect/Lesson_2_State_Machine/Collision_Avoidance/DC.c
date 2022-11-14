#include "state.h"
#include "DC.h"

//Variables
int DC_Speed = 0;

//STATE Pointer to Function
void (*DC_STATE)();

void DC_Init()
{
	printf("PWM Init .... \n");
}

void DC_Set_Speed(int Speed)
{
	DC_Speed = Speed;
	DC_STATE = STATE(DC_Busy);
	printf("CA ------ Speed = %d ------> DC \n",DC_Speed);
}

STATE_define(DC_Idle)
{
	//State Name
	DC_State_ID = DC_Idle;
	
	//State Action
	//Call PWM to make speed = DC_Speed

	printf("DC_Idle State : Speed = %d \n",DC_Speed);
}

STATE_define(DC_Busy)
{
	//State Name
	DC_State_ID = DC_Busy;
	
	//State Action
	//Call PWM to make speed = DC_Speed

	printf("DC_Idle State : Speed = %d \n",DC_Speed);

	DC_STATE = STATE(DC_Idle);
}

