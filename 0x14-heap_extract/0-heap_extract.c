#include "binary_trees.h"

/**
* heap_extract - extracts root node of max binary heap; rebalances max heap
* @root: double pointer to root node
* Return: 0 on fail; otherwise value of root
*/

int heap_extract(heap_t **root)
{
	if (root == NULL || *root == NULL)
		return (0);
	return ((*root)->n);
}
