#include <stdlib.h>
#include <stdio.h>
#include "binary_trees.h"

/**
 * avl_tree - function to create an avl tree
 * @array: sorted array
 * @start: array's initial index
 * @end: array's end index
 * @root: root of the tree
 *
 * Return: pointer to the root of the tree
 */

avl_t *avl_tree(int *array, int start, int end, avl_t **root)
{
	int middle = 0;
	avl_t *aux = NULL, *right = NULL, *left = NULL;

	if (start > end)
		return (NULL);
	middle = (start + end) / 2;
	avl_tree(array, start, middle - 1, &left);
	avl_tree(array, middle + 1, end, &right);
	aux = malloc(sizeof(avl_t));
	if (aux == NULL)
		return (NULL);
	aux->n = array[middle];
	aux->left = left;
	aux->right = right;
	aux->parent = NULL;
	if (left != NULL)
		left->parent = aux;
	if (middle != start)
		right->parent = aux;
	*root = aux;
	return (aux);
}

/**
 * sorted_array_to_avl - builds an AVL tree from an array
 * @array: is a pointer to the first element of the array to
 * be converted
 * @size: is the number of element in the array
 *
 * Return: a pointer to the root node of the created AVL
 * tree, or NULL on failure
 */

avl_t *sorted_array_to_avl(int *array, size_t size)
{
	avl_t *root = NULL;

	if (array == NULL)
		return (NULL);
	if (avl_tree(array, 0, (int)size - 1, &root) == NULL)
		return (NULL);
	return (root);
}
