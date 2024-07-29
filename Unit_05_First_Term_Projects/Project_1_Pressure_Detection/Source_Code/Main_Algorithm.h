#ifndef MAIN_ALGORITHM_
#define MAIN_ALGORITHM_

#include "state.h"

// Declare states functions
STATE_define(MAIN_ALGORITHM_high_pressure_detect);

// Define states
enum
{
	MAIN_ALGORITHM_high_pressure_detect
} MAIN_ALGORITHM_state_id;

// State pointer (pointer to function)
extern void (*MAIN_ALGORITHM_state)();

#endif
