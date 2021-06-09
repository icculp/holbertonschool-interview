#include "sort.h"

/**
* merger - merges subarrays
* @array: original array
* @l: left index
* @m: middle index
* @r: right index
*/
void merger(int *array, int l, int m, int r)
{
	int i, j, k, n1 = m - l + 1, n2 = r - m;
	int *R;

	R = malloc(sizeof(int) * (n1 + n2));
	if (R == NULL)
		return;
	for (i = 0; i < n1; i++)
		R[i] = array[l + i];
	/**printf("iiii %d\n", i);*/
	for (j = i; j - i < n2; j++)
		R[j] = array[m + 1 + (j - i)];
	/** printf("i: %d, j: %d\n", i, j);*/
	/** print_array(R, (size_t) n1 + n2);*/
	j = i, i = 0, k = l;
	printf("Merging...\n[left]: ");
	print_array(R, (size_t)n1);
	printf("[right]: ");
	print_array(R + j, (size_t)n2);
	/** printf("-------\n");*/
	/** print_array(array, (size_t)r + 5); */
	/** print_array(R, (size_t)n1 + n2 + 2); */
	while (i < n1 && j - n1 < n2)
	{
		if (R[i] <= R[j])
			array[k] = R[i], i++;
		else
			array[k] = R[j], j++;
		k++;
	}
	/** printf("where go wrong\n");*/
	/**print_array(array, (size_t)r + 5);*/
	while (i < n1)
		array[k] = R[i], i++, k++;
	while (j - i < n2)
		array[k] = R[j], j++, k++;
	printf("[Done]: ");
	print_array(array + l, (size_t)r - l + 1);
	free(R);
	/** print_array(array, (size_t)r + 5);*/
}

/**
* merge_rec - recursive helper for merge_sort
* @array: array slice during splits
* @l: left index
* @r: right index
*/
void merge_rec(int *array, int l, int r)
{
	int m;

	if (l < r)
	{
		m = (l + (r - l - 1) / 2);
		merge_rec(array, l, m);
		merge_rec(array, m + 1, r);
		merger(array, l, m, r);
	}
}

/**
* merge_sort - top-down merge sort
* @array: Array to sort
* @size: size of array
*/
void merge_sort(int *array, size_t size)
{
	merge_rec(array, 0, (int)size - 1);
}
