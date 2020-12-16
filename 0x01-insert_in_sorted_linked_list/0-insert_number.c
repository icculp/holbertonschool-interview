#include "lists.h"

/**
* insert_node - Inserts a node into a singly linked list
* @head: Head of linked list
* @number: Number to insert
* Return: Pointer to node
*/

listint_t *insert_node(listint_t **head, int number)
{
	listint_t *temp, *next;
	listint_t *new;

	new = malloc(sizeof(listint_t));
	if (new == NULL || head == NULL)
		return (NULL);
	new->n = number;
	if (*head == NULL)
	{
		*head = new;
		new->next = NULL;
		return (new);
	}
	temp = *head;
	if (number <= temp->n)
	{
		new->next = temp;
		*head = new;
		temp = NULL;
	}
	while (temp)
	{
		next = temp->next;
		if (next && (number <= next->n))
		{
			temp->next = new;
			new->next = next;
			return (new);
		}
		if (temp->next)
			temp = temp->next;
		else
		{
			temp->next = new;
			new->next = NULL;
			break;
		}
	}
	
	return (new);
}
