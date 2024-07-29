/*
 ============================================================================
 Name        : Q2_C_Program_For_Swapping_Two_Arrays_A_&_B_With_Different_Lengths.c
 Author      : Abdelrahman Aref
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define maxSize 50

void arrayEnter(int arr[],int length);
void arrayPrint(int arr[],int length);
void arraySwap(int arr[],int arr1[]);

int main(void) {


	int arrA[maxSize],arrB[maxSize];
	int arrA_Length = 0 , arrB_Length = 0;

	printf("Enter array A size : ");
	fflush(stdin);  fflush(stdout);
	scanf("%d",&arrA_Length);

	printf("Enter array B size : ");
	fflush(stdin);  fflush(stdout);
	scanf("%d",&arrB_Length);

	printf("Enter array A : ");
	fflush(stdin);  fflush(stdout);
	arrayEnter(arrA,arrA_Length);

	printf("\nEnter array B : ");
	fflush(stdin);  fflush(stdout);
	arrayEnter(arrB,arrB_Length);


	printf("\nArray A : ");
	arrayPrint(arrA,arrA_Length);

	printf("\nArray B : ");
	arrayPrint(arrB,arrB_Length);

	arraySwap(arrA,arrB);
	printf("\n===================");

	printf("\nArray A : ");
	arrayPrint(arrA,arrB_Length);

	printf("\nArray B : ");
	arrayPrint(arrB,arrA_Length);

	return EXIT_SUCCESS;
}


void arrayEnter(int arr[],int length)
{
	int i = 0;
	for(i = 0 ; i < length ; i++)
	{
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

void arraySwap(int arrA[],int arrB[])
{
	int i = 0 ;
	int tempArr[maxSize];

	for(i = 0 ; i < maxSize ; i++)
	{

		tempArr[i] = arrA[i];
		arrA[i] = arrB[i];
		arrB[i] = tempArr[i] ;
	}


}

