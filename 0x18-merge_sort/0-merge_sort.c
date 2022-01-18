#include "sort.h"

/**
 * merge_sort - function that sorts an array of integers in ascending order
 * using the Merge sort algorithm
 * @array: pointer to the array to sort
 * @size: size of the array
 *
 */
void merge_sort(int *array, size_t size)
{
	int *copy = NULL;

	copy = malloc(sizeof(int) * size);
	if (copy == NULL)
		return;
	copy_array(array, size, copy);
	split_and_merge(array, size, copy);
	free(copy);
}
/**
 * split_and_merge - function that splits and merge two arrays
 * @array: pointer to the array to copy from
 * @size: size of the array
 * @copy: pointer to an array to copy to
 *
 */
void split_and_merge(int *array, size_t size, int *copy)
{
	size_t n = 0, i = 0, j = 0, k = 0;

	if (array == NULL || size <= 1)
		return;

	n = size / 2;
	split_and_merge(array, n, copy);
	split_and_merge(array + n, size - n, copy + n);

	printf("Merging...\n");
	printf("[left]: ");
	print_side(array, n);
	printf("[right]: ");
	print_side(array + n, size - n);
	copy_array(array, size, copy);
	j = 0;
	k = n;
	for (i = 0; i < size; i++)
	{
		if (j < n && (k >= size || copy[j] <= copy[k]))
		{
			array[i] = copy[j];
			j++;
		}
		else
		{
			array[i] = copy[k];
			k++;
		}
	}
	printf("[Done]: ");
	print_side(array, size);
}
/**
 * print_side - function that prints an array
 * @array: pointer to the array to sort
 * @size: size of the array
 *
 */
void print_side(int *array, size_t size)
{
	size_t i = 0;

	for (i = 0; i < size; i++)
	{
		printf("%d", array[i]);
		if (i != size - 1)
			printf(", ");
	}
	printf("\n");
}
/**
 * copy_array - function that copys an array
 * @array: pointer to the array to copy from
 * @size: size of the array
 * @copy: pointer to the array to copy to
 *
 */
void copy_array(int *array, size_t size, int *copy)
{
	size_t i = 0;

	for (i = 0; i < size; i++)
		copy[i] = array[i];
}
