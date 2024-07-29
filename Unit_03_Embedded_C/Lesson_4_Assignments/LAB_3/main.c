#include "stdint.h"

#define SYSCTL_RCGC2_R 		    *((volatile unsigned long*) (0x400FE108))
#define GPIO_PORTF_DATA_R 		*((volatile unsigned long*) (0x400253FC))
#define GPIO_PORTF_DIR_R 		*((volatile unsigned long*) (0x40025400))
#define GPIO_PORTF_DEN_R		*((volatile unsigned long*) (0x4002551C))

int main()
{
	SYSCTL_RCGC2_R 	  = 0x20;
	GPIO_PORTF_DIR_R |= (1<<3);
	GPIO_PORTF_DEN_R |= (1<<3);
	
	volatile unsigned long delay_count;

	while(1)
	{

		GPIO_PORTF_DATA_R |= (1<<3);
		for(delay_count = 0 ; delay_count < 20000 ; delay_count++);

		GPIO_PORTF_DATA_R &= ~(1<<3);
		for(delay_count = 0 ; delay_count < 20000 ; delay_count++);

	}
}