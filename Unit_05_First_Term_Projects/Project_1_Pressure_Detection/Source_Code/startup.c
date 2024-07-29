/*	startup.c
	Copyright (C) Abdelrahman Aref
*/

#include "Platforms.h"

extern uint32 Stack_Top ; 
extern uint8 _E_TEXT_ ; 
extern uint8 _S_DATA_ ; 
extern uint8 _E_DATA_ ; 
extern uint8 _S_BSS_ ; 
extern uint8 _E_BSS_ ;

extern int main();

void Reset_Handler();

void Default_Handler()
{
	Reset_Handler();
}

void NMI_Handler() __attribute__((weak , alias ("Default_Handler")));
void H_Fault_Handler() __attribute__((weak , alias ("Default_Handler")));
void MM_Fault_Handler() __attribute__((weak , alias ("Default_Handler")));
void Bus_Fault() __attribute__((weak , alias ("Default_Handler")));
void Usage_Fault_Handler() __attribute__((weak , alias ("Default_Handler")));

uint32 vectors[] __attribute__((section(".vectors"))) = 
{
	(uint32) 	&Stack_Top ,
	(uint32)	&Reset_Handler ,
	(uint32)	&NMI_Handler ,
	(uint32)	&H_Fault_Handler ,
	(uint32)	&MM_Fault_Handler ,
	(uint32)	&Bus_Fault ,
	(uint32)	&Usage_Fault_Handler ,
} ;


void Reset_Handler()
{
	uint8 dataSize = (uint8*) &_E_DATA_ - (uint8*) &_S_DATA_ ;
	uint8 *P_Src = (uint8*) &_E_TEXT_ ; 
	uint8 *P_Dst = (uint8*) &_S_DATA_ ;
	uint32 i = 0 ;

	for (i = 0 ; i < dataSize ; ++i)
	 {
	 	*((uint8*) P_Dst++) = *((uint8*) P_Src++) ;	
	 } 

	uint8 bssSize = (uint8*) &_E_BSS_ - (uint8*) &_S_BSS_ ;
	P_Dst = (uint8*) &_S_BSS_ ;

	for (i = 0 ; i < bssSize ; ++i)
	{
		*((uint8*) P_Dst++) = (uint8) 0 ;
	}

	main();
}
