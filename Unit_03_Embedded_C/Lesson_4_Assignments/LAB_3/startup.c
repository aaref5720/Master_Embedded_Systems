/*	startup.c
	Copyright (C) Abdelrahman Aref
*/

#include <stdint.h>

static unsigned long Stack_top[256];

extern int main();

void Default_Handler()
{
	Reset_Handler();
}
void Reset_Handler();
void NMI_Handler() __attribute__((weak , alias ("Default_Handler")));
void H_Fault_Handler() __attribute__((weak , alias ("Default_Handler")));
void MM_Fault_Handler() __attribute__((weak , alias ("Default_Handler")));
void Bus_Fault() __attribute__((weak , alias ("Default_Handler")));
void Usage_Fault_Handler() __attribute__((weak , alias ("Default_Handler")));

void ( * const vectors[])() __attribute__((section(".vectors"))) = {

	(void(*)())	((unsigned long)Stack_top + sizeof(Stack_top)) ,
	&Reset_Handler ,
	&NMI_Handler ,
	&H_Fault_Handler ,
	&MM_Fault_Handler ,
	&Bus_Fault ,
	&Usage_Fault_Handler ,
};

extern unsigned int _E_text;
extern unsigned int _S_Data;
extern unsigned int _E_Data;
extern unsigned int _S_bss;
extern unsigned int _E_bss;

void Reset_Handler()
{
	unsigned int DATA_Size = (unsigned char*) &_E_Data - (unsigned char*) &_S_Data ;
	unsigned char* P_Src = (unsigned char*) &_E_text;
	unsigned char* P_Dst = (unsigned char*) &_S_Data;

	int i = 0 ;

		// Copy data section from flash to SRAM
	for (i = 0 ; i < DATA_Size ; ++i)
	{
		*((unsigned char*) P_Dst++) = *((unsigned char*) P_Src++);
	}

		// Init bss section in SRAM = 0
	unsigned int BSS_Size = (unsigned char*) &_E_bss - (unsigned char*) &_S_bss ;
	P_Dst = (unsigned char*) &_S_bss;

	for (i = 0 ; i < DATA_Size ; ++i)
	{
		*((unsigned char*) P_Dst++) = (unsigned char)0;
	}


	main();
}

