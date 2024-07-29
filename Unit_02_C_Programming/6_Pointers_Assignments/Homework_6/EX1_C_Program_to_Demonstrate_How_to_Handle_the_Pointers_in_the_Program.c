/*
 ============================================================================
 Name        : EX1_C_Program_to_Demonstrate_How_to_Handle_the_Pointers_in_the_Program.c
 Author      : Abdelrahman Aref
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>

int main(void) {
	int m = 29;
	int* ab = &m;
	printf("Address of m : %p\n",&m);
	printf("Value of m : %d\n",m);

	printf("\nNow ab is assigned with the address of m. \n");

	printf("Address of pointer ab : %p\n",ab);
	printf("Content of pointer ab : %d\n",*ab);

	m = 34;
	printf("\nThe value of m assigned to 34 now.\n");

	printf("Address of pointer ab : %p\n",ab);
	printf("Content of pointer ab : %d\n",*ab);

	*ab = 7;
	printf("\nThe pointer variable ab is assigned with the value 7 now.\n");

	printf("Address of m : %p\n",&m);
	printf("Value of m : %d\n",m);


	return EXIT_SUCCESS;
}
