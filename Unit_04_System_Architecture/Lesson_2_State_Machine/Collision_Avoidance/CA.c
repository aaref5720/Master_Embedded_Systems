#include "state.h"
#include "CA.h"

//Variables
int CA_Speed = 0;
int CA_Distance = 0;
int CA_Threshold = 50;

//STATE Pointer to Function
void (*CA_STATE)();

void US_Set_Distance(int Distance)
{
	CA_Distance = Distance;
	(CA_Distance <= CA_Threshold) ? (CA_STATE = STATE(CA_Waiting)) : (CA_STATE = STATE(CA_Driving));
	printf("US ------ Distance = %d ------> CA \n",CA_Distance);
}

STATE_define(CA_Waiting)
{
	//State Name
	CA_State_ID = CA_Waiting;
	printf("CA_Waiting STATE : Distance = %d 	Speed = %d \n",CA_Distance,CA_Speed);

	//State Action
	CA_Speed = 0;
	DC_Set_Speed(CA_Speed);
}

STATE_define(CA_Driving)
{
	//State Name
	CA_State_ID = CA_Driving;
	printf("CA_Driving STATE : Distance = %d 	Speed = %d \n",CA_Distance,CA_Speed);

	//State Action
	CA_Speed = 30;
	DC_Set_Speed(CA_Speed);
}