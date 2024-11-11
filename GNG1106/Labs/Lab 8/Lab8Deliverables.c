#include <stdio.h>
#include <stdlib.h>
#include <math.h>


#define NUM_STUDENTS 20
#define INVALID_MARK -1   



/*******************************************************************************************************
*												       *
*		symbolic constants concerning the graded items					       *
*												       *
*******************************************************************************************************/


#define NUM_ASSIGNMENTS 2 
#define NUM_ICES 3 
#define NUM_LABS 4 
#define MAX_MARK_PER_ASSIGNMENT 10
#define MAX_MARK_PER_LAB 20
#define MAX_MARK_PER_ICE 5
#define MAX_MARK_MIDTERM 100
#define MAX_MARK_FINAL_EXAM 100

/*******************************************************************************************************
*												       *
*	 symbolic constants for weighting factors in the grading scheme				       *
*												       *
*******************************************************************************************************/


#define WEIGHT_ASSIGNMENTS 0.05
#define WEIGHT_ICES 0.05
#define WEIGHT_LABS 0.10
#define WEIGHT_MIDTERM 0.30
#define WEIGHT_FINAL_EXAM 0.50


/*******************************************************************************************************
*												       *
*	symbolic constants for the modes of sorting						       *
*												       *
*******************************************************************************************************/


#define SORT_BY_SINGLE_ASSIGNMENT 1
#define SORT_BY_SINGLE_ICE 2
#define SORT_BY_SINGLE_LAB 3
#define SORT_BY_ASSIGNMENT_AVG 11
#define SORT_BY_ICE_AVG 12
#define SORT_BY_LAB_AVG 13
#define SORT_BY_MIDTERM 14
#define SORT_BY_FINAL_EXAM 15
#define SORT_BY_OVERALL_MARK 16
#define SORT_BY_ID 21

/*******************************************************************************************************
*												       *
*       symbolic constants for the orders of sorting						       *
*												       *
*******************************************************************************************************/



#define SORT_ASCENDING 1
#define SORT_DESCENDING 0



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


/*******************************************************************************************************
*												       *
* 	This function prints a student record as a single row of numbers, which include the values in  *
* all member variables in the STUDENT_REC typed variable passed to this function.		       *
*												       * 
* 	YOU NEED TO IMPLEMENT THIS FUNCTION							       *
*												       *	 
*******************************************************************************************************/

void printRec(STUDENT_REC rec);



/*******************************************************************************************************
*												       *
*	This function prints all student records in a given array of STUDENT_REC typed variables. If   *
* the array contains K student records, it prints K+1 rows. The first row is the header indicating the *
* attribute of each column, such as "assignment 1", "ICE 2", "Lab 3", "midterm", etc, which could be   *
* in an abbreviated form, for example, "A-1" for "assignment 1" etc.  The remaining K rows each        *
* contain a student's record, printed via calling the printRec function.			       *
*												       *
*	YOU NEED TO IMPLEMENT THIS FUNCTION.							       *
*												       *
*******************************************************************************************************/

void printClassRec(STUDENT_REC *classRec, int numOfStudents);
      


/*******************************************************************************************************
*												       *
*	This function is used to generate random marks in student records. It has been implemented     *
* already. It is called by getClassRecords. This function returns a random number with distribution on *
* a specified range and centered at its mid-point. Parameter "peakiness" specifies the peakiness of    *
* the  distribution, where peakiness = 1 corresponds to the uniform distribution and higher peakiness  *
* value make the distribution peakier.								       *
*												       *
*	YOU DO NOT NEED TO UNDERSTAND OR CALL THIS FUNCTION.					       *
*												       *
*******************************************************************************************************/

double getGoodRandomNumberInRange(int lower, int upper, int peakiness);


/*******************************************************************************************************
*												       *
*	 This function generate a students records by setting the marks of all graded items to some    *
* random values, simulating the performance of a class of students. The parameter classRec is the      *
* pointer to an array of STUDENT_REC, and numOfStudents is the length of the array. After the calling  *
* of this function, the ID and each member variable in the array that corresponds to a graded item is  *
* assigned a value. The marks for other member variables in each variable is set to INVAID_MARK (a     *
* symbolic constant, defined earlier).								       *
*												       *
*	THIS FUNCTION HAS BEEN IMPLEMENTED. THE CALLING OF THIS FUNCTION IS ALREADY DONE IN THE MAIN   *
* FUNCTION. YOU ONLY NEED TO UNDERSTAND WHAT IT DOES AND ITS PROTOTYPE. YOU DO NOT NEED TO KNOW ITS    *
* INTERNAL DETAILS, NEITHER WILL YOU NEED TO MAKE ADDITIONAL CALLS OF THIS FUNCTION.		       *
*												       *
*******************************************************************************************************/


void getClassRecords(STUDENT_REC *classRec, int numOfStudents);


/*******************************************************************************************************
*												       *
*	This function completes each record in an array of STUDENT_REC variables. More precisely, for  *
* each student it computes the average assignment mark, average ICE mark, average lab mark, and assign *
* these values to the respective member variables in the student's record. It then computes the overall*
*  markv(out of 100) based on the maximnum marks of each item and the weighting schemes given in the   *
* following symbolic constants.									       *
*												       *
*	MAX_MARK_PER_ASSIGNMENT									       * 
*	MAX_MARK_PER_LAB 									       *
*	MAX_MARK_PER_ICE 									       *
*	MAX_MARK_MIDTERM 									       *
*	MAX_MARK_FINAL_EXAM 									       *
*												       *	
*	WEIGHT_ASSIGNMENTS									       * 
*	WEIGHT_ICES 										       *
*	WEIGHT_LABS 										       *
*	WEIGHT_MIDTERM 										       *
*	WEIGHT_FINAL_EXAM 									       *
*											               *
* 	The overall mark should be assigned to the corresponding member in the student's record.       *
*												       *
*	YOU NEED TO IMPLEMENT THIS FUNCTION.							       *
*												       *
*******************************************************************************************************/

void completeClassRecords(STUDENT_REC *classRec, int numOfStudents);





/*******************************************************************************************************
*												       *
*	Thia function performs bubbleSort of an array of STUDENT_REC typed variables. The parameters   *
* serve the following purposes:									       *
*												       *
*	classRec:	pointer to the array of STUDENT_REC typed variables to be sorted	       *
*	numRecs: 	number of STUDENT_REC typed variables in the array			       *
*	sort_order: 	taking values either SORT_ASCENDING or SORT_DESCENDING (which are defined      *
*			symbolic constants) indicating if the sorting is in ascending order or         *
*			descending order.							       *
*	sort_mode:	indicating if the sorting is based on a single assignment, a single ICE,       *
*			a single lab, the midter exam, the final exam, the average assignment mark,    *
*			the average ICE mark, the average lab mark, the overall mark, or the ID.       *
*			The variable takes value from the following symbolic constants, which have     *
*			been defined to indicate these options.					       *
*												       *
*				SORT_BY_SINGLE_ASSIGNMENT					       * 
*				SORT_BY_SINGLE_ICE 						       *
*				SORT_BY_SINGLE_LAB 						       *
*				SORT_BY_ASSIGNMENT_AVG 					               *
*				SORT_BY_ICE_AVG 						       *
*				SORT_BY_LAB_AVG 						       *
*				SORT_BY_MIDTERM 						       *
*				SORT_BY_FINAL_EXAM 						       *
*				SORT_BY_OVERALL_MARK						       *
*				SORT_BY_ID 							       *
*												       *
*	item_index: 	This variable is only useful when the sort_mode is SORT_BY_SINGLE_ASSIGNMENT,  *
*			SORT_BY_SINGLE_ICE, or SORT_BY_SINGLE_LAB. In this case, item_index indicates  *
*			respectively, the index of assignment, ICE, or lab, based on which sorting is  *
*			to be performed. 							       *
*												       *	
*	YOU NEED TO IMPLEMENT THIS FUNCTION.							       *
*												       *
*******************************************************************************************************/

void bubbleSortClassRecords(STUDENT_REC *classRec, int numRecs, int sort_order, int sort_mode, int item_index);



/*******************************************************************************************************
*												       *
*	This function must be called by bubbleSortClassRecords. It returns 1 (True) if record A        *
* precedes record B after sorting, and 0 (False) otherwise. Paramter pA contains the address of record *
* A, and pB contains the address of record B. Parameters sort_order, sort_mode, and item_index         *
* are meant to carry the same information as those in function bubbleSortClassRecords.		       *
*												       *
*	YOU NEED TO IMPLEMENT THIS FUNCTION.							       *
*												       *
*******************************************************************************************************/

int shouldAPrecedeB(STUDENT_REC *pA, STUDENT_REC *pB, int sort_order, int sort_mode, int item_index);



/*******************************************************************************************************
*											               *
*		THE MAIN FUNCTION. ALREADY IMPLEMENTED. YOU MUST NOT CHANGE IT.			       *
*												       *
*******************************************************************************************************/






int main()
{
	long randomSeed=1234;
	int sort_mode=0;
	int sort_order=0;
	int item_index=0;
	int showMenu=1;

	STUDENT_REC allRec[NUM_STUDENTS];
	getClassRecords(allRec, NUM_STUDENTS);
	// With this function call, the records of all students are loaded into array "allRec", where the members
	// assignment_average_mark, lab_average_mark, ice_average_mark and overall_mark  in each record are set to
	// INVALID_MARK, meaning that they are not yet computed.

	
	printf("Class records loaded.");

       	// Complete the record for each students by computing assignment_average_mark, lab_average_mark, ice_average_mark
	// and overall_mark
	completeClassRecords(allRec, NUM_STUDENTS);

	
	while(showMenu)
	{
		printf("Enter\n");
		printf("\t%d for SORT BY SINGLE ASSIGNMENT\n", SORT_BY_SINGLE_ASSIGNMENT);
		printf("\t%d for SORT BY SINGLE ICE\n", SORT_BY_SINGLE_ICE);
        printf("\t%d for SORT BY SINGLE LAB\n", SORT_BY_SINGLE_LAB);       
        printf("\t%d for SORT BY ASSIGNMENT AVERAGE\n", SORT_BY_ASSIGNMENT_AVG);
        printf("\t%d for SORT BY ICE AVERAGE\n", SORT_BY_ICE_AVG);
        printf("\t%d for SORT BY LAB AVERAGE\n", SORT_BY_LAB_AVG);
        printf("\t%d for SORT BY MIDTERM\n", SORT_BY_MIDTERM);
        printf("\t%d for SORT BY FINAL EXAM\n", SORT_BY_FINAL_EXAM);
		printf("\t%d for SORT BY OVERALL MARK\n", SORT_BY_OVERALL_MARK);
        printf("\t%d for SORT BY ID\n", SORT_BY_ID);
		scanf("%d", &sort_mode);
		if ((sort_mode==SORT_BY_SINGLE_ICE)||(sort_mode==SORT_BY_SINGLE_ASSIGNMENT)||(sort_mode==SORT_BY_SINGLE_LAB))
		{
			printf("Enter the index of the item (indices start from 1)\n");
			scanf("%d", &item_index);
		}
		printf("Ascending (%d) or desecending (%d)?\n", SORT_ASCENDING, SORT_DESCENDING);
		scanf("%d", &sort_order);
		bubbleSortClassRecords(allRec, NUM_STUDENTS, sort_order, sort_mode, item_index-1);
		printClassRec(allRec, NUM_STUDENTS);
		printf("Enter 0 to exit, or 1 to sort again\n");
		scanf("%d", &showMenu);
	}
	return 0;
}


/*******************************************************************************************************
*												       *
*					FUNCTIONS YOU NEED TO IMPLEMENT				       *
*												       *
*******************************************************************************************************/


void printRec(STUDENT_REC rec) {
    printf("%d\t", rec.ID); // Print the student's ID followed by a tab
    for (int i = 0; i < NUM_ASSIGNMENTS; i++) printf("%.1f\t", rec.assignment_mark[i]); // Print each assignment mark with one decimal and a tab
    for (int i = 0; i < NUM_ICES; i++) printf("%.1f\t", rec.ice_mark[i]); // Print each ICE mark with one decimal and a tab
    for (int i = 0; i < NUM_LABS; i++) printf("%.1f\t", rec.lab_mark[i]); // Print each lab mark with one decimal and a tab
    printf("%.1f\t%.1f\t%.1f\t%.1f\t%.1f\t%.1f\n", // Print midterm, final, assignment average, lab average, ICE average, and overall marks
           rec.midterm_mark,
           rec.final_mark,
           rec.assignment_average_mark,
           rec.lab_average_mark,
           rec.ice_average_mark,
           rec.overall_mark);
}


void printClassRec(STUDENT_REC *classRec, int numOfStudents) {
    //I realize in hindsight that the following print could have been done using for loops as it is defined above how many assignments etc. there are
    printf("ID\tA-1\tA-2\tICE-1\tICE-2\tICE-3\tLab-1\tLab-2\tLab-3\tLab-4\tMidterm\tFinal\tA-Avg\tL-Avg\tI-Avg\tOverall\n"); // Print the header row for student records
    for (int i = 0; i < numOfStudents; i++) { // Loop through each student record
        printRec(classRec[i]); // Print the current student's record by calling printRec function
    }
}




void completeClassRecords(STUDENT_REC *classRec, int numOfStudents) {
    for (int i = 0; i < numOfStudents; i++) { // Loop through each student record
        STUDENT_REC *rec = &classRec[i]; // Pointer to the current student record
        
        float assignmentSum = 0, iceSum = 0, labSum = 0; // Initialize sums for assignment, ICE, and lab marks
        for (int j = 0; j < NUM_ASSIGNMENTS; j++) assignmentSum += rec->assignment_mark[j]; // Sum assignment marks
        for (int j = 0; j < NUM_ICES; j++) iceSum += rec->ice_mark[j]; // Sum ICE marks
        for (int j = 0; j < NUM_LABS; j++) labSum += rec->lab_mark[j]; // Sum lab marks

        rec->assignment_average_mark = assignmentSum / NUM_ASSIGNMENTS; // Calculate assignment average
        rec->ice_average_mark = iceSum / NUM_ICES; // Calculate ICE average
        rec->lab_average_mark = labSum / NUM_LABS; // Calculate lab average

        rec->overall_mark = ((rec->assignment_average_mark / MAX_MARK_PER_ASSIGNMENT) * WEIGHT_ASSIGNMENTS + // Calculate weighted assignment contribution
                             (rec->ice_average_mark / MAX_MARK_PER_ICE) * WEIGHT_ICES + // Calculate weighted ICE contribution
                             (rec->lab_average_mark / MAX_MARK_PER_LAB) * WEIGHT_LABS + // Calculate weighted lab contribution
                             (rec->midterm_mark / MAX_MARK_MIDTERM) * WEIGHT_MIDTERM + // Calculate weighted midterm contribution
                             (rec->final_mark / MAX_MARK_FINAL_EXAM) * WEIGHT_FINAL_EXAM) * 100; // Calculate weighted final contribution, then multiply by 100
    }
}


void bubbleSortClassRecords(STUDENT_REC *classRec, int numRecs, int sort_order, int sort_mode, int item_index) {
    for (int i = 0; i < numRecs - 1; i++) { // Outer loop for bubble sort
        for (int j = 0; j < numRecs - i - 1; j++) { // Inner loop for comparing adjacent elements
            if (shouldAPrecedeB(&classRec[j + 1], &classRec[j], sort_order, sort_mode, item_index)) { // Check if elements should be swapped
                STUDENT_REC temp = classRec[j]; // Temporary variable to hold the current element
                classRec[j] = classRec[j + 1]; // Swap the current element with the next element
                classRec[j + 1] = temp; // Assign the current element to the next position
            }
        }
    }
}




int shouldAPrecedeB(STUDENT_REC *pA, STUDENT_REC *pB, int sort_order, int sort_mode, int item_index) {
    float valA, valB; // Variables to hold the sorting values for pA and pB
    
    switch (sort_mode) { // Determine the value to compare based on sort_mode
        case SORT_BY_SINGLE_ASSIGNMENT: valA = pA->assignment_mark[item_index]; valB = pB->assignment_mark[item_index]; break;
        case SORT_BY_SINGLE_ICE: valA = pA->ice_mark[item_index]; valB = pB->ice_mark[item_index]; break;
        case SORT_BY_SINGLE_LAB: valA = pA->lab_mark[item_index]; valB = pB->lab_mark[item_index]; break;
        case SORT_BY_ASSIGNMENT_AVG: valA = pA->assignment_average_mark; valB = pB->assignment_average_mark; break;
        case SORT_BY_ICE_AVG: valA = pA->ice_average_mark; valB = pB->ice_average_mark; break;
        case SORT_BY_LAB_AVG: valA = pA->lab_average_mark; valB = pB->lab_average_mark; break;
        case SORT_BY_MIDTERM: valA = pA->midterm_mark; valB = pB->midterm_mark; break;
        case SORT_BY_FINAL_EXAM: valA = pA->final_mark; valB = pB->final_mark; break;
        case SORT_BY_OVERALL_MARK: valA = pA->overall_mark; valB = pB->overall_mark; break;
        case SORT_BY_ID: valA = pA->ID; valB = pB->ID; break;
        default: return 0; // Return 0 if sort_mode is invalid
    }

    if (sort_order == SORT_ASCENDING) return valA < valB; // Return 1 if sorting is ascending and valA < valB
    else return valA > valB; // Return 1 if sorting is descending and valA > valB
}






/*******************************************************************************************************
*												       *
*				IMPLEMENTED FUNCTIONS. DO NOT CHANGE THEM.			       *
*												       *
*******************************************************************************************************/



double getGoodRandomNumberInRange(int lower, int upper, int peakiness)
{

	int range=upper-lower;
	int i;
	double x=0;
	for (i=0; i<peakiness; i++)
		x=x+(double)(rand()%RAND_MAX)/RAND_MAX;
	x=x/peakiness;
	x=x*range+lower;
	return x;
}

void getClassRecords(STUDENT_REC *classRec, int numOfStudents)
{
	int i, j;
	double x;
	int* ptrStudentLevels;

	// create levels for all students
	ptrStudentLevels=(int  *)malloc(numOfStudents*sizeof(int));
	for (i=0; i<numOfStudents; i++)
		ptrStudentLevels[i]=rand()%7;


	for (i=0; i<numOfStudents; i++)
	{
		// generate student numbers
		(classRec+i)->ID=rand()%10000+30000;

		// generate assignment marks
		for (j=0; j<NUM_ASSIGNMENTS; j++)
		{
			x=getGoodRandomNumberInRange(MAX_MARK_PER_ASSIGNMENT*ptrStudentLevels[i]/10, MAX_MARK_PER_ASSIGNMENT, 3);
			(classRec+i)->assignment_mark[j]=round(x*2)/2;	
		}

		// generate ICE marks
                for (j=0; j<NUM_ICES; j++)
                {       
                        x=getGoodRandomNumberInRange(MAX_MARK_PER_ICE*ptrStudentLevels[i]/10, MAX_MARK_PER_ICE, 2);
                        (classRec+i)->ice_mark[j]=round(x*2)/2;
                }

		// generate lab marks
                for (j=0; j<NUM_LABS; j++)
                {
                        x=getGoodRandomNumberInRange(MAX_MARK_PER_LAB*ptrStudentLevels[i]/10, MAX_MARK_PER_LAB, 2);
                        (classRec+i)->lab_mark[j]=round(x*2)/2;
                }

		// generate midterm mark
                x=getGoodRandomNumberInRange(MAX_MARK_MIDTERM*ptrStudentLevels[i]/10, MAX_MARK_MIDTERM, 1);
               (classRec+i)->midterm_mark=round(x*2)/2;

		// generate final exam mark
                x=getGoodRandomNumberInRange(MAX_MARK_FINAL_EXAM*ptrStudentLevels[i]/10, MAX_MARK_FINAL_EXAM, 2);
               (classRec+i)->final_mark=round(x*2)/2;

		// generate invalid marks for assignment average, ice average, lab average, overall mark,
		(classRec+i)->assignment_average_mark=INVALID_MARK;
                (classRec+i)->ice_average_mark=INVALID_MARK;
                (classRec+i)->lab_average_mark=INVALID_MARK;
                (classRec+i)->overall_mark=INVALID_MARK;
	}
	free(ptrStudentLevels);
}
