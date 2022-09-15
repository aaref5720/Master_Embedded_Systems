/*
 ============================================================================
 Name        : Q1_C_Program_Takes_String_From_The_User_And_Check_If_It_The_Same.c
 Author      : Abdelrahman Aref
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int main(void) {
	char first[20],USERNAME[20] = "Embedded_Systems";
	printf("Enter the user name : ");
	fflush(stdin);  fflush(stdout);
	scanf("%s",first);

	int x = strcmp(first,USERNAME);

	if(x==0)
		printf("Identical");
	else
		printf("Different");

	return EXIT_SUCCESS;
}
