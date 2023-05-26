#include "shell.h"

/**
 * _strdup - duplicates string
 * @str: string to duplicate
 *
 * Return: pointer to duplicated string
 */

char *_strdup(const char *strn)
{
	int n = 0;
	char *result;

	if (strn == NULL)
		return (NULL);

	while (*strn++)
		n++;

	result = malloc(sizeof(char) * (n + 1));
	if (!result)
		return (NULL);

	for (n++; n--;)
		result[n] = *--strn;

	return (result);
}

