/*
 ============================================================================
 Name        : EX4_C_Program_To_Check_Whether_A_Number_Is_Positive_Or_Negative.c
 Author      : Abdelrahman aref
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>

int main(void) {
	float x = 0 ;
	printf("Enter a number : ");
	fflush(stdin);  fflush(stdout);
	scanf("%f",&x);
	if(x == 0)
	{
		printf("You entered zero.\n");
	}
	else if(x > 0)
	{
		printf("%3.2f is positive.\n",x);
	}
	else
	{
		printf("%3.2f is negative.\n",x);
	}

	return EXIT_SUCCESS;
}
