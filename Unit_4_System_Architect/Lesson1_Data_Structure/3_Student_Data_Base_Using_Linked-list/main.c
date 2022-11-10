#include "Students_DB.h"


int main(void)
{
	char temp_text[Max_Name_Size];
	int num = 0;
	struct Student_Node_t *gpStudent = NULL ;

	while(1)
	{
		DPRINTF(" ============================= ");
		DPRINTF("\n Choose one from the following options \n");
		DPRINTF("\n\t 1: Add Student");
		DPRINTF("\n\t 2: Delete Student");
		DPRINTF("\n\t 3: View Students");
		DPRINTF("\n\t 4: Delete All");
		DPRINTF("\n\t 5: Get Node");
		DPRINTF("\n\t 6: Get Students count by Iteration");
		DPRINTF("\n\t 7: Get Students count by Recursion");
		DPRINTF("\n\t 8: Get Node from the end");
		DPRINTF("\n\t 9: Get the middle student");
		DPRINTF("\n\t 10: Reverse student");
		DPRINTF("\n\t 11: Exit");
		DPRINTF("\n\n Enter option number: ");

		gets(temp_text);
		DPRINTF("\n ============================= \n");
		switch(atoi(temp_text))
		{
			case 1:
				Add_Student();
				break;

			case 2:
				Delete_Student();
				break;

			case 3:
				View_students();
				break;

			case 4:
				Delete_All();
				break;

			case 5:
				DPRINTF("Enter Node Number: ");
				gets(temp_text);
				num = atoi(temp_text);
				Get_Node(num);
				break;

			case 6:
				num = Students_Count_Iterative();
				DPRINTF("Student Numbers : %d\n", num);
				break;

			case 7:
				num = Students_Count_Recursive(gpStudent);
				DPRINTF("Student Numbers : %d\n", num);
				break;

			case 8:
				DPRINTF("Enter Node Number from the end : ");
				gets(temp_text);
				num = atoi(temp_text);
				Get_Node_From_End(num);
				break;

			case 9:
				Get_Middle_Student();
				break;

			case 10:
				Reverse_Students();
				break;

			case 11:
				return 0;

			default:
				DPRINTF("\n Wrong Option: Try Again \n\n");
				break;
		}
	}
	return 0;
}
