#include "holberton.h"

/**
* compare - Compares the original string with the reversed string
* @s: Source string
* @rev: Reversed string
* @i: Iterator
* Return: 1 if equal 0 if not
*/

int compare(char *s, char *rev, int i)
{
	if (s[i] != '\0')
	{
		/**printf("%s, %s\n", s+i, rev+i);*/
		if (*(rev + i) == '*')
			return (compare(s, rev + 1, 1));
		if (*(s + i) == *(rev + i))
			return (compare(s, rev, i + 1));
		else if (*(s + i) != *(rev + i) && *(rev + i) == '*')
		{
			if (*(s + i + 1) != *(rev + i + 1))
				return (compare(s + 1, rev, i));
			else
				return (compare(s, rev, i + 1));
		}
		else
			return (0);
	}
	else if (rev[i] != '\0')
		return (0);
	else
		return (1);
}

/**
* wildcmp - Compares two strings
* @s1: First string to compare
* @s2: Second string to compare
* Return: Zero or One
*/

int wildcmp(char *s1, char *s2)
{
	/**int flag = 0, i = 0;*/
	return (1);
	return (compare(s1, s2, 0));
}
