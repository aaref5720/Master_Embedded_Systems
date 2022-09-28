/*
 ============================================================================
 Name        : EX2_C_Program_to_Add_Two_Distances_Systems_Using_Structure.c
 Author      : Abdelrahman Aref
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>

struct Sdistances
{
	float inchs;
	float feets;
};

struct Sdistances distanceInfo();
struct Sdistances distanceSum(struct Sdistances distance1 , struct Sdistances distance2);

int main(void) {

	struct Sdistances distance1 , distance2 , result;

	printf("Enter information of the 1st distance : \n");
	distance1 = distanceInfo();

	printf("\nEnter information of the 2nd distance : \n");
	distance2 = distanceInfo();

	result =  distanceSum(distance1 , distance2);
	printf("Sum of distances : %.2f feet %.2f inch",result.feets , result.inchs);

	return EXIT_SUCCESS;
}

struct Sdistances distanceInfo()
{
	struct Sdistances distance;
	printf("Enter distance in Feet : ");
	fflush(stdin);  fflush(stdout);
	scanf("%f",&distance.feets);

	printf("Enter distance in inch : ");
	fflush(stdin);  fflush(stdout);
	scanf("%f",&distance.inchs);

	return distance ;
}

struct Sdistances distanceSum(struct Sdistances distance1 , struct Sdistances distance2)
{
	struct Sdistances sum ;
	sum.inchs = distance1.inchs + distance2.inchs;
	sum.feets = distance1.feets + distance2.feets;

	while(sum.inchs >= 12 )
	{
		sum.inchs -= 12 ;
		sum.feets++;
	}

	return sum;
}
