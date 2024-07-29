/*
 ============================================================================
 Name        : C_Function_to_Take_an_Array_and_Revers_its_Elements.c
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
void arrayReverser(int arr[] , int length);

int main(void) {
	int arr [maxSize] ;
	int arrLength = 0 ;

	printf("Enter array size : ");
	fflush(stdin);  fflush(stdout);
	scanf("%d",&arrLength);

	fflush(stdin);  fflush(stdout);
	arrayEnter(arr,arrLength);

	printf("Array = ");
	arrayPrint(arr,arrLength);

	arrayReverser(arr , arrLength);

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

void arrayReverser(int arr[] , int length)
{
	int temp[maxSize];
	int i = 0;
	for(;i < length ; i++)
	{
		temp[i] = arr[i];
	}
	for(i = 0 ;i < length ; i++)
	{
		arr[i] = temp[length - i - 1];
	}
	printf("\nThe reversed array is : ");
	arrayPrint(arr,length);
}
