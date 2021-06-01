#include "lists.h"

/**
* find_listint_loop - find cycle in linked list
* @head: head of list
* Return: node of cycle or NULL
*/

listint_t *find_listint_loop(listint_t *head)
{
	listint_t *turtle, *hare;

	if (head == NULL)
		return (NULL);
	turtle = hare = head;
	while (turtle && hare && hare->next)
	{
		if (turtle->next)
			turtle = turtle->next;
		if (hare->next && hare->next->next)
			hare = hare->next->next;
		else
			return (NULL);
		if (turtle == hare)
		{
			turtle = head;
			while (turtle && hare && hare->next)
			{
				if (turtle == hare)
					return (turtle);
				turtle = turtle->next;
				hare = hare->next;
			}
		}
	}
return (NULL);
}
