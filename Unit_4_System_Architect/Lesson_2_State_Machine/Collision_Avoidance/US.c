#include "state.h"
#include "US.h"


//Variables
int US_Distance = 0;


//STATE Pointer to Function
void (*US_STATE)();

void US_Init()
{
	printf("UltraSonic Sensor Init ... \n");
}

STATE_define(US_Busy)
{
	//State Name
	US_State_ID = US_Busy;
	
	//State Action
	US_Distance = US_Get_Random_Distance(45 , 55 , 1);
	printf("US_Busy STATE : Distance = %d\n",US_Distance);

	//Send the Signal (Distance)
	US_Set_Distance(US_Distance);

	//Next STATE
	US_STATE = STATE(US_Busy);


}

int US_Get_Random_Distance(int start , int end , int count)
{
	int i = 0;

	for(;i < count ; i++)
	{
		int Rand_Num = (rand() % (end - start + 1)) + start;
		return Rand_Num;
	}

	return 0;
}