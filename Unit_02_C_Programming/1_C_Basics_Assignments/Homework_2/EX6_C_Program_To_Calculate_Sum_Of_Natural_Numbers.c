/*
 ============================================================================
 Name        : EX5_C_Program_To_Calculate_Sum_Of_Natural_Numbers.c
 Author      : Abdelrahman aref
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>

int main(void) {
	int i = 0 , num = 0 , sum = 0;
	printf("Enter an integer : ");
	fflush(stdin);  fflush(stdout);
	scanf("%d",&num);
	for(i = 1 ; i <= num ; i++)
	{
		sum += i ;
	}
	printf("sum = %d",sum);

	return EXIT_SUCCESS;
}
