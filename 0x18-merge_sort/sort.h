#ifndef _SORT_H_
#define _SORT_H_
#include <stdio.h>
#include <stdlib.h>

/**
 * struct listint_s - Doubly linked list node
 *
 * @n: Integer stored in the node
 * @prev: Pointer to the previous element of the list
 * @next: Pointer to the next element of the list
 */
typedef struct listint_s
{
	const int n;
	struct listint_s *prev;
	struct listint_s *next;
} listint_t;

void merge_sort(int *array, size_t size);
void split_and_merge(int *array, size_t size, int *copy);
void print_side(int *array, size_t size);
void copy_array(int *array, size_t size, int *copy);
void print_array(const int *array, size_t size);

#endif
