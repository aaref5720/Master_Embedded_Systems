#include "system.h"
#include "FIFO.h"

int main (void)
{
	FIFO_Status flag ;
	// Call FIFO_Init to initialize the FIFO Buffer in memory 
	flag = FIFO_init(&VirtualBuffer, Stu , Buffer_Length);

	// Start handling
	printf("Welcome to the student management system\n");

	uint8 Option;

	while(1)
	{
		printf("\nChoose the task that you want to perform\n"
			   "1.  Add the student details manually\n"
			   "2.  Add the student details from text file\n"
			   "3.  Find the student details by roll number\n"
			   "4.  Find the students details by first name\n"
			   "5.  Find the students details by course ID\n"
			   "6.  Find the total number of students\n"
			   "7.  Delete the student details by roll number\n"
			   "8.  Update the student details by roll number\n"
			   "9.  Show all information\n"
			   "10. Exit\n"
			   "Enter your choice to perform the task: "
			  );
		fflush (stdin); fflush(stdout);
		scanf("%d", &Option);
		printf("\n----------------------------------------------\n");

		switch(Option)
		{
			case 1 :	Add_Student_Manually 			();			break;
			case 2 :	Add_Student_From_File     		();         break;
			case 3 :	Find_Student_by_Roll_Number  	();    		break;
			case 4 :	Find_Student_by_First_Name   	();    		break;
			case 5 :	Find_Students_by_Course       	();    		break;
			case 6 :	Total_Students       			();    		break;
			case 7 :	Delete_Student_by_Roll_Number	();			break;
			case 8 :	Update_Student_by_Roll_Number	();    		break;
			case 9 :	Show_Students_Info        		();		    break;
			case 10:	printf("Exiting ...\n");   exit(0);   		break;
			default:    printf("Not valid option\n");       		break;
		}
	}

	return 0;
}
