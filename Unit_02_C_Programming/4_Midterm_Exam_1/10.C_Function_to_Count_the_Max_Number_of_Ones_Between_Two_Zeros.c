/*
 ============================================================================
 Name        : C_Function_to_Count_the_Max_Number_of_Ones_Between_Two_Zeros.c
 Author      : Abdelrahman Aref
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>

int onesNumber(int number);

int main(void) {

	int number = 0;
	printf("Enter a number : ");
	fflush(stdin);  fflush(stdout);
	scanf("%d",&number);
	printf("The number binary number : ");
	printf("  has a %d ones between two zeros ", onesNumber(number));

	return EXIT_SUCCESS;
}

int onesNumber(int number)
{
	int i = 0 , k = 1 , n = 0, counter = 0;
	int onesNumber = 0 ;
	for(i = 31 ; i >= 0 ; i--)
	{
		n = number >> i ;
		if(n & k)
		{
			printf("1");
			counter++;

		}
		else
		{
			printf("0");

			if(counter > onesNumber)
			{
				onesNumber = counter ;
				counter = 0;
			}
			else
				counter = 0;

		}

	}
	return onesNumber;
}
