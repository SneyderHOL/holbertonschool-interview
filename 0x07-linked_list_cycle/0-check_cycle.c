#include <stdlib.h>
#include "lists.h"
/**
 * check_cycle - function that finds the loop in a linked list.
 * @list: pointer to the head of a listint element
 * Return: 0 if there is no cycle, 1 if there is a cycle
 */
int check_cycle(listint_t *list)
{
	listint_t *hare = list;
	listint_t *turtle = list;

	if (list == NULL || list->next == NULL)
		return (0);
	turtle = turtle->next;
	hare = hare->next->next;
	while (turtle != NULL && hare != NULL && hare->next)
	{
		if (turtle == hare)
		{
			hare = list;
			while (turtle != hare)
			{
				turtle = turtle->next;
				hare = hare->next;
			}
			return (1);
		}
		turtle = turtle->next;
		hare = hare->next->next;
	}

	return (0);
}

