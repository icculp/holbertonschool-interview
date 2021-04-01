#include "search.h"


/**
 * main - Entry point
 *
 * Return: Always EXIT_SUCCESS
 */
int main(void)
{
    skiplist_t *list, *list2, *res;
    int array[] = {
        0, 1, 2, 3, 4, 7, 12, 15, 18, 19, 23, 53, 61, 62, 76, 99
    };
    int array2[] = {1, 2};
    size_t size = sizeof(array) / sizeof(array[0]), size2 = sizeof(array2) / sizeof(array2[0]);

    list = create_skiplist(array, size);
    list2 = create_skiplist(array2, size2);
    print_skiplist(list);

    res =  linear_skip(list2, 1);
    printf("Found %d at index: %lu\n\n", 1, res->index);
    res =  linear_skip(list, 2);
    printf("Found %d at index: %lu\n\n", 2, res->index);
    res =  linear_skip(list, 999);
    printf("Found %d at index: %p\n", 999, (void *) res);

    free_skiplist(list);
    return (EXIT_SUCCESS);
}
