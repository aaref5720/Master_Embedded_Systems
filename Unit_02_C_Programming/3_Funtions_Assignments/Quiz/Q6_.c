/*
 ============================================================================
 Name        : Q6_.c
 Author      : Abdelrahman Aref
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>

int main(void) {
	int number = 0 , k = 0 ,x =0;
	int i = 0;
	printf("Enter number : ");
	fflush(stdin);  fflush(stdout);
	scanf("%d",&number);
	printf("%d in binary equals : ",number);
	for( i = 31 ; i > 0 ; i--)
	{
		k = number >> i ;
		if(k & 1)
			printf("1");
		else
			printf("0");
	}

	if(number & 8)
		x = 1;
	else
		x = 0;

	printf("\n4th least significant bit is : %d",x);
	return EXIT_SUCCESS;
}

