/*
 ============================================================================
 Name        : C_Function_to_Return_Unique_Number_in_Array_With_One_Loop.c
 Author      : Abdelrahman Aref
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>

#define maxSize 20

void arrayEnter(int arr[],int length);
void arrayPrint(int arr[],int length);

int uniqNum(int arr[],int length);

int main(void) {
	int arr [maxSize] ;
	int arrLength = 0 ;
	int result = 0 ;

	printf("Enter array size : ");
	fflush(stdin);  fflush(stdout);
	scanf("%d",&arrLength);

	fflush(stdin);  fflush(stdout);
	arrayEnter(arr,arrLength);

	printf("Array = ");
	arrayPrint(arr,arrLength);

	result = uniqNum(arr,arrLength);
	printf("\nThe unique value is : %d",result);


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

int uniqNum(int arr[],int length)
{
	int i = 0 , value = 0;
	for(i = 0 ; i < length ; i++)
	{
		value ^= arr[i];

	}


	return value;
}
