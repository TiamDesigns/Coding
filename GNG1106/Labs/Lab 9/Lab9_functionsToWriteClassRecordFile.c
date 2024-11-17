#include <stdio.h>

#define NUM_STUDENTS 200
#define INVALID_MARK -1   

/*******************************************************************************************************
*												       *
*		symbolic constants concerning the graded items.                                        *
*         										               *
* Note that the values of these constant might have been changed when the code is used to generate     *
* the class record file.									       *
*					       							       *
*												       *
*******************************************************************************************************/

#define NUM_ASSIGNMENTS 5 
#define NUM_ICES 4
#define NUM_LABS 6 
#define MAX_MARK_PER_ASSIGNMENT 10
#define MAX_MARK_PER_LAB 20
#define MAX_MARK_PER_ICE 5
#define MAX_MARK_MIDTERM 100
#define MAX_MARK_FINAL_EXAM 100

/*******************************************************************************************************
*												       *
*	This is the structure defined to encapsulate one student's information of graded items,        *
* average assignment mark, average ICE mark, average lab mark, and overall mark, as well as the        *
* student ID. Such a collection of information is referred to as a student record.		       *
*												       *
*******************************************************************************************************/

typedef struct
{
	int ID;
	float assignment_mark[NUM_ASSIGNMENTS];
	float ice_mark[NUM_ICES];
	float lab_mark[NUM_LABS];
	float midterm_mark;
	float final_mark;
	float assignment_average_mark;
	float lab_average_mark;
	float ice_average_mark;
	float overall_mark;
}STUDENT_REC;


void printRecToFile(STUDENT_REC rec, FILE *fp)
{

	fprintf(fp, "%d", rec.ID);
	for  (int i=0; i<NUM_ASSIGNMENTS; i++)
		fprintf(fp, "\t%6.2f", rec.assignment_mark[i]);
        for  (int i=0; i<NUM_ICES; i++)
                fprintf(fp, "\t%6.2f", rec.ice_mark[i]);
       	for  (int i=0; i<NUM_LABS; i++)
                fprintf(fp, "\t%6.2f", rec.lab_mark[i]);

	fprintf(fp, "\t%6.2f", rec.midterm_mark);
        fprintf(fp, "\t%6.2f", rec.final_mark);
        fprintf(fp, "\t%6.2f", rec.assignment_average_mark);
        fprintf(fp, "\t%6.2f", rec.ice_average_mark);
        fprintf(fp, "\t%6.2f", rec.lab_average_mark);
        fprintf(fp, "\t%6.2f", rec.overall_mark);
	fprintf(fp, "\n");
}

void printClassRecToFile(STUDENT_REC *classRec, int numOfStudents, char filename[200])
{
	// print header information
	FILE *fp=fopen(filename, "w");
	fprintf(fp, "%d\n", numOfStudents);
	fprintf(fp, "%d\t%d\t%d\t%d\t%d\t%d\t%d\t%d\n", NUM_ASSIGNMENTS, NUM_ICES, NUM_LABS, 
		MAX_MARK_PER_ASSIGNMENT, MAX_MARK_PER_LAB, MAX_MARK_PER_ICE, 
		MAX_MARK_MIDTERM, MAX_MARK_FINAL_EXAM);
  
	for (int i=0; i<numOfStudents; i++)
		printRecToFile(classRec[i], fp);

	fclose(fp);
}



int main()
{
	// This is the program that is used to generate the ascii file "classStats.txt".
        // The details of the code is deleted. But the creation of the file "classStats.txt" is done by
        // calling the function  printClassRecToFile above.

	return 0;

}
