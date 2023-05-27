#include "shell.h"

/**
 **_strchr - locates a character a string
 *@s: string to be parsed
 *@c: character to look for
 *Return: pointer to the memory area s
 */

char *_strchr(char *s, char c)
{
	do {
		if (*s == c)
			return (s);
	} while (*s++ != '\0');

	return (NULL);
}
