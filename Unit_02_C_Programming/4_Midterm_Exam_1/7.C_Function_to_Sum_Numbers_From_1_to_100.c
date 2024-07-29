/*
 ============================================================================
 Name        : C_Function_to_Sum_Numbers_From_1_to_100.c
 Author      : Abdelrahman Aref
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>

int sum(int number);

int main(void) {
	int total = 0;
	total = sum(100);
	printf("The Sum of numbers from 0 to 100 is : %d" ,total);
	return EXIT_SUCCESS;
}

int sum(int number)
{
	  if (number != 0)
	    return number + sum(number - 1);
	  else
	    return number;

}
