#include "sort.h"

/**
* merger - merges subarrays
* @array: original array
* @l: left index
* @m: middle index
* @r: right
*/
void merger(int *array, int l, int m, int r)
{
    int i, j, k, n1 = m - l + 1, n2 = r - m;
    int *L, *R;

    L = malloc(sizeof(int) * n1);
    R = malloc(sizeof(int) * n2);

    for (i = 0; i < n1; i++)
        L[i] = array[l + i];
    for (j = 0; j < n2; j++)
        R[j] = array[m + 1 + j];
    i = j = 0, k = l;
    printf("Merging...\n[left]: ");
    print_array(L, (size_t)n1);
    printf("[right]: ");
    print_array(R, (size_t)n2);
    while (i < n1 && j < n2)
    {
        if (L[i] <= R[j])
            array[k] = L[i], i++;
        else
            array[k] = R[j], j++;
        k++;
    }
    while (i < n1)
        array[k] = L[i], i++, k++;
    while (j < n2)
        array[k] = R[j], j++, k++;
    printf("[Done]: ");
    print_array(array + l, (size_t)r - l + 1);
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
