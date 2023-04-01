#ifndef STATE_H_
#define STATE_H_

#include "stdio.h"
#include "stdlib.h"

//Automatic STATE functions generator
#define STATE_define(_stateFun_)  	void ST_##_stateFun_()
#define STATE(_stateFun_)  			ST_##_stateFun_

//States Connections
void US_Set_Distance(int Distance);
void DC_Set_Speed(int Speed);

#endif