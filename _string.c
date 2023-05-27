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

/**
 * _strcat - concatenates two strings
 * @dest: destination buffer
 * @src: source buffer
 *
 * Return: pointer to destination buffer
 */

char *_strcat(char *dest, char *src)
{
	char *result = dest;

	while (*dest)
		dest++;
	while (*src)
		*dest++ = *src++;
	*dest = *src;

	return (result);
}

#include "shell.h"

/**
 * _strcpy - copies a string
 * @dest: destination
 * @src: source
 *
 * Return: pointer to destination
 */

char *_strcpy(char *dest, char *src)
{
	int x = 0;

	if (dest == src || src == 0)
		return (dest);
	while (src[x])
	{
		dest[x] = src[x];
		x++;
	}
	dest[x] = 0;
	return (dest);
}

#include "shell.h"

/**
 * _strlen - returns length string
 * @s: string whose length to check
 *
 * Return: integer length of string
 */

int _strlen(char *s)
{
	int x = 0;

	if (!s)
		return (0);

	while (*s++)
		x++;
	return (x);
}
