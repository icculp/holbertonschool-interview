#ifndef BIN_H
#define BIN_H

#include <stdio.h>
#include <stdlib.h>
#include <stddef.h>
#include <string.h>
#include <stdbool.h>
#include <limits.h>

/**
 * struct binary_tree_s - Binary tree node
 *
 * @n: Integer stored in the node
 * @parent: Pointer to the parent node
 * @left: Pointer to the left child node
 * @right: Pointer to the right child node
 */
struct binary_tree_s
{
	int n;
	struct binary_tree_s *parent;
	struct binary_tree_s *left;
	struct binary_tree_s *right;
};

typedef struct binary_tree_s binary_tree_t;
typedef struct binary_tree_s avl_t;



/**
* binary_tree_node - creates a binary tree node
* @parent: parent node pointer
* @value: value to put in node
* Return: pointer to new node, or NULL on failure
*/

binary_tree_t *binary_tree_node(binary_tree_t *parent, int value)
{
	binary_tree_t *new;

	new = malloc(sizeof(binary_tree_t));
	if (new == NULL)
		return (NULL);
	new->left = NULL;
	new->right = NULL;
	new->parent = parent;
	new->n = value;
	return (new);
}


void binary_tree_print(const binary_tree_t *tree);

int bstr(binary_tree_t *tree, int min, int max);
int binary_tree_is_bst(const binary_tree_t *tree);
size_t binary_tree_height(const binary_tree_t *tree);
bool avl(binary_tree_t *tree);
int binary_tree_is_avl(const binary_tree_t *tree);


#endif
