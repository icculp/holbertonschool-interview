#include "search.h"

/**
* linear_skip - linear search in skip list
* @list: list to search
* @value: Value to search for
* Return: Pointer to node with value, or NULL
*/

skiplist_t *linear_skip(skiplist_t *list, int value)
{
	skiplist_t *ptr = list, *exp;
	int flag = 1;

	while (ptr != NULL)
	{
		if (ptr)
			exp = ptr->express;
		else
			return (NULL);
		if (exp && (value == exp->n))
			return (exp);
		else if (ptr && value == ptr->n)
		{
			printf("Value checked at index [%d] = [%d]\n", (int)ptr->index, ptr->n);
			return (ptr);
		}
		else if (exp && (value > exp->n))
		{
			printf("Value checked at index [%d] = [%d]\n", (int)exp->index, exp->n);
			ptr = exp;
		}
		else if (ptr && ptr->next)
		{
			if (flag)
			{
				if (!exp)
				{ /** last node not express, find last node */
					exp = ptr;
					while (exp->next)
						exp = exp->next;
				}
				printf("Value checked at index [%d] = [%d]\n", (int)exp->index, exp->n);
				printf("Value found between indexes [%d] and [%d]\n",
					(int)ptr->index, (int)exp->index), flag = 0;
			}
			else
			{
				printf("Value checked at index [%d] = [%d]\n", (int)ptr->index, ptr->n);
				ptr = ptr->next;
			}
		}
		else
			return (NULL);
	}
	return (ptr);
}
