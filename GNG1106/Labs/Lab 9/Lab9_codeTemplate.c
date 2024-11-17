#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>



#define LONG_ARRAY_LENGTH 300
// This number is larger than the number of students in the class. For any array having length equal to
// the number of students in the class, this number can be used as the length of the array.

#define SHORT_ARRAY_LENGTH 30
// All arrays (that are not char arrays) needed in this lab, except those having length equal to the number 
// of students in the class, can be declared to have this length.


#define MAX_STRING_LENGTH 200
// All strings encountered in this lab have length lower than this number. Use this as the length of  
// any char array that is meant to represent strings.


/*******************************************************************************************************
*												       *
*	The following structure is  defined to encapsulate a student's marks of all graded items,      *
* average assignment mark, average ICE mark, average lab mark, and overall mark, as well as the        *
* student ID. Such a collection of information is referred to as a student record. It is known that    *
* the number of assignments, the number of ICEs, and the number of labs are all no larger than         *
* SHORT_ARRAY_LENGTH. 		       								       *
*												       *
*******************************************************************************************************/

typedef struct
{
	int ID;
	float assignment_mark[SHORT_ARRAY_LENGTH];
	float ice_mark[SHORT_ARRAY_LENGTH];
	float lab_mark[SHORT_ARRAY_LENGTH];
	float midterm_mark;
	float final_mark;
	float assignment_average_mark;
	float lab_average_mark;
	float ice_average_mark;
	float overall_mark;
}STUDENT_REC;


/*******************************************************************************************************
*                                                                                                      *
*       Define a structure, called CLASS_STATS, to encapsulate the statistics of the class marks of a  *
* graded item (such as Assignment 1),  of an the average of a category of graded items (such as        *
* the average of all assignments) or of the midterm marks, the final exam marks, or the  overall mark. *
* The statistics must contain the following information: the highest mark, the lowest mark, and the    *
* average mark in the class.  The structure must also include a string (i.e. a char array) member      *
* named "description", indicating for what item the statistics is computed (e.g,  for "Assignment 1",  *
* for "overall mark", for "ice average" etc.                                                           *						       
*												       *
*       COMPLETE THE DEFINITION OF THE STRUCTURE BELOW                                                 *
*                                                                                                      *
*******************************************************************************************************/


typedef struct
{
    float highest_mark;
    float lowest_mark;
    float average_mark;
    char description[MAX_STRING_LENGTH];
}CLASS_STATS;


/*******************************************************************************************************
 *                                                                                                     *
 *     The following function asks the user to enter a string as a file name and has the string stored *
 * in the character array pointed to by the parameter filename.                                        *
 *                                                                                                     *
 *     IMPLEMENT THIS FUNCTION.                                                                        *
 *                                                                                                     *
 *******************************************************************************************************/

void getFileNameFromUser(char *filename)
{
    printf("Enter the file name: ");
    scanf("%s", filename);
}

/*******************************************************************************************************
 *                                                                                                     *
 *      The following function reads an ascii file containing the records of a class of students, and  *
 * load the records into an array of STUDENT_REC variables. The name of the file is passed into the    *
 * function by the parameter filename. The parameter classRec points to the array of STUDENT_REC       *
 * variables. After calling this function, the number of records read from the file is stored in the   *
 * variable pointed to by pNumStudents; the number of assignments, the number of ICEs, and the number  *
 * of labs are stored in the variables pointed to by pNumAssignments, pNumICEs, and pNumLabs           *
 * respectively.                                                                                       *
 *                                                                                                     *
 *                            IMPLEMENT THIS FUNCTION                                                  *
 *                                                                                                     *
 *******************************************************************************************************/

/*#define NUM_ASSIGNMENTS 5 
#define NUM_ICES 4
#define NUM_LABS 6 
#define MAX_MARK_PER_ASSIGNMENT 10
#define MAX_MARK_PER_LAB 20
#define MAX_MARK_PER_ICE 5
#define MAX_MARK_MIDTERM 100
#define MAX_MARK_FINAL_EXAM 100*/

void getClassRecordsFromFile(STUDENT_REC *classRec, int *pNumStudents, int *pNumAssignments, int *pNumICEs, 
                             int *pNumLabs, char* filename) {
    FILE *fp = fopen(filename, "r");
    if (!fp) {
        perror("Error opening file");
        exit(1);
    }

    // Read number of students
    fscanf(fp, "%d", pNumStudents);

    // Read number of assignments, ICEs, labs, and their maximum marks from line 2
    int maxMarkPerAssignment, maxMarkPerLab, maxMarkPerICE, maxMarkMidterm, maxMarkFinal;
    fscanf(fp, "%d %d %d %d %d %d %d %d", 
           pNumAssignments, pNumICEs, pNumLabs, 
           &maxMarkPerAssignment, &maxMarkPerLab, &maxMarkPerICE, 
           &maxMarkMidterm, &maxMarkFinal);

    // Read the student records
    for (int i = 0; i < *pNumStudents; i++) {
        fscanf(fp, "%d", &classRec[i].ID);
        for (int j = 0; j < *pNumAssignments; j++) {
            float rawMark;
            fscanf(fp, "%f", &rawMark);
            classRec[i].assignment_mark[j] = rawMark;
        }
        for (int j = 0; j < *pNumICEs; j++) {
            float rawMark;
            fscanf(fp, "%f", &rawMark);
            classRec[i].ice_mark[j] = rawMark;
        }
        for (int j = 0; j < *pNumLabs; j++) {
            float rawMark;
            fscanf(fp, "%f", &rawMark);
            classRec[i].lab_mark[j] = rawMark;
        }

        float rawMidterm, rawFinal;
        fscanf(fp, "%f %f", &rawMidterm, &rawFinal);
        classRec[i].midterm_mark = rawMidterm;
        classRec[i].final_mark = rawFinal;

        // Read computed averages and overall marks directly as percentages
        fscanf(fp, "%f %f %f %f",
               &classRec[i].assignment_average_mark,
               &classRec[i].ice_average_mark,
               &classRec[i].lab_average_mark,
               &classRec[i].overall_mark);
    }

    fclose(fp);
}





/*******************************************************************************************************
 *                                                                                                     *
 *       The following function prints to the screen an array of STUDENT_REC variables. Specifically   *
 * the parameter classRec points to the array and the parameter numOfStudents is the number of records *
 * to be printed. The parameters numAssignments, numICEs, and numLabs are respectively the number of   *
 * assignments, the number of ICEs and the number of labs in each record. The print-out begins with a  *
 * header line, indicating the description for each column. After the header line, each row contains   *
 * the record of a student.                                                                            *
 *                                                                                                     *
 *                            IMPLEMENT THIS FUNCTION                                                  *
 *                                                                                                     *
 *******************************************************************************************************/


void printClassRec(STUDENT_REC *classRec, int numOfStudents, int numAssignments, int numICEs, int numLabs) {
    // Print header row
    printf("%-10s", "ID");
    for (int i = 0; i < numAssignments; i++) {
        printf("A-%d%-9s", i + 1, "");
    }
    for (int i = 0; i < numICEs; i++) {
        printf("ICE-%d%-5s", i + 1, "");
    }
    for (int i = 0; i < numLabs; i++) {
        printf("Lab-%d%-5s", i + 1, "");
    }
    printf("%-10s%-10s%-12s%-10s%-10s%-10s\n", 
           "Midterm", "Final", "Assign Avg", "ICE Avg", "Lab Avg", "Overall");

    // Print student records with aligned columns
    for (int i = 0; i < numOfStudents; i++) {
        printf("%-10d", classRec[i].ID);
        for (int j = 0; j < numAssignments; j++) {
            printf("%-12.2f", classRec[i].assignment_mark[j]);
        }
        for (int j = 0; j < numICEs; j++) {
            printf("%-10.2f", classRec[i].ice_mark[j]);
        }
        for (int j = 0; j < numLabs; j++) {
            printf("%-10.2f", classRec[i].lab_mark[j]);
        }
        printf("%-10.2f%-10.2f%-12.2f%-10.2f%-10.2f%-10.2f\n", 
               classRec[i].midterm_mark, 
               classRec[i].final_mark, 
               classRec[i].assignment_average_mark, 
               classRec[i].ice_average_mark, 
               classRec[i].lab_average_mark, 
               classRec[i].overall_mark);
    }
}





/*******************************************************************************************************
 *                                                                                                     *
 *     The following function computes the statistics of   an array of marks and use this information  *
 * to fill a   CLASS_STATS variable. Specifically, it processes the marks stored in the array with     *
 * address pMarks and length numOfStudents; it stores the statistics of the marks in the members       *
 * of the CLASS_STRUCT variable pointed to by s; the parameter "description" is used to set the        *
 * the member "description" of the CLASS_STATS variable.                                               *
 *                                                                                                     *
 *     IMPLEMENT THIS FUNCTION.                                                                        *
 *                                                                                                     *
 *     The function strcpy (built in string.h) can be used to copy one string to another, as shown     *
 * in the following example, where array B will contain string "hello" after the execution of the code.*
 *                                                                                                     *
 *    char A[200]="hello";                                                                             *
 *    char B[200];                                                                                     *
 *    strcpy (B, A);                                                                                   *
 *                                                                                                     *
 *******************************************************************************************************/

void setClassStatsForItem(double *pMarks, int numOfStudents, CLASS_STATS *s, char *description)
{
    s->highest_mark = pMarks[0];
    s->lowest_mark = pMarks[0];
    s->average_mark = 0.0;

    for (int i = 0; i < numOfStudents; i++) {
        if (pMarks[i] > s->highest_mark) s->highest_mark = pMarks[i];
        if (pMarks[i] < s->lowest_mark) s->lowest_mark = pMarks[i];
        s->average_mark += pMarks[i];
    }
    s->average_mark /= numOfStudents;
    strcpy(s->description, description);

}


/*******************************************************************************************************
 *  												       *
 * 	The following function computes the statistics of all items from the records of a class of     *
 * students. These records are passed into the function via the parameter allRec, which points to an   *
 * array of STUDENT_REC variables. The parameter numOfStudents indicates the number of student records *
 * contained in the array. The number of assignments, the number of ICEs, and the number of labs are   *
 * passed into the function via the corresponding parameters. The parameter pAllStats points to an     *
 * array of CLASS_STATS variables, which will store the computed statistics of all items in the        *
 * records as well as their string description.  The number of CLASS_STATS variables filled with       *
 * the computed statitics will be stored in the variable with address pNumOfStats.       	       *
 * 												       *
 *  IMPLEMENT THIS FUNCTION. THE FUNCTION MUST CALL THE ABOVE FUNCTION setClassStatsForItem	       *
 *												       *
 * The function sprintf, which one can use to "print" a string and which can be used similarly  to     *
 * fprintf, may be helpful. For example the execution of the following code make char array A contain  *
 * string "The mark is 81".									       *
 *												       *
 * 	int mark=81;										       *
 * 	char A[200];										       *
 * 	sprintf(A, "The mark is %d", mark);							       * 
 *												       *
 *******************************************************************************************************/

void getClassStatsForAllItems(STUDENT_REC *allRec, int numOfStudents, int numAssignments, int numICEs, int numLabs, CLASS_STATS *pAllStats, int *pNumOfStats)
{
    int index = 0;
    double marks[LONG_ARRAY_LENGTH];
    char description[MAX_STRING_LENGTH];

    // Statistics for each assignment
    for (int i = 0; i < numAssignments; i++) {
        for (int j = 0; j < numOfStudents; j++) {
            marks[j] = allRec[j].assignment_mark[i];
        }
        sprintf(description, "Assignment %d", i + 1);
        setClassStatsForItem(marks, numOfStudents, &pAllStats[index++], description);
    }

    // Statistics for each ICE
    for (int i = 0; i < numICEs; i++) {
        for (int j = 0; j < numOfStudents; j++) {
            marks[j] = allRec[j].ice_mark[i];
        }
        sprintf(description, "ICE %d", i + 1);
        setClassStatsForItem(marks, numOfStudents, &pAllStats[index++], description);
    }

    // Statistics for each lab
    for (int i = 0; i < numLabs; i++) {
        for (int j = 0; j < numOfStudents; j++) {
            marks[j] = allRec[j].lab_mark[i];
        }
        sprintf(description, "Lab %d", i + 1);
        setClassStatsForItem(marks, numOfStudents, &pAllStats[index++], description);
    }

    // Statistics for midterm
    for (int j = 0; j < numOfStudents; j++) {
        marks[j] = allRec[j].midterm_mark;
    }
    setClassStatsForItem(marks, numOfStudents, &pAllStats[index++], "Midterm");

    // Statistics for final exam
    for (int j = 0; j < numOfStudents; j++) {
        marks[j] = allRec[j].final_mark;
    }
    setClassStatsForItem(marks, numOfStudents, &pAllStats[index++], "Final Exam");

    // Statistics for overall assignment average
    for (int j = 0; j < numOfStudents; j++) {
        marks[j] = allRec[j].assignment_average_mark;
    }
    setClassStatsForItem(marks, numOfStudents, &pAllStats[index++], "Overall Assignment Average");

    // Statistics for overall ICE average
    for (int j = 0; j < numOfStudents; j++) {
        marks[j] = allRec[j].ice_average_mark;
    }
    setClassStatsForItem(marks, numOfStudents, &pAllStats[index++], "Overall ICE Average");

    // Statistics for overall lab average
    for (int j = 0; j < numOfStudents; j++) {
        marks[j] = allRec[j].lab_average_mark;
    }
    setClassStatsForItem(marks, numOfStudents, &pAllStats[index++], "Overall Lab Average");

    // Update the number of statistics
    *pNumOfStats = index;
}



/*******************************************************************************************************
 *                                                                                                     *
 *      The following function prints to the screen the content of an array of CLASS_STATS variables.  *
 * The parameter allStats points to the array, and the parameter numStats is the number of CLASS_STATS *
 * variables in the array to be printed.                                                               *
 *                                                                                                     *
 *                          IMPLEMENT THIS FUNCTION                                                    *
 *                                                                                                     *
 *******************************************************************************************************/
 
void printAllStats(CLASS_STATS *allStats, int numStats) {
    printf("%-30s %10s %10s %10s\n", "Item", "Highest", "Lowest", "Average");
    printf("--------------------------------------------------------------\n");
    
    for (int i = 0; i < numStats; i++) {
        printf("%-30s %10.2f %10.2f %10.2f\n",
               allStats[i].description,
               allStats[i].highest_mark,
               allStats[i].lowest_mark,
               allStats[i].average_mark);
    }
}



/*******************************************************************************************************
 *                                                                                                     *
 *      The following function writes to an ascii file the content of an array of CLASS_STATS          *
 * variables.  The parameter allStats points to the array, the parameter numStats is the number of     *
 * CLASS_STATS variables in the array to be printed, the parameter filename points to the char array   *
 * containing the file name.                                                                           *
 *                                                                                                     *
 *                          IMPLEMENT THIS FUNCTION                                                    *
 *                                                                                                     *
 *******************************************************************************************************/

void printAllStatsToFile(CLASS_STATS *allStats, int numStats, char *filename)
{
	FILE *fp = fopen(filename, "w");
    if (!fp) {
        perror("Error opening file for writing");
        return;
    }

    fprintf(fp, "Item\tHighest\tLowest\tAverage\n");
    for (int i = 0; i < numStats; i++) {
        fprintf(fp, "%s\t%.2f\t%.2f\t%.2f\n",
                allStats[i].description,
                allStats[i].highest_mark,
                allStats[i].lowest_mark,
                allStats[i].average_mark);
    }

    fclose(fp);
  
}




/***** the main function; insert one line only as instructed *****/

int main()
{

	STUDENT_REC allRec[LONG_ARRAY_LENGTH];
	CLASS_STATS allStats[LONG_ARRAY_LENGTH];	
	int numOfStudents, numAssignments, numICEs, numLabs; 
	int numStats;
	char filename[MAX_STRING_LENGTH];


	getFileNameFromUser(filename);

/*******************************************************************************************************
 *                   ADD ONE LINE BELOW TO SHOW THE ENTERED FILE NAME                                  *
 *******************************************************************************************************/                    

	printf("You entered: %s\n", filename);


	getClassRecordsFromFile(allRec, &numOfStudents, &numAssignments, &numICEs, &numLabs, filename);
	printClassRec(allRec, numOfStudents, numAssignments, numICEs, numLabs);

	

	getClassStatsForAllItems(allRec, numOfStudents, numAssignments, numICEs, numLabs, allStats, &numStats);
	printAllStats(allStats, numStats);
	
	getFileNameFromUser(filename);
	printAllStatsToFile(allStats, numStats, filename);

	return 0;
}

