/*
 ============================================================================
 Name        : C_Function_to_Take_an_Integer_Number_and_Calculate_its_Square_Root.c
 Author      : Abdelrahman Aref
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>

float sqroot(float number);

int main(void) {
	float number = 0 ; float result = 0;
	printf("Enter a number : ");
	fflush(stdin);  fflush(stdout);
	scanf("%f",&number);
	result = sqroot(number);
	printf("The square root is : %.3f",result);
	return EXIT_SUCCESS;
}

float sqroot(float number)
{
	int i = 0;
	float increment = .1 , result = 0;

    for (i = 0; i < 6; i++) {
        while (result * result <= number) {
        	result += increment;
        }

        // Loop terminates,
        // when ans * ans > number
        result = result - increment;
        increment = increment / 10;
    }

	return result ;



}
