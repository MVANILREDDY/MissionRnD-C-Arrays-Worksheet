/*
OVERVIEW: Given a sorted array, insert a given number into the array at appropriate position.
			E.g.: Arr = [2, 4, 6], num = 5 final Arr = [2, 4, 5, 6]. 5 is inserted at 2nd index.

INPUTS: Integer	Array pointer, length of the array, number to be inserted.

OUTPUT: Array pointer after inserting number.

ERROR CASES: Return NULL for invalid inputs.

NOTES: Use realloc to allocate memory.
*/

#include <stdio.h>
#include <malloc.h>

int * sortedArrayInsertNumber(int *Arr, int len, int num)
{
	int index = -5, i, count = 0, dup, temp;
	if ((Arr != NULL) &&len>0) //index is used for approriate position for given num,in given array.
	{
		for (i = 0; i<len; i++)
		{
			if (Arr[i]>num)
			{
				if (index == -5)
				{
					index = i;
				}
			}
			if (Arr[i]>Arr[i + 1] && i<len - 1)
			{
				count++;
			}
		}
		if (!count)//count is used to determine whether index lies within range of given array.
		{
			Arr = (int*)realloc(Arr, (len + 1)*sizeof(int));
			if (index == -5)
			{
				Arr[len] = num;
			}
			else 
			{    //shifting numbers after inserting num,at appropriate position.
				dup = Arr[index];
				Arr[index] = num;
				for (i = index + 1; i <= len; i++)
				{
					temp = Arr[i];
					Arr[i] = dup;
					dup = temp;
				}
			}
			return Arr;
		}
	}
	else
	{
		return NULL;
	}
}
