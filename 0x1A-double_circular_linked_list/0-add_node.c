#include "list.h"

/**
* add_node_end - adds node to end of dlist
* @list: list to add to
* @str: str to append to list
* Return: ptr to node or null
*/

List *add_node_end(List **list, char *str)
{
	List *temp, *new;

	new = malloc(sizeof(List));
	if (new == NULL)
		return (NULL);
	new->str = strdup(str);
	new->prev = new;
	new->next = new;
	if (*list == NULL)
	{
		*list = new;
		return (*list);
	}
	temp = new->next = *list;
	(*list)->prev = new;
	while (temp->next != NULL && temp->next != *list)
		temp = temp->next;
	temp->next = new;
	new->prev = temp;
	return (new);
}

/**
* add_node_begin - adds node to begining of dlist
* @list: list to add to
* @str: str to append to list
* Return: ptr to node or null
*/

List *add_node_begin(List **list, char *str)
{
	List *new;

	new = malloc(sizeof(List));
	if (new == NULL)
		return (NULL);
	new->str = strdup(str);
	new->prev = new;
	new->next = new;
	if (*list == NULL)
	{
		*list = new;
		return (*list);
	}
	new->prev = (*list)->prev;
	(*list)->prev->next = new;
	(*list)->prev = new;
	new->next = *list;
	*list = new;
	return (new);
}
