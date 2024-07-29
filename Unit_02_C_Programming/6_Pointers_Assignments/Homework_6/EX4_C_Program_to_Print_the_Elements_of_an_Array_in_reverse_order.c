/*
 ============================================================================
 Name        : Program_to_Print_the_Elements_of_an_Array_in_reverse_order.c
 Author      : Abdelrahman Aref
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>

#define maxSize 15

void arrayEnter(int arr[],int length);

int main(void) {
	int arr[maxSize];
	int arrLength = 0 ;


	printf("Enter array size : ");
	fflush(stdin);  fflush(stdout);
	scanf("%d",&arrLength);

	arrayEnter(arr,arrLength);

	int* ptr = arr + arrLength - 1;
	int i = arrLength ;

	printf("\nThe elements of array in reverse order are : \n");

	for(;i >= 0 ; i--)
	{
		printf("element [%d] : %d \n",i,*ptr);
		ptr--;
	}


	return EXIT_SUCCESS;
}

void arrayEnter(int arr[],int length)
{
	int i = 0;
	printf("Enter %d number of elements in the array :\n",length);

	for(i = 0 ; i < length ; i++)
	{
		printf("Enter array element [%d] : ",i + 1);
		fflush(stdin);  fflush(stdout);
		scanf("%d",&arr[i]);
	}

}
