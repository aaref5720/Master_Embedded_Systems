#include "Students_DB.h"

struct Student_Node_t* gFirst_student = NULL;

void Fill_A_New_Record(struct Student_Node_t *NewStudent)
{
	char temp_text[Max_Name_Size];

	DPRINTF("Enter the student's ID : ");
	gets(temp_text);
	NewStudent->Student.ID = atoi(temp_text);

	DPRINTF("Enter the student's name : ");
	gets(NewStudent->Student.name);

	DPRINTF("Enter the student's hight : ");
	gets(temp_text);
	NewStudent->Student.hight = atof(temp_text);
}

void Add_Student(void)
{
	struct Student_Node_t* PnewStudent;
	struct Student_Node_t* PlastStudent;

	if(gFirst_student == NULL)
	{
		//Creat a new record
		PnewStudent = (struct Student_Node_t*) malloc(sizeof(struct Student_Node_t));

		// Check for invalid allocation
		if(PnewStudent == NULL)
		{
			DPRINTF("Error: Can't create new student\n");
			return;
		}

		//Assign it to gFirst_student
		gFirst_student = PnewStudent;
	}
	else
	{
		//Navigate until reach the last record
		PlastStudent = gFirst_student;
		while(PlastStudent->Next_Student_Ptr)
		{
			PlastStudent = PlastStudent->Next_Student_Ptr;
		}

		//Creat a new record
		PnewStudent = (struct Student_Node_t*) malloc(sizeof(struct Student_Node_t));

		// Check for invalid allocation
		if(PnewStudent == NULL)
		{
			DPRINTF("Error: Can't create new student\n");
			return;
		}

		// Assign its next to it
		PlastStudent->Next_Student_Ptr = PnewStudent;
	}
	// Fill the record
	Fill_A_New_Record(PnewStudent);

	// Assign its next to null
	PnewStudent->Next_Student_Ptr = NULL;
}

void Delete_Student(void)
{
	char temp_text[Max_Name_Size];
	unsigned int selected_id;

	// Get the selected ID from the user
	DPRINTF("\nEnter Student's ID to be deleted: ");
	gets(temp_text);
	selected_id = atoi(temp_text);
	//check if list is empty
	if(gFirst_student)
	{
		struct Student_Node_t* PselectedStudent = gFirst_student;
		struct Student_Node_t* PPreviousStudent = NULL;
		//loop on all records
		while(PselectedStudent)
		{
			//Compare each node with the selected ID
			if(PselectedStudent->Student.ID == selected_id)
			{
				if (PPreviousStudent) //The selected student is not the first one
				{
					PPreviousStudent->Next_Student_Ptr = PselectedStudent->Next_Student_Ptr;
				}
				else
				{
					gFirst_student = PselectedStudent->Next_Student_Ptr;
				}
				free(PselectedStudent);
				DPRINTF("\nThe selected ID have deleted. \n");
				return;
			}

			PPreviousStudent = PselectedStudent;
			PselectedStudent = PselectedStudent->Next_Student_Ptr;
		}
	DPRINTF("\n\tThe selected ID not find. \n");
	return;
	}

	else
	{
		DPRINTF("\nThe list is already NULL !\n");
		return;
	}
}

void View_students(void)
{
	if(gFirst_student)
	{
		struct Student_Node_t* PselectedStudent = gFirst_student;
		unsigned int counter = 1 ;
		while(PselectedStudent)
		{
			DPRINTF("\n Record Number %d",counter);
			DPRINTF("\n\t ID : %d",PselectedStudent->Student.ID);
			DPRINTF("\n\t Name : %s",PselectedStudent->Student.name);
			DPRINTF("\n\t Height : %0.2f\n",PselectedStudent->Student.hight);
			PselectedStudent = PselectedStudent->Next_Student_Ptr;
			counter++;
		}
		return;
	}

	else
	{
		DPRINTF("\nThe list is NULL !\n");
		return;
	}
}

void Delete_All(void)
{
	if(gFirst_student)
	{
		struct Student_Node_t* PselectedStudent = gFirst_student;
		while(PselectedStudent)
		{
			struct Student_Node_t* PtempStudent = PselectedStudent->Next_Student_Ptr;
			PselectedStudent = PselectedStudent->Next_Student_Ptr;
			free(PtempStudent);
		}
		gFirst_student = NULL;
		DPRINTF("\nThe list's elements have deleted\n");
		return;
	}

	else
	{
		DPRINTF("\nThe list is already NULL !\n");
		return;
	}
}

void Get_Node(unsigned int index)
{
	unsigned int counter = 0;

	if(index < 0)
	{
		DPRINTF("\nInvalid index\n");
		return;
	}

	if(gFirst_student)
	{
		struct Student_Node_t* PselectedStudent = gFirst_student;

		while(PselectedStudent)
		{
			if(counter == index)
			{
				DPRINTF("\n Record Index %d",index);
				DPRINTF("\n\t ID : %d",PselectedStudent->Student.ID);
				DPRINTF("\n\t Name : %s",PselectedStudent->Student.name);
				DPRINTF("\n\t Height : %0.2f\n",PselectedStudent->Student.hight);
				return;
			}

			PselectedStudent = PselectedStudent->Next_Student_Ptr;
			counter++;
		}
		return;
	}

	else
	{
		DPRINTF("\nThe list is NULL !\n");
		return;
	}
}

void Get_Node_From_End(int index)
{

	if(index < 0)
	{
		DPRINTF("\nInvalid index\n");
		return;
	}

	if(gFirst_student)
	{
		unsigned int counter = 0;
		struct Student_Node_t* Pmain = gFirst_student;
		struct Student_Node_t* Pref  = gFirst_student;

		while(Pmain)
		{
			Pmain = Pmain->Next_Student_Ptr;
			counter++;

			if (counter == index)
			{
				break;
			}
		}

		while(Pmain)
		{
			Pmain = Pmain->Next_Student_Ptr;
			Pref  = Pref->Next_Student_Ptr;
		}

		DPRINTF("\n Record Index %d",index);
		DPRINTF("\n\t ID : %d",Pref->Student.ID);
		DPRINTF("\n\t Name : %s",Pref->Student.name);
		DPRINTF("\n\t Height : %0.2f\n",Pref->Student.hight);
		return;
	}

	else
	{
		DPRINTF("\nThe list is NULL !\n");
		return;
	}
	
}

int Students_Count_Iterative(void)
{
	struct Student_Node_t* PselectedStudent = gFirst_student;
	unsigned int counter = 1;
	if(gFirst_student)
	{
		while(PselectedStudent)
		{
			if(PselectedStudent->Next_Student_Ptr == NULL)
				break;

			PselectedStudent = PselectedStudent->Next_Student_Ptr;
			counter++;
		}
	}
	else
	{
		DPRINTF("\nThe list is  NULL !\n");
		return 0;
	}
	return counter;
}

int Students_Count_Recursive(struct Student_Node_t* head)
{

	if(gFirst_student == NULL)
	{
		DPRINTF("\nThe list is  NULL !\n");
		return 0 ;
	}

	if(head == NULL)
	{
		return 0;
	}
	else
	{
		return (1 + Students_Count_Recursive(head->Next_Student_Ptr));
	}

}

void Get_Middle_Student(void)
{
	if(gFirst_student)
	{
		int StudentNumber = Students_Count_Iterative();
		unsigned int index = 0;
		Get_Node(StudentNumber/2);
		return;
	}

	else
	{
		DPRINTF("\nThe list is NULL !\n");
		return;
	}
}

void Reverse_Students(void)
{
	struct Student_Node_t* Pnext 	  = NULL;
	struct Student_Node_t* Pcurrent  = gFirst_student;
	struct Student_Node_t* Pprevious = NULL;

	while(Pcurrent)
	{
		Pnext = Pcurrent->Next_Student_Ptr;
		Pcurrent->Next_Student_Ptr = Pprevious;
		Pprevious = Pcurrent;
		Pcurrent = Pnext;
	}
	gFirst_student = Pprevious;
}

