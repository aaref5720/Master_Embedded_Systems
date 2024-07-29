/*
 ============================================================================
 Name        : C_Function_to_Print_All_Prime_Numbers_Between_Two_Numbers.c
 Author      : Abdelrahman Aref
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>

void isPrime(int number1 , int number2);

int main(void) {
	int number1 = 0 , number2 = 0;
	printf("Enter a number1 : ");
	fflush(stdin);  fflush(stdout);
	scanf("%d",&number1);
	printf("Enter a number2 : ");
	fflush(stdin);  fflush(stdout);
	scanf("%d",&number2);
	printf("The prime numbers between %d and %d is : ",number1 ,number1);
	isPrime(number1 , number2);
	return EXIT_SUCCESS;
}

void isPrime(int number1 , int number2)
{
	int i = 0;
	for(i = number1 ; i <= number2 ; i++)
	{
		if(i != 2 && i % 2 == 0)
			continue;
		if(i != 3 && i % 3 == 0)
			continue;
		if(i != 5 && i % 5 == 0)
			continue;
		if(i != 7 && i % 7 == 0)
			continue;
		else
			printf("%d ",i);
	}
}
