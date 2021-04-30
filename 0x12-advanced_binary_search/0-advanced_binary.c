#include "search_algos.h"

/**
* printd - prints the subarray
* @a: array to print
* @l: left slice index
* @r: right slice index
*/

void printd(int *a, int l, int r)
{
	int i;

	printf("Searching in array: ");
	for (i = l; i < r + 1; i++)
	{
		if (i < r)
			printf("%d, ", a[i]);
		else
			printf("%d\n", a[i]);
	}
}

/**
* bin - binary recursive helper
* @a: array to search
* @l: left index
* @r: right index
* @v: Value to search for
* @s: size of array
* Return: index or -1 if not found
*/

int bin(int *a, int l, int r, int v, int s)
{
	int mid;

	if (r >= l)
	{
		printd(a, l, r);
		mid = l + (r - l) / 2;
		if (a[mid] == v && a[mid - 1] != v)
		{
			return (mid);
		}
		if (a[mid] >= v)
			return (bin(a, l, mid, v, s));
		return (bin(a, mid + 1, r, v, s));
	}

	return (-1);
}

/**
* advanced_binary - binary search returning first instance index
* @array: pointer to first element of array to search in
* @size: # of elements in array
* @value: value to search for
* Return: index where value is located at or -1
*/

int advanced_binary(int *array, size_t size, int value)
{
	int i;


	if (array == NULL || size < 1)
		return (-1);
	i = bin(array, 0, (int)size - 1, value, (int)size);
	return (i);
}
