/*
 ============================================================================
 Name        : EX1_C_Program_To_Find_Sum_Of_Two_Matrix_Of_Order_2x2.c
 Author      : Abdelrahman Aref
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>

int main(void) {
	float matrix_1 [2][2] ;
    float matrix_2[2][2] , sum[2][2] ;
	printf("Enter the element of 1st matrix\n");
	int i = 0 , j = 0;
	for(i = 0 ; i < 2 ; i++)
	{
		for(j = 0 ; j < 2 ; j++)
		{
			printf("Enter a%d%d : ",i,j);
			fflush(stdin);  fflush(stdout);
			scanf("%f",&matrix_1[i][j]);

		}
	}

	printf("Enter the element of 1st matrix\n");

	for(i = 0 ; i < 2 ; i++)
	{
		for(j = 0 ; j < 2 ; j++)
		{
			printf("Enter b%d%d : ",i,j);
			fflush(stdin);  fflush(stdout);
			scanf("%f",&matrix_2[i][j]);

		}
	}

	printf("The sum of matrices : \n");

	for(i = 0 ; i < 2 ; i++)
	{
		for(j = 0 ; j < 2 ; j++)
		{
			sum[i][j] = matrix_1[i][j] + matrix_2[i][j] ;
			printf("%.1f \t",sum[i][j]);

		}
		printf("\n");
	}


	return EXIT_SUCCESS;
}
