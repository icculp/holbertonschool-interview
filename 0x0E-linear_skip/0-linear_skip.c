#include "search.h"

/**
 * linear_skip - searches for a value in a sorted skip list
 * @list: list to search through
 * @value: value to search for
 *
 * Return: node where value is located, NULL otherwise
 */

skiplist_t *linear_skip(skiplist_t *list, int value)
{
	skiplist_t *temp = list, *temp2;

	if (list == NULL || list->n > value)
		return (NULL);
	while (temp && temp->express)
	{
		printf("Value checked at index [%d] = [%d]\n",
			(int)temp->express->index, temp->express->n);
		if (temp->express->n >= value)
			break;
		temp = temp->express;
	}
	if (temp->express)
		printf("Value found between indexes [%d] and [%d]\n",
			(int)temp->index, (int)temp->express->index);
	else
	{
		temp2 = temp;
		while (temp2->next)
			temp2 = temp2->next;
		printf("Value found between indexes [%d] and [%d]\n",
			(int)temp->index, (int)temp2->index);
	}
	while (temp->next && temp->next->n < value)
	{
		printf("Value checked at index [%d] = [%d]\n", (int)temp->index, temp->n);
		temp = temp->next;
	}
	printf("Value checked at index [%d] = [%d]\n", (int)temp->index, temp->n);
	if (temp->next && temp->next->n == value)
	{
		printf("Value checked at index [%d] = [%d]\n",
			(int)temp->next->index, temp->next->n);
		return (temp->next);
	}
	return (NULL);
}
