#ifndef DC_H_
#define DC_H_

#include "state.h"

enum
{
	DC_Idle,
	DC_Busy
	
}DC_State_ID;

//Declear State functions
STATE_define(DC_Idle);
STATE_define(DC_Busy);

void DC_Init();

//STATE Pointer to Function
extern void (*DC_STATE)();

#endif