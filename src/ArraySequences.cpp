/*
Given an array which has two arithmetic sequences and 
one geometric sequence (in any order).
Copy indexes where each sequence starts and ends into an Array and return it.

Note : Each sequence will be of atleast LENGTH 3,and The sequences can be overlapping

Ex : 1, 3, 5, 7, 2, 4, 8, 16 18 20, output is [0, 3, 7, 9, 4, 7]
Ex : 1 ,2, 4, 8, 12, 16, 21, 26     output is [2, 5, 5, 7, 0, 3]
Ex : 10 15 20 30 50 70 100 200 400 800  output is [0, 2, 3, 5, 6, 9]

The final_arr[0], final_arr[1] values in final array  
will be start and end indexes of First A.P in the Original Array

The final_arr[2], final_arr[3] values in final array  
will be start and end indexes of Second A.P 

The final_arr[4], final_arr[5] values in final array  
will be start and end indexes of First  G.P (Only)

Input: Array and Length of Array
Output : New Array which has 6 integers , which denote the (start,end) indexes .

Note : All elements in the array will be part of atleast 1 sequence .
Two A.P cannot start at same index . 

Difficulty : Medium
*/

#include <stdlib.h>
#include <stdio.h>
#include <math.h>

int * find_sequences(int *arr, int len){
	if (arr != NULL && len >= 3)
	{
		printf("in program");
		int final[6] = { 0 };
		int i = 0, x = 0, start = 0, stop = 0, t = 0, y = 0, z = 0;
		float d = 0;
		while (t <= len - 3)
		{
			x = arr[t];
			y = arr[t + 1];
			d = y - x;
			z = arr[t + 2];
			if (d == z - y)
			{
				start = t;
				break;
			}
			else
			{
				t++;
			}

		}
		final[0] = start;
		for (i = start; i <= len - 2; i++)
		{
			if (d == arr[i + 1] - arr[i])
			{
			}
			else
			{
				stop = i;
				break;
			}
		}
		final[1] = stop;
		t = stop;
		while (t <= len - 3)
		{
			x = arr[t];
			y = arr[t + 1];
			d = y - x;
			z = arr[t + 2];
			if (d == z - y)
			{
				start = t;
				break;
			}
			else
			{
				t++;
			}
		}
		final[2] = start;
		for (i = start; i <= len - 2; i++)
		{
			if (d == arr[i + 1] - arr[i])
			{
				printf("whr i wanted");
				stop = i + 1;
			}
			else
			{
				stop = i;
				break;
			}
		}
		final[3] = stop;
		t = 0; start = 0; stop = 0;
		while (t <= len - 3)
		{
			x = arr[t];
			y = arr[t + 1];
			d = y / x;
			z = arr[t + 2];
			if (d == z / y)
			{
				start = t;
				break;
			}
			else
			{
				t++;
			}
		}
		final[4] = start;
		for (i = start; i <= len - 2; i++)
		{
			if (d == arr[i + 1] / arr[i])
			{
				stop = i + 1;
			}
			else
			{
				stop = i;
				break;
			}
		}
		final[5] = stop;
		for (i = 0; i<6; i++)
		{
			printf("%d", final[i]);
		}
		return final;
	}
	else{
		//Return final array which has 6indexes [AP1_S,AP1_E,AP2_S,AP2_E,GP1_S,GP2_E]
		return NULL;
	}
}