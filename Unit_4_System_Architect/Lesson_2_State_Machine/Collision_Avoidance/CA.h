#ifndef CA_H_
#define CA_H_

#include "state.h"

enum
{
	CA_Waiting,
	CA_Driving

}CA_State_ID;

//Declear State functions
STATE_define(CA_Waiting);
STATE_define(CA_Driving);

//STATE Pointer to Function
extern void (*CA_STATE)();


#endif