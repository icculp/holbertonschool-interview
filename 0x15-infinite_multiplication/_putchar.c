#include "holberton.h"

/**
* _putchar - writes the character c to stdout
* @c: The character to print
* Return: 1 on success, else -1 and errno set
*/

int _putchar(char c)
{
	return (write(1, &c, 1));
}
