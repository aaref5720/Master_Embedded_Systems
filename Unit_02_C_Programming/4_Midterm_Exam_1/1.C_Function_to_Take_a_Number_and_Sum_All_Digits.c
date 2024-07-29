/*
 ============================================================================
 Name        : C_Function_to_Take_a_Number_and_Sum_All_Digits.c
 Author      : Abdelrahman Aref
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>

int digitsSum(int number);

int main(void) {
	int number = 0 , result = 0;
	printf("Enter a number : ");
	fflush(stdin);  fflush(stdout);
	scanf("%d",&number);
	result = digitsSum(number);
	printf("The sum of the digits is : %d ",result);
	return EXIT_SUCCESS;
}

int digitsSum(int number)
{
	int sum = 0 , i = 0 , p = 0;
	for(i = 10 ; i < number *10 ; i *= 10 )
	{
		p = ((number % i) / (i / 10))   ;
		sum += p ;
	}
	return sum ;
}
