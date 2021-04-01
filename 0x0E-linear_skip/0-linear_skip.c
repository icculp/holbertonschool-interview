#include "search.h"

/**
* linear_skip - linear search in skip list
* @list: list to search
* @value: Value to search for
* Return: Pointer to node with value, or NULL
*/

skiplist_t *linear_skip(skiplist_t *list, int value)
{
	skiplist_t *ptr, *exp;
	int flag = 1;

	if (list == NULL)
		return(NULL);
	(void)value;
	ptr = list;
	while (ptr != NULL)
	{
		printf("Value checked at index [%d] = [%d]\n", (int)ptr->index, ptr->n);
		/**printf("while\n");*/
		if (ptr)
		{
			/**printf("23");*/
			exp = ptr->express;
			/**printf("25");*/
		}
		else
			return (NULL);
		/**printf("25");*/
		if (exp && (value == exp->n))
			return (exp);
		else if (value == ptr->n)
			return (ptr);
		else if (exp && (value > exp->n))
		{
			/**printf("34");*/
			ptr = exp;
			/**printf("36");*/
		}
		else if (ptr && ptr->next)
		{
			/**printf("40");*/
			if (flag)
			{
				printf("Value found between indexes [%d] and [%d]\n", (int)ptr->index, (int)exp->index);
				flag = 0;
			}
			ptr = ptr->next;
			/**printf("42");*/
		}
		else
		{
			/**printf("ELSE\n");*/
			return (NULL);
		}
	}
	/**printf("RETURNING\n");*/
	return(ptr);
}
