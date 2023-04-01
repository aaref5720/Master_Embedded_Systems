#include "state.h"
#include "CA.h"
#include "US.h"
#include "DC.h"


void setup()
{
	//Init all Blocks
	US_Init();
	DC_Init();

	//Set STATES Pointers for each Block
	CA_STATE = STATE(CA_Waiting);
	US_STATE = STATE(US_Busy);
	DC_STATE = STATE(DC_Idle);
}

void main()
{
	volatile int d ;
	setup();
	
	while(1)
	{
		//Call state for each Block
		US_STATE();
		CA_STATE();
		DC_STATE();

		//Delay
		for(d = 0 ; d < 1000 ; d++);

	}
}