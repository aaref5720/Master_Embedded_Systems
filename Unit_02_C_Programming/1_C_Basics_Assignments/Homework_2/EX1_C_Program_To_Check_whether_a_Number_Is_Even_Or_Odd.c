/*
 ============================================================================
 Name        : EX1_C_Program_To_Check_whether_a_Number_Is_Even_Or_Odd.c
 Author      : Abdelrahman aref
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>

int main(void) {
	int x = 0;
	printf("Enter an integer you wont to check : ");
	fflush(stdin);  fflush(stdout);
	scanf("%d",&x);
	if(x % 2 == 0)
	{
		printf("%d is even. \n",x);
	}
	else
	{
		printf("%d is odd. \n",x);
	}
	return EXIT_SUCCESS;
}
