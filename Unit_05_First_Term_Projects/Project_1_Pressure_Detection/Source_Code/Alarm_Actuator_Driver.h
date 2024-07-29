#ifndef ALARM_ACTUATOR_DRIVER_
#define ALARM_ACTUATOR_DRIVER_

#include "state.h"

// Declare init function
void Alarm_Actuator_Driver_init ();

// Declare states functions
STATE_define(ALARM_ACTUATOR_DRIVER_alarm_off);
STATE_define(ALARM_ACTUATOR_DRIVER_alarm_on);
STATE_define(ALARM_ACTUATOR_DRIVER_waiting);


// Define states
enum
{
	ALARM_ACTUATOR_DRIVER_alarm_off,
	ALARM_ACTUATOR_DRIVER_alarm_on,
	ALARM_ACTUATOR_DRIVER_waiting
	
} ALARM_ACTUATOR_DRIVER_state_id;


// State pointer (pointer to function)
extern void (*ALARM_ACTUATOR_DRIVER_state)();

#endif