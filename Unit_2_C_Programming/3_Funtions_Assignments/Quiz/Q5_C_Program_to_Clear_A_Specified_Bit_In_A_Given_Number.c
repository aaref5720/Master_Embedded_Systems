/*
 ============================================================================
 Name        : C_Program_to_Clear_A_Specified_Bit_In_A_Given_Number.c
 Author      : Abdelrahman Aref
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>

int bitClear(int num , int bitPos);

int main(void) {
	int num = 0 , bitPos = 0;
	printf("Input number = ");
	fflush(stdin);  fflush(stdout);
	scanf("%d",&num);
	printf("Bit position = ");
	fflush(stdin);  fflush(stdout);
	scanf("%d",&bitPos);
	printf("Result  = %d",bitClear(num , bitPos));
	return EXIT_SUCCESS;
}


int bitClear(int num , int bitPos)
{
	num &= ~(1<<bitPos);

	return num;
}
