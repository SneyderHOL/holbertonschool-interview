#include <stdlib.h>
#include "binary_trees.h"

/**
 * heap_insert - inserts a value into a Max Binary Heap:
 * @root: is a double pointer to the root node of the Heap
 * @value:  is the value to store in the node to be inserted
 *
 * Return: a pointer to the inserted node, or NULL on failure
 */

heap_t *heap_insert(heap_t **root, int value)
{
	binary_tree_t *new_node = NULL;

	new_node = malloc(sizeof(binary_tree_t));
	if (new_node == NULL)
		return (NULL);
	new_node->parent = NULL;
	new_node->left = NULL;
	new_node->right = NULL;
	new_node->n = value;
	if (parent != NULL)
		new_node->parent = parent;
	return (new_node);
}
