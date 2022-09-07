/*
 ============================================================================
 Name        : EX2_C_Program_To_Calculate_Average.c
 Author      : Abdelrahman Aref
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>

int main(void) {
	int dataNum = 0;
	int i = 0 ;
	float sum = 0;
	printf("Enter the numbers of data : ");
	fflush(stdin);  fflush(stdout);
	scanf("%d",&dataNum);
	float arrayData[dataNum];

	for(i = 0 ; i < dataNum ; i ++)
	{
		printf("%d. Enter number : ",i + 1);
		fflush(stdin);  fflush(stdout);
		scanf("%f",&arrayData[i]);
		sum += arrayData[i];
	}

	printf("Average = %.2f",(sum / dataNum));

	return EXIT_SUCCESS;
}
