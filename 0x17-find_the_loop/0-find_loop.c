#include <stdlib.h>
#include "lists.h"
/**
 * find_listint_loop - function that finds the loop in a linked list.
 * @head: pointer to the head of a listint element
 * Return: the address of the node where the loop starts, or NULL if there is
 * no loop.
 */
listint_t *find_listint_loop(listint_t *head)
{
	listint_t *hare = head;
	listint_t *turtle = head;

	if (head == NULL || head->next == NULL)
		return (NULL);
	turtle = turtle->next;
	hare = hare->next->next;
	while (turtle != NULL && hare != NULL && hare->next)
	{
		if (turtle == hare)
		{
			hare = head;
			while (turtle != hare)
			{
				turtle = turtle->next;
				hare = hare->next;
			}
			return (hare);
		}
		turtle = turtle->next;
		hare = hare->next->next;
	}

	return (NULL);
}
