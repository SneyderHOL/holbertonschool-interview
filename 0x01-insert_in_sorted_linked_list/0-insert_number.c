#include <stdio.h>
#include <stdlib.h>
#include "lists.h"

/**
 * insert_node - inserts a number into a sorted singly linked list
 * @head: pointer to head of list
 * @number: number to insert
 *
 * Return: the address of the new node, or NULL if it failed
 */

listint_t *insert_node(listint_t **head, int number)
{
	listint_t *aux = *head, *prev = *head, *new_node = NULL;

	if (head == NULL)
		return (NULL);
	new_node = malloc(sizeof(listint_t));
	if (new_node == NULL)
		return (NULL);
	new_node->n = number;
	new_node->next = NULL;
	if (*head == NULL)
	{
		*head = new_node;
		return (new_node);
	}
	while (aux->next != NULL && aux->n < number)
	{
		prev = aux;
		aux = aux->next;
	}
	if (aux->n < number)
		aux->next = new_node;
	else
	{
		if (prev != aux)
			prev->next = new_node;
		else
			*head = new_node;
		new_node->next = aux;
	}
	return (new_node);
}
