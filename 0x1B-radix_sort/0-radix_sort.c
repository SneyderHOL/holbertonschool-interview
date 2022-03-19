#include "sort.h"

/**
 * pow_then - calculates pow of 10
 * @pow: pow to calculate
 *
 * Return: 10 ^ number
 */

int pow_then(int pow)
{
	int i, result = 1;

	for (i = 0; i < pow; i++)
		result *= 10;

	return (result);
}

/**
 * sorting_matrix - sort by one digit in a matrix
 * @array: array to sort
 * @sorting: matrix to put the sorted numbers
 * @size: size of arrray
 * @l: digit to apply sortting
 * Return: 0 if the digit is the mostright digit, otherwise 1
 */


int sorting_matrix(int *array, int **sorting, size_t size, int l)
{
	int n, k, max = 0;
	int index[10] = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0};
	size_t i, j;

	for (i = 0; i < size; i++)
	{
		n = (array[i] % pow_then(l)) / pow_then(l - 1);
		sorting[n][index[n]++] = array[i];
		if (array[i] > max)
			max = array[i];
	}

	k = 0;
	j = 0;

	for (i = 0; i < 10; i++)
	{
		while (index[i] != 0 && k < index[i])
		{
			array[j + k] = sorting[i][k];
			k++;
		}
		j += k;
		k = 0;
	}
	print_array(array, size);

	if (max / pow_then(l) == 0)
		return (0);
	return (1);
}

/**
 * free_matrix - frees a matrix
 * @grid: double pointer to free
 * Return: Nothing (void)
 */

void free_matrix(int **grid)
{
	int i;

	for (i = 0; i < 10; i++)
		free(grid[i]);
	free(grid);
}

/**
 * radix_sort - sorts an array of integers in ascending order
 * using the Radix sort algorithm
 * @array: array to sort
 * @size: size of the array
 * Return: Nothing (void)
 */

void radix_sort(int *array, size_t size)
{
	int **sorting, aux = 1, l = 1;
	size_t i;

	if (array == NULL)
		return;
	if (size < 2)
		return;
	sorting = malloc(sizeof(int *) * 10);
	for (i = 0; i < 10; i++)
		sorting[i] = malloc(sizeof(int) * size);
	while (aux)
		aux = sorting_matrix(array, sorting, size, l++);
	free_matrix(sorting);
}
