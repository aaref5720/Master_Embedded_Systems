/*
 ============================================================================
 Name        : EX4_C_Program_To_Insert_An_Element_in_a_Array.c
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

	for (i = 0; i < elementsNum; i++)
	{
		scanf("%d", &arr[i]);
	}
	for(i = 0 ; i < elementsNum ; i++ )
	{
		printf("%d ",arr[i]);
	}

	int element2insert = 0 , location = 0 ;
	int narr[elementsNum + 1];
	printf("\nEnter the element to be inserted : ");
	fflush(stdin);  fflush(stdout);
	scanf("%d",&element2insert);

	printf("Enter the location : ");
	fflush(stdin);  fflush(stdout);
	scanf("%d",&location);

	for(i = 0 ; i < elementsNum ; i++ )
	{
		if(i + 1 < location)
		{
			narr[i] = arr[i];
			printf("%d ",narr[i]);
		}
		else if(i + 1 == location)
		{
			narr[i] = element2insert;
			printf("%d ",narr[i]);
			printf("%d ",arr[i]);
		}
		else
		{
			printf("%d ",arr[i]);
		}
	}

	return EXIT_SUCCESS;
}
