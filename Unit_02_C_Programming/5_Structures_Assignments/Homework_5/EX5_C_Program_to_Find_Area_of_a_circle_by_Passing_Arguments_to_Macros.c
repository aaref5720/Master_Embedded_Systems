/*
 ============================================================================
 Name        : EX5_C_Program_to_Find_Area_of_a_circle_by_Passing_Arguments_to_Macros.c
 Author      : Abdelrahman Aref
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>

#define PI 3.14159

void circleArea();

int main(void) {
	circleArea();
	return EXIT_SUCCESS;
}


void circleArea()
{
	float radius;
	printf("Enter the radius : ");
	fflush(stdin);  fflush(stdout);
	scanf("%f",&radius);
	float area = radius * radius * PI ;
	printf("Area = %.2f",area);
}
