#include "lists.h"
#include <stdio.h>

/**
 * check_cycle - checks linked list is circular or not
 * @list: linked list
 * Return: 1 circular, 0 not
 */
int check_cycle(listint_t *list)
{
	listint_t *n1 = list;
	listint_t *n2 = list;

	if (!list)
		return (0);

	while (1)
	{
		if (n1->next != NULL && n1->next->next != NULL)
		{
			n1 = n1->next->next;
			n2 = n2->next;
			if (n1 == n2)
				return (1);
		}
		else
			return (0);
	}
}
