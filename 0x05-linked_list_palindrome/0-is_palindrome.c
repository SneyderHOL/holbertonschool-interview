#include <stdlib.h>
#include "lists.h"
/**
 *get_length - function that return the length of a singly linked list
 *@head: pointer to the head of the list
 *
 *Return: an integer with the length of the list
 */

int get_length(listint_t *head)
{
	int length = 1;

	while (head->next != NULL)
	{
		length++;
		head = head->next;
	}
	return (length);
}
/**
 *is_palindrome - function that checks if a singly linked list is a palindrome
 *@head: pointer to the head of the list
 *
 *Return: 1 if is a palindrome or 0 otherwise
 */
int is_palindrome(listint_t **head)
{
	listint_t *aux, *tail = NULL;
	int length = 0, half = 0;

	if (head == NULL || *head == NULL)
		return (1);
	aux, tail = *head;
	length = get_length(tail);
	half = lenght / 2;
	return (1);
}
