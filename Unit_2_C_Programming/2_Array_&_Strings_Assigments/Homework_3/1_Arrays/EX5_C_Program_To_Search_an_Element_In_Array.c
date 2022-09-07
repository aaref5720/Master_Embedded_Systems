/*
 ============================================================================
 Name        : EX5_C_Program_To_Search_an_Element_In_Array.c
 Author      : Abdelrahman Aref
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>

int main(void) {
	int elementsNum = 0 , i = 0;
	printf("Enter no of elements : ");
	fflush(stdin);  fflush(stdout);
	scanf("%d",&elementsNum);
	int arr[elementsNum - 1] ;

	for (i = 0; i < elementsNum ; i++)
	{
		scanf("%d", &arr[i]);
	}
	for(i = 0 ; i < elementsNum  ; i++ )
	{
		printf("%d ",arr[i]);
	}

	int element2search = 0;
	printf("\nEnter an element to be searched : ");
	fflush(stdin);  fflush(stdout);
	scanf("%d",&element2search);

	for(i = 0 ; i < elementsNum ; i++)
	{
		if(arr[i] == element2search)
			printf("Number found at the location : %d",i + 1);
	}

	return EXIT_SUCCESS;
}
