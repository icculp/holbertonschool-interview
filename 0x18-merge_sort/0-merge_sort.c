#include "sort.h"

/**
* merger - merges subarrays
* @array: original array
* @l: left index
* @m: middle index
* @r: right index
* @temp: temp array for merging
*/
void merger(int *array, int l, int m, int r, int *temp)
{
	int i, j, k, n1 = m - l + 1, n2 = r - m;

	for (i = 0; i < n1; i++)
		temp[i] = array[l + i];
	/**printf("iiii %d\n", i);*/
	for (j = i; j - i < n2; j++)
		temp[j] = array[m + 1 + (j - i)];
	/** printf("i: %d, j: %d\n", i, j);*/
	/** print_array(R, (size_t) n1 + n2);*/
	j = i, i = 0, k = l;
	printf("Merging...\n[left]: ");
	print_array(temp, (size_t)n1);
	printf("[right]: ");
	print_array(temp + j, (size_t)n2);
	/** printf("-------\n");*/
	/** print_array(array, (size_t)r + 5); */
	/** print_array(R, (size_t)n1 + n2 + 2); */
	while (i < n1 && j - n1 < n2)
	{
		if (temp[i] <= temp[j])
			array[k] = temp[i], i++;
		else
			array[k] = temp[j], j++;
		k++;
	}
	/** printf("where go wrong\n");*/
	/**print_array(array, (size_t)r + 5);*/
	while (i < n1)
		array[k] = temp[i], i++, k++;
	while (j - i < n2)
		array[k] = temp[j], j++, k++;
	printf("[Done]: ");
	print_array(array + l, (size_t)r - l + 1);
	/** print_array(array, (size_t)r + 5);*/
}

/**
* merge_rec - recursive helper for merge_sort
* @array: array slice during splits
* @l: left index
* @r: right index
* @temp: temp array for merging
*/
void merge_rec(int *array, int l, int r, int *temp)
{
	int m;

	if (l < r)
	{
		m = (l + (r - l - 1) / 2);
		merge_rec(array, l, m, temp);
		merge_rec(array, m + 1, r, temp);
		merger(array, l, m, r, temp);
	}
}

/**
* merge_sort - top-down merge sort
* @array: Array to sort
* @size: size of array
*/
void merge_sort(int *array, size_t size)
{
	int *temp;

	temp = malloc(sizeof(int) * size);
	merge_rec(array, 0, (int)size - 1, temp);
	free(temp);
}
