/*
 ============================================================================
 Name        : Q7_C_Program_to_Check_If_A_Given_Number_is_Power_Of_3.c
 Author      : Abdelrahman Aref
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>

int checkFun(int num);

int main(void) {
	int num = 0 , check = 0;
	printf("Enter a number : ");
	fflush(stdin);  fflush(stdout);
	scanf("%d",&num);
	check = checkFun(num);
	printf("%d ==> %d",num,check);
	return EXIT_SUCCESS;
}


int checkFun(int num)
{
	while((num % 3 == 0) && num != 1)
	{
		num = num / 3 ;
		if(num == 3)
			return 0;
	}
	return 1;
}
