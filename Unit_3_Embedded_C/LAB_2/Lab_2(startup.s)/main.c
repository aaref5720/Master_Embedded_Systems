#include "stm32pin.h"

volatile R_ODR* ODR_Ptr = (volatile R_ODR*)(GPIOA_Base + 0x0C);

int main()
{
	Set();
	int x;

	while(1)
	{

		ODR_Ptr->PINA.PINA13 = 1;
		for(x=0 ; x < 5000 ; x++);

		ODR_Ptr->PINA.PINA13 = 0;
		for(x=0 ; x < 5000 ; x++);

	}
}