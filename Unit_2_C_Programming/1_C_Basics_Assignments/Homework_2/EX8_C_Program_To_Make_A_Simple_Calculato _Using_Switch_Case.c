/*
 ============================================================================
 Name        : EX8_C_Program_To_Make_A_Simple_Calculato.c
 Author      : Abdelrahman aref
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>

int main(void) {
	char operator = 0;
	float x = 0, y = 0;
	printf("Enter operator either + or - or * or / :  ");
	fflush(stdin);  fflush(stdout);
	scanf("%c",&operator);
	printf("Enter two operands :  ");
	fflush(stdin);  fflush(stdout);
	scanf("%f%f",&x ,&y);

	switch(operator)
	{
	case '+':
	{
		printf("%2.1f %c %2.1f = %2.1f",x , operator , y , x + y);
		break;
	}
	case '-':
	{
		printf("%2.1f %c %2.1f = %2.1f",x , operator , y , x - y);
		break;
	}
	case '/':
	{
		printf("%2.1f %c %2.1f = %2.1f",x , operator , y , x / y);
		break;
	}
	case '*':
	{
		printf("%2.1f %c %2.1f = %2.1f",x , operator , y , x * y);
		break;
	}
	}
	return EXIT_SUCCESS;
}
