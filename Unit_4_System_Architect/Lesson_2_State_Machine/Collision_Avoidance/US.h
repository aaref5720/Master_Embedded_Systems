#ifndef US_H_
#define US_H_

#include "state.h"

enum
{
	US_Busy,
	
}US_State_ID;

//Declear State functions
STATE_define(US_Busy);

void US_Init();
int US_Get_Random_Distance(int start , int end , int count);

//STATE Pointer to Function
extern void (*US_STATE)();

#endif