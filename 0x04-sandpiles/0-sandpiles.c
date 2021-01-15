#include "sandpiles.h"


/**
* print_grid - prints a 3x3 grid
* @grid: the grid
*/

static void print_grid(int grid[3][3])
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
* sandpiles_sum - Computes sum of two sandpiles
* @grid1: First grid 3x3 grid (0-3)
* @grid2: Second 3x3 grid (0-3)
*/

void sandpiles_sum(int grid1[3][3], int grid2[3][3])
{
	int i, j;

	for (i = 0; i < 3; i++)
		for (j = 0; j < 3; j++)
			grid1[i][j] += grid2[i][j];
	print_grid(grid1);
}
