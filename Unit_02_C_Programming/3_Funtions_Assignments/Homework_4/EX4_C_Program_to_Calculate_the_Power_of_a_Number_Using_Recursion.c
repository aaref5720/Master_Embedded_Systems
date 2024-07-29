/*
 ============================================================================
 Name        : EX4_C_Program_to_Calculate_the_Power_of_a_Number_Using_Recursion.c
 Author      : Abdelrahman Aref
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>

int powerFun(int base , int power);

int main(void) {
	int base = 0 , power = 0;
	printf("Enter base number : ");
	fflush(stdin);  fflush(stdout);
	scanf("%d",&base);
	printf("Enter power number (positive only) : ");
	fflush(stdin);  fflush(stdout);
	scanf("%d",&power);
	printf("%d ^ %d = %d ",base,power, powerFun(base,power));
	return EXIT_SUCCESS;
}

int powerFun(int base , int power)
{
	if(power == 0)
		return 1 ;
	else
		base *= powerFun(base,power - 1);
	return base ;
}
