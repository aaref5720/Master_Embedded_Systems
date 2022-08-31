/*
 ============================================================================
 Name        : EX7_C_Program_To_Swap_Two_Numbers_Without_Temp_Variable.c
 Author      : Abdelrahman Aref
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>

int main(void) {
	float a = 0 , b = 0;
	printf("Enter value of a:");
	fflush(stdin);  fflush(stdout);
	scanf("%f",&a);
	printf("Enter value of b:");
	fflush(stdin);  fflush(stdout);
	scanf("%f",&b);
	a = a + b ; // 10 + 11 = 21
	b = a - b ; // 21 - 11 = 10
	a = a - b ; // 21 - 10 = 11
	printf("\nAfter swapping, value of a = %3.2f \n",a);
	printf("After swapping, value of b = %3.2f",b);

	return EXIT_SUCCESS;
}
