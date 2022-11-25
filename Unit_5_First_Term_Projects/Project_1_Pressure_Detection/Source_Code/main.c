#include <stdint.h>
#include <stdio.h>

#include "driver.h"
#include "state.h"

#include "Pressure_Sensor_Driver.h"
#include "Alarm_Actuator_Driver.h"
#include "Alarm_Monitor.h"
#include "Main_Algorithm.h"

void setup()
{
	//Init all Blocks
	Pressure_Sensor_Driver_init ();	
	Alarm_Actuator_Driver_init ();

	//Set STATES Pointers for each Block
	PRESSURE_SENSOR_DRIVER_state = STATE(PRESSURE_SENSOR_DRIVER_reading);
	MAIN_ALGORITHM_state = Set_Pressure_value;
	ALARM_MONITOR_state = Stop_Alarm;
	ALARM_ACTUATOR_DRIVER_state = STATE(ALARM_ACTUATOR_DRIVER_waiting);
}


int main ()
{
	GPIO_INITIALIZATION();
	setup();

	while (1)
	{
		//Call state for each Block
		PRESSURE_SENSOR_DRIVER_state();
		MAIN_ALGORITHM_state();
		ALARM_MONITOR_state();
		ALARM_ACTUATOR_DRIVER_state();
	}

	return 0;

}
