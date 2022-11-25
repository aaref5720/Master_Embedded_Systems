#include "Main_Algorithm.h"

// Variables
int Main_Algorithm_pVal = 0;
int Threshold = 20;

// State pointer (pointer to function)
void (*MAIN_ALGORITHM_state)();

void Set_Pressure_value(int Pval)
{
	Main_Algorithm_pVal = Pval ;
	
	//Next STATE
	MAIN_ALGORITHM_state = STATE(MAIN_ALGORITHM_high_pressure_detect);

}

STATE_define(MAIN_ALGORITHM_high_pressure_detect)
{
	//State Name
	MAIN_ALGORITHM_state_id = MAIN_ALGORITHM_high_pressure_detect;

	//State Action
	if(Main_Algorithm_pVal > Threshold) { High_Pressure_Detected (); }
}