#include "holberton.h"
#define MAX 1000000


/**
* _strlen - Determines the length of the string manually
* @s: Pointer to array of characters
* Return: Value of length
*/

int _strlen(char *s)
{
	int i = 0;

	while (s[i] != '\0')
		i++;
	return (i);
}

/**
* *main - Multiplies two big-ass numbers
* @argc: Number of args
* @argv: Args stored as strings
* Return: Success
*/

int main(int argc, char *argv[])
{
	char *c;
	char *error;
	int i;

	if (argc != 3)
	{
		error = "Error\n";
		for (i = 0; i < _strlen(error); i++)
		{
			_putchar(error[i]);
		}
		exit(98);
	}
	c = multiply(argv[1], argv[2]);
	for (i = 0; i < _strlen(c); i++)
	{
		if (c[i] == '0' && i == 0)
		{
			while (c[i + 1] == '0')
			{
				i++;
			}
			if (i == _strlen(c) - 1)
				_putchar('0');
		}
		else
			_putchar(c[i]);
	}
	_putchar('\n');
	return (0);
}

/**
* *multiply - Multiplies the strings and returns a string
* @a: Firstr
* @b: Secondstr
* Return: String of result
*/

char *multiply(char a[], char b[])
{
	static char mul[MAX];
	char c[MAX], temp[MAX];
	int la, lb, i, j, k = 0, x = 0, y;
	long int r = 0;
	long sum = 0;

	la = _strlen(a) - 1, lb = _strlen(b) - 1;
	for (i = 0; i <= la; i++)
		a[i] = a[i] - 48;
	for (i = 0; i <= lb; i++)
		b[i] = b[i] - 48;
	for (i = lb; i >= 0; i--, r = 0)
	{
		for (j = la; j >= 0; j--)
		{
			temp[k++] = (b[i] * a[j] + r) % 10;
			r = (b[i] * a[j] + r) / 10;
		}
		temp[k++] = r, x++;
		for (y = 0; y < x; y++)
			temp[k++] = 0;
	}
	k = 0, r = 0;
	for (i = 0; i < la + lb + 2; i++)
	{
		sum = 0, y = 0;
		for (j = 1; j <= lb + 1; j++)
		{
			if (i <= la + j)
				sum = sum + temp[y + i];
		y += j + la + 1;
		}
		c[k++] = (sum + r) % 10;
		r = (sum + r) / 10;
	}
	c[k] = r, j = 0;
	for (i = k - 1; i >= 0; i--)
		mul[j++] = c[i] + 48;
	mul[j] = '\0';
	return ((void *)mul);
}
