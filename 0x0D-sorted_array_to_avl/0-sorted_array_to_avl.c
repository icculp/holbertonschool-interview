#include "binary_trees.h"

/**
* newNode - creates new node
* @data: value to add to node
* Return: node pointer
*/
avl_t *newNode(int data)
{
	avl_t *node;

	node = malloc(sizeof(avl_t));
	if (node == NULL)
		return (NULL);
	node->n = data;
	node->parent = NULL;
	node->left = NULL;
	node->right = NULL;
	return (node);
}

/**
* sortedArrayToBST - Inserts reursivley to BST
* @arr: Array slice to insert from
* @parent: Parent node to attach
* @start: start of slice
* @end: end of slice
* Return: root of tree
*/
avl_t *sortedArrayToBST(int arr[], avl_t *parent, int start, int end)
{
	avl_t *root;
	int mid;

	if (start > end || start < 0)
		return (NULL);
	mid = (start + end) / 2;
	/**printf("smash here");*/
	root = newNode(arr[mid]);
	root->parent = parent;
	root->left =  sortedArrayToBST(arr, root, start, mid - 1);
	root->right = sortedArrayToBST(arr, root, mid + 1, end);
	return (root);
}

/**
* sorted_array_to_avl - Converts sorted array to AVL tree
* @array: Sorted array to convert
* @size: Size of the tree
* Return: Pointer to root, or NULL on fail
*/

avl_t *sorted_array_to_avl(int *array, size_t size)
{
	avl_t *root = NULL;

	if (!array || size < 1)
		return (NULL);

	root = sortedArrayToBST(array, root, 0, size - 1);
	return (root);
}
