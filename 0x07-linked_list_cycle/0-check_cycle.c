#include "lists.h"

/**
* check_cycle - checks if a linked list has a cycle
* @list: list to check
* Return: 0 if no cycle, 1 if there is
*/

int check_cycle(listint_t *list)
{
	listint_t *turtle, *hare;

	if (list == NULL)
		return (0);
	turtle = hare = list;
	while (turtle && hare)
	{
		if (turtle->next)
			turtle = turtle->next;
		else
			break;
		if (hare->next && hare->next->next)
			hare = hare->next->next;
		else
			break;
		if (turtle == hare)
			return (1);
	}
	return (0);
}
