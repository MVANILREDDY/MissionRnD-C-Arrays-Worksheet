/*
OVERVIEW:  You are given scores for students of a class in alphabetical order. Write a function that sorts these scores in descending order.
Input is array of structures of type student (each student has name and score).
E.g.: If input is [ { "stud1", 20 }, { "stud2", 30 }, { "stud3", 40 } ] (three students with marks 20, 30 , 40).
Output for this will be [ { "stud3", 40 }, { "stud2", 30 }, { "stud1", 20 } ]

INPUTS: Array of structures of type student, length of array.

OUTPUT: Sort the array in descending order of scores.

ERROR CASES: Return NULL for invalid Inputs.

NOTES:
*/

#include <stdio.h>

struct student {
	char name[10];
	int score;
};
void quicksort(struct student *students, int , int );

void * scoresDescendingSort(struct student *students, int len) 
{
	int i, j;
	struct student a;
	if ((students != NULL) && len>0)
	{
		quicksort(students, 0, len - 1);
	}
	else
	{
		return NULL;
	}
}
void quicksort(struct student *students, int start, int end)
{
	int i, j, pivot; //i & j indexes used while traversing given structure from first and last.
	struct student temp;//start & end are used for storing starting and ending indexes of  given structure.

	if (start<end){   //pivot is an  reference index,comparing with that index value,values are swapped greater & lower than that value.
		pivot = start;
		i = start;
		j = end;

		while (i<j)
		{
			while (students[i].score >= students[pivot].score&&i<end)
				i++;
			while (students[j].score<students[pivot].score)
				j--;
			if (i<j){
				temp = students[i];
				students[i] = students[j];
				students[j] = temp;
			}
		}
		temp = students[pivot];
		students[pivot] = students[j]; //swapping takes place.
		students[j] = temp;
		quicksort(students, start, j - 1);
		quicksort(students, j + 1, end);

	}
}

