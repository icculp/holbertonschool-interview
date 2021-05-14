#include "binary_trees.h"

/**
* binary_tree_height - measure height of binary tree
* @tree: tree pointer
* Return: height
*/

int binary_tree_height(heap_t *tree)
{
	int left, right;

	if (tree == NULL)
		return (0);
	left = binary_tree_height(tree->left);
	right = binary_tree_height(tree->right);
	if (left > right)
	{
		if (tree->left == NULL && tree->right == NULL)
			return (left);
		else
			return (left + 1);
	}
	else
	{
		if (tree->left == NULL && tree->right == NULL)
			return (right);
		else
			return (right + 1);
	}
}

/**
* last - returns last node
* @tree: starting pointer
* @height: tree height
* @current: current height
* Return: last node in the heap
*/

heap_t *last(heap_t *tree, int height, int current)
{
	heap_t *temp;

	if (current >= (height - 1))
	{
		if (tree->right != NULL)
			return (tree->right);
		else
			return (tree->left);
	}
	temp = last(tree->right, height, current + 1);
	if (temp != NULL)
		return (temp);
	return (last(tree->left, height, current + 1));
}

/**
* heapify - heapify max binary heap
* @tree: pointer to node in heap
*/

void heapify(heap_t *tree)
{
	heap_t *largest;
	int n;

	if (!tree)
		return;
	largest = tree;
	if (tree->left && tree->left->n >= largest->n)
		largest = tree->left;
	if (tree->right)
	{
		if (largest == tree->left && tree->right->n > largest->n)
			largest = tree->right;
		else if (tree->right->n >= largest->n)
			largest = tree->right;
	}
	if (largest != tree)
	{
		n = tree->n;
		tree->n = largest->n;
		largest->n = n;
		heapify(largest);
	}
}


/**
* heap_extract - extracts root node of max binary heap; rebalances max heap
* @root: double pointer to root node
* Return: 0 on fail; otherwise value of root
*/

int heap_extract(heap_t **root)
{
	heap_t *temp;
	int height, val;

	if (root == NULL || *root == NULL)
		return (0);
	val = (*root)->n;
	temp = *root;
	height = binary_tree_height(*root) + 1;
	/**printf("height %d\n", height);*/
	if (height == 1)
	{
		temp = *root;
		*root = NULL;
		free(temp);
		return (val);
	}
	temp = last(*root, height, 1);
	(*root)->n = temp->n;
	if (temp->parent->right == temp)
		temp->parent->right = NULL;
	else if (temp->parent->left == temp)
		temp->parent->left = NULL;
	free(temp);
	heapify((*root));
	return (val);
}
