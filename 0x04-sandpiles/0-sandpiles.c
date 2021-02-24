#include <stdio.h>
#include <stdlib.h>
#include "sandpiles.h"

/**
 * print_grid - Print 3x3 grid
 * @grid: 3x3 grid
 *
 */

void print_grid(int grid[3][3])
{
	int i, j;

	for (i = 0; i < 3; i++)
	{
		for (j = 0; j < 3; j++)
		{
			if (j)
				printf(" ");
			printf("%d", grid[i][j]);
		}
		printf("\n");
	}
}

/**
 * copy_grid - function that copies a grid
 * @grid1: grid to copy from
 * @grid2: grid to copy to
 *
 */

void copy_grid(int grid1[3][3], int grid2[3][3])
{
	int i = 0, j = 0;

	for (i = 0; i < 3; i++)
	{
		for (j = 0; j < 3; j++)
		{
			grid2[i][j] = grid1[i][j];
		}
	}
}


/**
 * is_stable - function that checks if a grid is a stable sandpile
 * @grid: grid to check
 *
 * Return: 1 if the grid is stable, 0 otherwise
 */

char is_stable(int grid[3][3])
{
	int i = 0, j = 0;

	for (i = 0; i < 3; i++)
	{
		for (j = 0; j < 3; j++)
		{
			if (grid[i][j] > 3)
				return (0);
		}
	}
	return (1);
}


/**
 * split - function that split the greater pile of sand to its neighbors
 * @grid1: unstable sandpile grid to based
 * @grid2: grid to apply the function
 *
 */

void split(int grid1[3][3], int grid2[3][3])
{
	int i = 0, j = 0;
	int left[2] = {0, 0}, right[2] = {0, 0}, up[2] = {0, 0}, down[2] = {0, 0};

	for (i = 0; i < 3; i++)
	{
		for (j = 0; j < 3; j++)
		{
			if (grid1[i][j] <= 3)
				continue;
			grid2[i][j] -= 4;
			left[0] = i;
			left[1] = j - 1;
			right[0] = i;
			right[1] = j + 1;
			up[0] = i - 1;
			up[1] = j;
			down[0] = i + 1;
			down[1] = j;
			if (!(left[0] < 0 || left[0] > 2 ||
			     left[1] < 0 || left[1] > 2))
				grid2[left[0]][left[1]] += 1;
			if (!(right[0] < 0 || right[0] > 2 ||
			      right[1] < 0 || right[1] > 2))
				grid2[right[0]][right[1]] += 1;
			if (!(up[0] < 0 || up[0] > 2 ||
			     up[1] < 0 || up[1] > 2))
				grid2[up[0]][up[1]] += 1;
			if (!(down[0] < 0 || down[0] > 2 ||
			      down[1] < 0 || down[1] > 2))
				grid2[down[0]][down[1]] += 1;
		}
	}
}


/**
 * sandpiles_sum - function that computes the sum of two sandpiles
 * @grid1: stable sandpile grid1
 * @grid2: stable sandpile grid2
 *
 */

void sandpiles_sum(int grid1[3][3], int grid2[3][3])
{
	int i = 0, j = 0;
	char is_grid_stable = 0;
	int aux_grid[3][3] = {{0, 0, 0}, {0, 0, 0}, {0, 0, 0}};

	copy_grid(grid1, aux_grid);
	for (i = 0; i < 3; i++)
	{
		for (j = 0; j < 3; j++)
		{
			grid1[i][j] = aux_grid[i][j] + grid2[i][j];
		}
	}
	is_grid_stable = is_stable(grid1);
	while (!is_grid_stable)
	{
		printf("=\n");
		print_grid(grid1);
		copy_grid(grid1, aux_grid);
		split(aux_grid, grid1);
		is_grid_stable = is_stable(grid1);
	}
}
