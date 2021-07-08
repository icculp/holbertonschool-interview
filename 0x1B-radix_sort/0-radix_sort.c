#include "sort.h"

/**
* get_max - gets max value from array
* @array: array to pull max from
* @size: size of array
* Return: max value
*/

int get_max(int *array, size_t size)
{
	int max = array[0], i;

	for (i = 1; i < (int)size; i++)
	{
		if (array[i] > max)
			max = array[i];
	}
	return (max);
}

/**
* radix_sort - sorts via radix algo
* @array: array to sor
* @size: size of array
*/

void radix_sort(int *array, size_t size)
{
	if (size < 2)
		return;
	print_array(array, size);
}
