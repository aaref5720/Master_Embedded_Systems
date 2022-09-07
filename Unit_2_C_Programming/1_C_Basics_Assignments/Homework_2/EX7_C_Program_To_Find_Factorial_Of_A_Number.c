/*
 ============================================================================
 Name        : EX7_C_Program_To_Find_Factorial_Of_A_Number.c
 Author      : Abdelrahman aref
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>

int main(void) {
	int i = 0 , num = 0 , fact = 1;
		printf("Enter an integer : ");
		fflush(stdin);  fflush(stdout);
		scanf("%d",&num);
		if(num < 0 )
		{
			printf("Error!!! Factorial of negative number doesn't exist \n");
					goto end;
		}
		for(i = 1 ; i <= num ; i++)
			{
				fact *= i ;
			}
			printf("Factorial = %d",fact);
			end:

	return EXIT_SUCCESS;
}
