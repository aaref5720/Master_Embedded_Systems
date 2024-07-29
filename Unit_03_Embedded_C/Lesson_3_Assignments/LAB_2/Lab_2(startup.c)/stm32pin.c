#include "stm32pin.h"

void Set()
{
	APB2ENR |= IOPAEN;
	GPIOA_CRH &= 0xFF0FFFFF;
	GPIOA_CRH |= 0x00200000;
}

