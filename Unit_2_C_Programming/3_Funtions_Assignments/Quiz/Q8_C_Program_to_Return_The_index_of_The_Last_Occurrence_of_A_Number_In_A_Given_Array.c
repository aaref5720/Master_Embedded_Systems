/*
 ============================================================================
 Name        : Q8_C_Program_to_Return_The_index_of_The_Last_Occurrence_of_A_Number_In_A_Given_Array.c
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
void indexFound(int arr[],int num ,int length);

int main(void) {
	int arr [maxSize] ;
	int arrLength = 0 ;
	int num = 0 ;

	printf("Enter array size : ");
	fflush(stdin);  fflush(stdout);
	scanf("%d",&arrLength);

	fflush(stdin);  fflush(stdout);
	arrayEnter(arr,arrLength);

	printf("Array = ");
	arrayPrint(arr,arrLength);

	printf("\nThe number is : ");
	fflush(stdin);  fflush(stdout);
	scanf("%d",&num);

	indexFound(arr,num,arrLength);
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

void indexFound(int arr[],int num ,int length)
{
	int i = 0 , index = 0;
	for(i = 0 ; i < length ; i++)
	{
		if(num == arr[i])
			index = i;
	}
	if(index != 0)
		printf("index = %d",index + 1);
	else
		printf("-1");

}
