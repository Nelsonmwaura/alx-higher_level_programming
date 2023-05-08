#include "lists.h"

/**
 * check_cycle - checks linked list is circular or not
 * @list: linked list
 * Return: 1 circular, 0 not
 */
int check_cycle(listint_t *list)
{
	listint_t *n1 = NULL, *n2 = NULL;

	n1 = n2 = list;
	while (list && n1 && n2 && n1->next && n2->next)
	{
		n1 = n1->next;
		n1 = n2->next->next;
		if (!n2 || !n1)
			return (0);
		if (n2->next == n1)
			return (1);
	}
	return (0);
}
