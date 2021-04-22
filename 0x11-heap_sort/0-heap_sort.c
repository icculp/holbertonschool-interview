#include "sort.h"

/**
* max - function to determine max of two values
* @a: array to find max of
* @n: size of array
* @i: current index
* @j: left binary multiple
* @k: right binary multiple
* Return: Index of max
*/

int max(int *a, int n, int i, int j, int k)
{
	int m = i;

	if (j < n && a[j] > a[m])
	{
		m = j;
	}
	if (k < n && a[k] > a[m])
	{
		m = k;
	}
	return (m);
}

/**
* downheap - siftdown heapfiy algorithm
* @a: array to sift down
* @n: size of subarray to sift
* @i: current index
* @size: Total size of original array (for printing)
*/

void downheap(int *a, int n, int i, size_t size)
{
	int j, t;

	while (1)
	{
		j = max(a, n, i, 2 * i + 1, 2 * i + 2);
		if (j == i)
		{
			break;
		}
		t = a[i];
		a[i] = a[j];
		a[j] = t;
		i = j;
		print_array(a, size);
	}
}


/**
* heap_sort - Heap sort via sift-down
* @array: array to be sorted
* @size: Size of array to sort
*/

void heap_sort(int *array, size_t size)
{
	int i, t;

	for (i = ((int)size - 2) / 2; i >= 0; i--)
	{
		downheap(array, (int)size, i, size);
		/** print_array(array, size); */
	}
	for (i = 0; i < (int)size; i++)
	{
		t = array[(int)size - i - 1];
		array[(int)size - i - 1] = array[0];
		array[0] = t;
		if (i != (int)size - 1)
			print_array(array, size);
		downheap(array, (int)size - i - 1, 0, size);
	}

}
