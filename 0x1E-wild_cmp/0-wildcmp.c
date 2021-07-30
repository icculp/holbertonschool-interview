#include "holberton.h"

/**
* wildcmp - Compares two strings
* @s1: First string to compare
* @s2: Second string to compare
* Return: Zero or One
*/

int wildcmp(char *s1, char *s2)
{
	int flag = 0, i = 0;

	while (*(s1 + i) != '\0')
	{
		/**printf("%s, %s\n", s1+i, s2+i);*/
		if (*(s2 + i) == '*')
		{
			s2++, flag = 1;
			continue;
		}
		if (*(s1 + i) == *(s2 + i))
			!flag ? i++ : i++, flag = 0;
		else if (flag)
			s1++;
		else
			return (0);
	}
	while ((*(s2 + i) != '\0') && *(s2 + i) == '*')
		s2++;
	if (*(s2 + i) != '\0')
		return (0);
	return (1);
}

