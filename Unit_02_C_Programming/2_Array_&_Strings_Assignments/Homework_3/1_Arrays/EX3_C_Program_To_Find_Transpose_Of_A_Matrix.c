/*
 ============================================================================
 Name        : EX3_C_Program_To_Find_Transpose_Of_A_Matrix.c
 Author      : Abdelrahman Aref
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>

int main(void) {
	int row = 0 , column = 0 , i = 0 , j = 0;
	printf("Enter rows and columns of the matrix : ");
	fflush(stdin);  fflush(stdout);
	scanf("%d%d",&row ,&column);

	int matrix_1[row][column];

	for(i = 0 ; i < row ; i++)
	{
		for(j = 0 ; j < column ; j++)
		{
			printf("Enter a%d%d : ",i,j);
			fflush(stdin);  fflush(stdout);
			scanf("%d",&matrix_1[i][j]);

		}
	}

	printf("\nEntered matrix : \n");

	for(i = 0 ; i < row ; i++)
	{
		for(j = 0 ; j < column ; j++)
		{
			printf("%d \t",matrix_1[i][j]);

		}
		printf("\n");
	}

	printf("\nTranspose of the matrix : \n");
	int matrix_2[column][row];

	for(i = 0 ; i < column ; i++)
	{
		for(j = 0 ; j < row ; j++)
		{
			matrix_2[i][j] = matrix_1[j][i];
			printf("%d \t",matrix_2[i][j]);

		}
		printf("\n");
	}


	return EXIT_SUCCESS;
}
