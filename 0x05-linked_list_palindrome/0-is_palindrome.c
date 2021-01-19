#include "lists.h"

/**
* is_palindrome - Checks if values make palindrome
* @head: head node of linked list
* Return: 0 if not, 1 if it is
*/

int is_palindrome(listint_t **head)
{
	listint_t *temp;
	int count = 0, c, d, stack[1024], i;


	if (head == NULL)
		return (0);
	if (*head == NULL || (*head)->next == NULL)
		return (1);
	temp = *head;
	while (temp->next)
		temp = temp->next, count++;
	count++;
	c = count / 2;
	if (count % 2 == 0)
		d = 1;
	else
		d = 0;
	temp = *head;
	for (i = 0; i < c; i++)
	{
		stack[i] = temp->n;
		/**printf("temp->n: %d\n", temp->n);*/
		temp = temp->next;
	}
	i--;
	/**printf("temp->n %d\n", temp->next->n);*/
	if (d == 0)
		temp = temp->next, printf("D == 0\n");
	while (temp != NULL)
	{
		/**printf("temp->n %d, stacki %d\n", temp->n, stack[i]);*/
		if (temp->n != stack[i])
			return (0);
		temp = temp->next;
		i--;
	}
	/**printf("count: %d\n", count);*/
	return (1);
}
