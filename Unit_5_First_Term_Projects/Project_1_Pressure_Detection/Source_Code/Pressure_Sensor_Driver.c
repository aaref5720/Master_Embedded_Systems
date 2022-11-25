#include "Pressure_Sensor_Driver.h"

void (*PRESSURE_SENSOR_DRIVER_state)();

void Pressure_Sensor_Driver_init ()
{
	//Init Pressure Sensor driver
}

STATE_define(PRESSURE_SENSOR_DRIVER_reading)
{
	//State Name
	PRESSURE_SENSOR_DRIVER_state_id = PRESSURE_SENSOR_DRIVER_reading ;

	//State Action
	int Pval = getPressureVal() ;

	//Send the Signal (Distance)
	Set_Pressure_value(Pval) ;

	//Set pressure sensor pulling timer for 100 ms 
	Delay(100);

	//Next STATE
	PRESSURE_SENSOR_DRIVER_state = STATE(PRESSURE_SENSOR_DRIVER_waiting); 

}

STATE_define(PRESSURE_SENSOR_DRIVER_waiting)
{
	//State Name
	PRESSURE_SENSOR_DRIVER_state_id = PRESSURE_SENSOR_DRIVER_waiting ;

	//Next STATE
	PRESSURE_SENSOR_DRIVER_state = STATE(PRESSURE_SENSOR_DRIVER_reading); 
}