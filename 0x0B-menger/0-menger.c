#include "menger.h"



/**
* menger - draws a 2d menger sponge
* @level: level of menger sponge to draw (do nothing < 0)
*/

void menger(int level)
{
	int side = pow(3, level), i, j, d, dim;

	if (level < 0)
		return;
	if (level == 0)
	{
		printf("#\n");
		return;
	}
	for (i = 0, dim = 1; i < level; i++, dim *= 3)
		;
	for (i = 0; i < side; i++)
	{
		for (j = 0; j < side; j++)
		{
			for (d = dim / 3; d; d /= 3)
			{
				if ((i % (d * 3)) / d == 1 && (j % (d * 3)) / d == 1)
					break;
			}
			if (d)
			{
				printf(" ");
			}
			else
				printf("#");
		}
		printf("\n");

	}
}
