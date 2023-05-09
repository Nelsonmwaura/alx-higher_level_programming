#include "lists.h"
#include <stddef.h>

/**
 * insert_node - sorted singly linked lists
 * @head: pointer to the head of the linked list
 * @number: data
 * Return: address of new node, or NULL if failed
 */
listint_t *insert_node(listint_t **head, int number)
{
	listint_t *tmp = NULL;
	listint_t *new = NULL;

	if (!head)
		return (NULL);

	new = malloc(sizeof(listint_t));
	if (new == NULL)
		return (NULL);
	new->num = number;
	new->next = NULL;

	if (*head == NULL)
	{
		*head = new;
		(*head)->next = NULL;
		return (new);
	}
	if ((*head)->next == NULL)
	{
		if ((*head)->n < new->n)
			(*head)->next = new;
		else
		{
			new->next = *head;
			*head = new;
		}
		return (new);
	}

	tmp = *head;
	while (tmp->next != NULL)
	{
		if (new->n < tmp->n)
		{
			new->next = tmp;
			*head = new;
			return (new);
		}
		
		if (((new->n > tmp->n) && (new->n < (tmp->next)->n)) || (new->n == tmp->n))
		{
			new->next = tmp->next;
			tmp->next = new;
			return (new);
		}
		tmp = tmp->next;
	}

	tmp->next = new;
	return (new);
}
