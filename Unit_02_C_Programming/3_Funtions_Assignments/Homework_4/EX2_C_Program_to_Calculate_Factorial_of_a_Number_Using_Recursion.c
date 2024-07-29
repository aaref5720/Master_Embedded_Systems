/*
 ============================================================================
 Name        : EX2_C_Program_to_Calculate_Factorial_of_a_Number_Using_Recursion.c
 Author      : Abdelrahman Aref
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>

int factorial(int x);

int main(void) {
	int x = 0 , y = 0 ;
	printf("Enter a positive integer : ");
	fflush(stdin);  fflush(stdout);
	scanf("%d",&x);
	y =  factorial(x);
	printf("Factorial of %d = %d",x,y);
	return EXIT_SUCCESS;
}


int factorial(int x)
{
	if(x == 1)
		return 1;
	else
		x *= factorial(x - 1);
	return x;
}
