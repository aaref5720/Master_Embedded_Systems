#ifndef STATE_H_
#define STATE_H_

#include "Platforms.h"

//Automatic STATE functions generator
#define STATE_define(_stateFun_)  	void ST_##_stateFun_()
#define STATE(_stateFun_)  			ST_##_stateFun_

//States Connections
void Set_Pressure_value(int Pval);
void High_Pressure_Detected ();
void Start_Alarm ();
void Stop_Alarm ();

#endif