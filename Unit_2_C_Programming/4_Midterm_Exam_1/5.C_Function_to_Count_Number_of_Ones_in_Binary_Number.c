/*
 ============================================================================
 Name        : C_Function_to_Count_Number_of_Ones_in_Binary_Number.c
 Author      : Abdelrahman Aref
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>

int onesNum(int number);

int main(void) {
	int number = 0 , result = 0;
	printf("Enter a number : ");
	fflush(stdin);  fflush(stdout);
	scanf("%d",&number);
	printf("The number binary number : ");
	result = onesNum(number);
	printf("  Contains %d of ones.", result);

	return EXIT_SUCCESS;
}


int onesNum(int number)
{
	int i = 0 , k = 1 , n = 0, counter = 0;
	//int test = 0;
	for(i = 31 ; i >= 0 ; i--)
	{
		n = number >> i ;
		if(n & k)
		{

			printf("1");
			counter++;
		}
		else
			printf("0");

	}
	return counter;
}
