/*
 ============================================================================
 Name        : EX3_C_Program_to_Add_Two_Integers.c
 Author      : Abdelrahman Aref
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>

int main(void) {
	int x = 0 , y = 0 ;
	printf("Enter two integers:"); /* prints !!!Hello World!!! */
	fflush(stdin);  fflush(stdout);
	scanf("%d%d",&x,&y);
	printf("Sum:%d",x+y);
	return EXIT_SUCCESS;
}
