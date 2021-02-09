#include "palindrome.h"

/**
* is_palindrome - Checks if int is palindrome
* @n: unsigned long int
* Return: 0 if not 1 if is
*/

int is_palindrome(unsigned long n)
{
	char inty[20];
	int i = 0, j = 0;

	while (n)
	{
		inty[i] = n % 10 + 48;
		n = n / 10;
		i++;
	}
	inty[i] = '\0';
	for (i--; i > 0 && i >= j; i--, j++)
	{
		if (inty[i] != inty[j])
			return (0);
	}
	return (1);
}
