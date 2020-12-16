#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "lists.h"

/**
 * main - check the code for Holberton School students.
 *
 * Return: Always 0.
 */
int main(void)
{
    listint_t *head, *head2, *head3;

    head = NULL;
	head2 = NULL;
	head3 = NULL;

    add_nodeint_end(&head, 0);
    add_nodeint_end(&head, 1);
    add_nodeint_end(&head, 2);
    add_nodeint_end(&head, 3);
    add_nodeint_end(&head, 4);
    add_nodeint_end(&head, 98);
    add_nodeint_end(&head, 402);
    add_nodeint_end(&head, 1024);
    print_listint(head);

    printf("-----------------\n");

    insert_node(&head, 27);

    print_listint(head);
    insert_node(&head, 1);
    printf("-----------------\n");
    print_listint(head);

    printf("-----------------\n");
    insert_node(&head, -1);
    print_listint(head);

    printf("-----------------\n");
    insert_node(&head2, 1024);
    print_listint(head2);

    printf("-----------------\n");
    head3 = insert_node(NULL, 1024);
    print_listint(head3);

    printf("-----------------\n");
    insert_node(&head, 1025);
    print_listint(head);


    printf("-----------------\n");
    free_listint(head);

    return (0);
}
