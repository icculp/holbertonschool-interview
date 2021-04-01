#include "search.h"

/**
* linear_skip - linear search in skip list
* @list: list to search
* @value: Value to search for
* Return: Pointer to node with value, or NULL
*/

skiplist_t *linear_skip(skiplist_t *list, int value)
{
	skiplist_t *ptr;

	if (list == NULL)
		return(NULL);
	(void)value;
	ptr = NULL;
	return(ptr);
}
