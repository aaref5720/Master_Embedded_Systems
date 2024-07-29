#include "Alarm_Monitor.h"

// Variables
int Alarm_Timer = 60 ;

// State pointer (pointer to function)
void (*ALARM_MONITOR_state)();

void High_Pressure_Detected ()
{
	//Next STATE
	ALARM_MONITOR_state = STATE(ALARM_MONITOR_alarm_on);
}

STATE_define(ALARM_MONITOR_alarm_off)
{
	//State Name
	ALARM_MONITOR_state_id = ALARM_MONITOR_alarm_off ;
}

STATE_define(ALARM_MONITOR_alarm_on)
{
	//State Name
	ALARM_MONITOR_state_id = ALARM_MONITOR_alarm_on ;

	//State Action
	Start_Alarm ();

	// Set a timer with the required alarm period (60 Sec)
	Delay(Alarm_Timer);

	//Next STATE
	ALARM_MONITOR_state = STATE(ALARM_MONITOR_waiting);
}

STATE_define(ALARM_MONITOR_waiting)
{
	//State Name
	ALARM_MONITOR_state_id = ALARM_MONITOR_waiting ;

	//State Action
	Stop_Alarm ();

	//Next STATE
	ALARM_MONITOR_state = STATE(ALARM_MONITOR_alarm_off);
}