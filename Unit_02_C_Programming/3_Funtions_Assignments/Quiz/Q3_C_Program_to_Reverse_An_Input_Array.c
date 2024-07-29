/*
 ============================================================================
 Name        : Q3_C_Program_to_Reverse_An_Input_Array.c
 Author      : Abdelrahman Aref
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>

#define maxSize 50

void arrayEnter(int arr[],int length);
void arrayPrint(int arr[],int length);
void arrayReverse(int arr[],int length);

int main(void) {
	int arr[maxSize];
	int arrLength = 0 ;

	printf("Enter array size : ");
	fflush(stdin);  fflush(stdout);
	scanf("%d",&arrLength);


	arrayEnter(arr,arrLength);


	printf("Inputs : ");
	arrayPrint(arr,arrLength);


	arrayReverse(arr, arrLength);


	return EXIT_SUCCESS;
}

void arrayEnter(int arr[],int length)
{
	int i = 0;
	for(i = 0 ; i < length ; i++)
	{
		printf("Enter array element [%d] : ",i + 1);
		fflush(stdin);  fflush(stdout);
		scanf("%d",&arr[i]);
	}

}

void arrayPrint(int arr[],int length)
{
	int i = 0;
	for(i = 0 ; i < length ; i++)
	{
		printf("%d,",arr[i]);
	}
}

void arrayReverse(int arr[],int length)
{
	printf("\nOutputs : ");
	int i = 0;
	for(i = length - 1 ; i >= 0 ; i--)
		printf("%d,",arr[i]);
}
