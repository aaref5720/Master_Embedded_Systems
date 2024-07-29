#include "Alarm_Actuator_Driver.h"

// State pointer (pointer to function)
void (*ALARM_ACTUATOR_DRIVER_state)();

void Alarm_Actuator_Driver_init ()
{
	//Alarm_Actuator_Driver_init
}

void Start_Alarm ()
{
	//Next STATE
	ALARM_ACTUATOR_DRIVER_state = STATE(ALARM_ACTUATOR_DRIVER_alarm_on);
}

void Stop_Alarm ()
{
	//Next STATE
	ALARM_ACTUATOR_DRIVER_state = STATE(ALARM_ACTUATOR_DRIVER_alarm_off);
}

STATE_define(ALARM_ACTUATOR_DRIVER_alarm_off)
{
	//State Name
	ALARM_ACTUATOR_DRIVER_state_id = ALARM_ACTUATOR_DRIVER_alarm_off ;

	//State Action
	Set_Alarm_actuator(1);

	//Next STATE
	ALARM_ACTUATOR_DRIVER_state = STATE(ALARM_ACTUATOR_DRIVER_waiting);
}
STATE_define(ALARM_ACTUATOR_DRIVER_alarm_on)
{
	//State Name
	ALARM_ACTUATOR_DRIVER_state_id = ALARM_ACTUATOR_DRIVER_alarm_on ;

	//State Action
	Set_Alarm_actuator(0);

	//Next STATE
	ALARM_ACTUATOR_DRIVER_state = STATE(ALARM_ACTUATOR_DRIVER_waiting);
}
STATE_define(ALARM_ACTUATOR_DRIVER_waiting)
{
	//State Name
	ALARM_ACTUATOR_DRIVER_state_id = ALARM_ACTUATOR_DRIVER_waiting ;
}