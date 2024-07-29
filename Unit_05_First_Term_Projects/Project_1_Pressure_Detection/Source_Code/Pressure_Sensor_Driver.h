#ifndef PRESSURE_SENSOR_DRIVER_
#define PRESSURE_SENSOR_DRIVER_

#include "state.h"


// Declare init function
void Pressure_Sensor_Driver_init ();

// Declare states functions
STATE_define(PRESSURE_SENSOR_DRIVER_reading);
STATE_define(PRESSURE_SENSOR_DRIVER_waiting);

// Define states
enum
{
	PRESSURE_SENSOR_DRIVER_reading,
	PRESSURE_SENSOR_DRIVER_waiting
} PRESSURE_SENSOR_DRIVER_state_id;


// State pointer (pointer to function)
extern void (*PRESSURE_SENSOR_DRIVER_state)();

#endif