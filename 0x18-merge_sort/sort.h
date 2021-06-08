#ifndef SORT_H
#define SORT_H

#include <stdio.h>
#include <stdlib.h>

void print_array(const int *array, size_t size);
void merge_sort(int *array, size_t size);
void merger(int *array, int l, int m, int r);
void merge_rec(int *array, int l, int r);

#endif
