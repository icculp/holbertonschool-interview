#include "binary_trees.h"

/**
* count - Counts number of nodes in binary tree
* @root: root node
* Return: N, size of tree/count of nodes
*/

int count(heap_t *root)
{
	int c = 1;

	if (root == NULL)
		return (0);
	if (root->left != NULL)
		c += count(root->left);
	if (root->right != NULL)
		c += count(root->right);
	return (c);
}

/**
* end - Finds and inserts at end of complete binary tree
* @root: root node of tree
* @c: Size of tree
* @new: New node to insert
* Return: pointer of new node
*/

heap_t *end(heap_t **root, int c, heap_t **new)
{
	int q, r, i = 0, s[1024];
	heap_t *end = *root;

	if (c == 1)
	{
		end->left = *new, (*new)->parent = *root;
		return (*new);
	}
	else if (c == 2)
	{
		end->right = *new, (*new)->parent = *root;
		return (*new);
	}
	c++, r = c % 2, q = c / 2;
	for (i = 0; i < 1024; i++)
		s[i] = 2;
	i = 0;
	while (1)
	{
		if (r == 1)
			s[i] = 1;
		else if (r == 0)
			s[i] = 0;
		if (q == 1)
			break;
		r = q % 2, q = q / 2, i++;
	}
	for (; i > 0; i--)
	{
		if (s[i] == 1)
			end = end->right;
		else if (s[i] == 0)
			end = end->left;
	}
	if (s[0] == 1)
		end->right = *new;
	else if (s[0] == 0)
		end->left = *new;
	(*new)->parent = end;
	return (*new);
}

/**
* heapify - Swaps order to ensure max heap
* @new: Last node inserted to heapify
* Return: Node where new node is now at
*/

heap_t *heapify(heap_t *new)
{
	heap_t *temp = new;
	int t;

	while (new->parent)
	{
		if (new->n > new->parent->n)
		{
			t = new->n, new->n  = new->parent->n;
			new->parent->n = t;
			temp = new->parent;
		}
		new = new->parent;
	}
	return (temp);

}

/**
* heap_insert - Inserts into a heap
* @root: root node
* @value: value
* Return: N
*/

heap_t *heap_insert(heap_t **root, int value)
{
	heap_t *new;
	int c = 0;

	if (root == NULL)
	{
		return (NULL);
	}
	new = malloc(sizeof(heap_t));
	if (new == NULL)
		return (NULL);
	c = count(*root);
	new->parent = *root;
	new->n = value;
	new->left = NULL;
	new->right = NULL;
	if (c == 0)
		*root = new;
	else
		new = end(root, c, &new);
	new = heapify(new);
	return (new);
}
