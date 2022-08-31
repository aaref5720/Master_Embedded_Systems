/*
 ============================================================================
 Name        : EX2_C_Program_To_Print_a_Integer_Entered_by_a_User.c
 Author      : Abdelrahman Aref
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>

int main(void) {
	int x = 0 ;
	printf("Enter an integer : ");
	fflush(stdin);  fflush(stdout);
	scanf("%d",&x);
	printf("You Entered : %d",x);
	return EXIT_SUCCESS;
}
