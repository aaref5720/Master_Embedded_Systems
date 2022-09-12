/*
 ============================================================================
 Name        : EX1_Prime_Numbers_between_two_Intervals_by_Making_User_Defiend_Function.c
 Author      : Abdelrahman Aref
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>

void getPrim(int x , int y);

int main(void) {
	int x = 0 , y = 0 ;
	printf("Enter two numbers (intervals) : ");
	fflush(stdin);  fflush(stdout);
	scanf("%d %d",&x,&y);
	getPrim(x,y);

	return EXIT_SUCCESS;
}

void getPrim(int x , int y)
{
	int i = x ;
	printf("Prime numbers between %d and %d are  ",x,y);
	for(; i < y ; i++)
	{
		if(i % 2 == 0)
			continue;
		else if(i % 3 == 0)
			continue;
		else if(i % 5 == 0)
			continue;
		else
			printf("%d ",i);
	}
}
