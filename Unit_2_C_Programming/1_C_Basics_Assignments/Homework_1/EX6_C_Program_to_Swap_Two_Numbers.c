/*
 ============================================================================
 Name        : EX6_C_Program_to_Swap_Two_Numbers.c
 Author      : Abdelrahman Aref
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>

int main(void) {
	float a = 0 , b = 0 , temp;
	printf("Enter value of a:");
	fflush(stdin);  fflush(stdout);
	scanf("%f",&a);
	printf("Enter value of b:");
	fflush(stdin);  fflush(stdout);
	scanf("%f",&b);
	temp = a;
	a = b;
	b = temp;
	printf("\nAfter swapping, value of a = %3.2f \n",a);
	printf("After swapping, value of b = %3.2f",b);

	return EXIT_SUCCESS;
}
