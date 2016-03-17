/*
OVERVIEW: In a given ascending sorted array, two numbers are changed their position, please fix those two numbers.
E.g.: In [10, 40, 30, 20, 50] 20 and 40 are swapped, so final output will be [10, 20, 30, 40, 50]

INPUTS: Ascending sorted array with two positions swapped, length of the array.

OUTPUT: Update sorted array by fixing swapped numbers.

ERROR CASES: Return NULL for invalid Inputs.

NOTES:
*/

#include <stdio.h>

void * sortedArrayPositionsChange(int *Arr, int len)
{
	int alt1, alt2, count = 0, i;
	if (!Arr || len<2)
	{
		return NULL;
	}
	else{
		for (i = 0; i<len - 1; i++)
		{
			if (count == 0 && Arr[i]>Arr[i + 1])
			{
				alt1 = i;
				count++;
				if (i == len - 2 && Arr[i + 1]<Arr[i])
				{
					alt2 = i + 1;
					count++;
				}

			}
			else if (count == 1 && Arr[i]>Arr[i + 1])
			{
				alt2 = i + 1;
				count++;
			}
		}
		if (count == 2)
		{
			Arr[alt1] = Arr[alt1] ^ Arr[alt2];
			Arr[alt2] = Arr[alt1] ^ Arr[alt2];//swapping using bitwise_xor.
			Arr[alt1] = Arr[alt1] ^ Arr[alt2];
		}
		else
		{
			return NULL;
		}
	}
}
