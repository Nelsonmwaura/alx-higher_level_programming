#include "lists.h"
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

listint_t *create_node(int n);

/**
 * insert_node - sorted singly linked lists
 * @head: pointer to the head of the linked list
 * @number: data
 * Return: address of new node, or NULL if failed
 */
listint_t *insert_node(listint_t **head, int number)
{
	listint_t *old_node = NULL, *new_node = NULL;

	if (!head)
		return (NULL);
	else if (!(*head))
	{
		new_node = create_node(number);
		*head = new_node;
		return (new_node);
	}
	old_node = *head;
	while (old_node)
	{
		if (old_node->n >= number)
		{
			new_node = create_node(number);
			new_node->next = old_node;
			*head = new_node;
			return (new_node);
		}
		else if (old_node->n <= number)
		{
			if (!old_node->next || old_node->next->n >= number)
			{
				new_node = create_node(number);
				new_node->next = old_node->next;
				old_node->next = new_node;
				return (old_node->next);
			}
		}
		old_node = old_node->next;
	}
	return (NULL);
}

/**
 * create_node - creates a node
 * @n: data to insert
 * Return: pointer to new node
 */
listint_t *create_node(int n)
{
	listint_t *ret = NULL;

	ret = malloc(sizeof(listint_t));
	if (!ret)
		return (NULL);
	ret->next = NULL;
	ret->n = n;
	return (ret);
}
