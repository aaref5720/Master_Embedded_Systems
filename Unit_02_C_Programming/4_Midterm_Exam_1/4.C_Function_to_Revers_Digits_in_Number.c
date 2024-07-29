/*
 ============================================================================
 Name        : C_Function_to_Revers_Digits_in_Number.c
 Author      : Abdelrahman Aref
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>

void digitsSum(int number);

int main(void) {
	int number = 0;
	printf("Enter a number : ");
	fflush(stdin);  fflush(stdout);
	scanf("%d",&number);
	printf("The number reversed digits : ");
	digitsSum(number);
	return EXIT_SUCCESS;
}

void digitsSum(int number)
{
	int i = 0 , p = 0;
	for(i = 10 ; i < number *10 ; i *= 10 )
	{
		p = ((number % i) / (i / 10))   ;
		printf("%d",p);
	}

}
