/*
OVERVIEW:  given an array that has duplicate values remove all duplicate values.
E.g.: input: [1, 1, 2, 2, 3, 3], output [1, 2, 3]

Ex 2: [4,4,2,2,1,5] output : [4,2,1,5]

INPUTS: Integer array and length of the array .

OUTPUT: Update input array by removing duplicate values and return the final array length

ERROR CASES: Return -1 for invalid inputs.

NOTES: Don't create new array, try to change the input array.
*/

#include <stdio.h>

int removeArrayDuplicates(int *Arr, int len)
{
		int i, j = 0, count = 0, m, uniq_count;
	uniq_count = len;
	if (Arr&&len>0) //NuLLcheck & invalid inputs.
	{
		if (len == 1)
		{
			return 1;
		}
		else
		{
			for (i = 1; i<len; i++)//i value is used to acess elements of given array while traversing.
			{
				m = 0;
				while (m <= j)
				{
					if (Arr[i] == Arr[m])
					{
						count++;
					}
					m++;
				}
				if (count>0)
				{
					count = 0;
					uniq_count--;//uniq_count used to determine length of array after deleting duplicates in given array.
				}
				else
				{
					j++;   
					Arr[j] = Arr[i];
				}
              }
			return uniq_count;
		}
	}
	else
	{
		return -1;
	}
}