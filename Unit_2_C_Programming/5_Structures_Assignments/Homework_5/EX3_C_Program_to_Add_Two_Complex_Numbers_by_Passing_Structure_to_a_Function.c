/*
 ============================================================================
 Name        : EX3_C_Program_to_Add_Two_Complex_Numbers_by_Passing_Structure_to_a_Function.c
 Author      : Abdelrahman Aref
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>


struct complex
{
	float real;
	float imaginary;
};

struct complex complexAdder(struct complex number1 , struct complex number2);
struct complex complexEntering();

int main(void) {
	struct complex number1 , number2 , sum ;

	printf("for 1st complex number : \n");
	number1 = complexEntering();

	printf("\nfor 2nd complex number : \n");
	number2 = complexEntering();

	sum = complexAdder(number1 , number2);
	printf("The sum of %.1f + %.1fi and %.1fi + %.1f = %.1f + %.1fi ",number1.real,number1.real
			,number2.real ,number2.imaginary ,sum.real ,sum.imaginary);

	return EXIT_SUCCESS;
}

struct complex complexEntering()
{
	struct complex number;
	printf("Enter real and imaginary respectively : ");
	fflush(stdin);  fflush(stdout);
	scanf("%f%f",&number.real,&number.imaginary);
	return number ;
}

struct complex complexAdder(struct complex number1 , struct complex number2)
{
	struct complex sum;
	sum.real = number1.real + number2.real;
	sum.imaginary = number1.imaginary + number2.imaginary;

	return sum;

}
