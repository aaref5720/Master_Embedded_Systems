/*
 ============================================================================
 Name        : EX6_C_Finding_The_Size_of_Both_Union_and_Structure.c
 Author      : Abdelrahman Aref
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>

union UNUMjob
{
	char name [32] ;
	float salary;
	int worker_no;

} ujob;

struct Sjob
{
	char name [32];
	float salary;
	int worker_no;

} sjob;


int main ()
{
	printf ("Size of the union is: %d", sizeof (ujob));
	printf ("\nSize of the structure is: %d", sizeof (sjob));

	return EXIT_SUCCESS;
}
