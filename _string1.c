#include "shell.h"


/**
 * starts_with - to checks if needle starts with haystack
 * @haystack: to search
 * @needle: substring to find
 *
 * Return: address haystack or NULL
 */

char *starts_with(const char *haystack, const char *needle)
{
	while (*needle)
		if (*needle++ != *haystack++)
			return (NULL);

	return ((char *)haystack);
}

/**
 *_puts - prints an input string
 *@str: the string to be printed
 *
 * Return: Nothing
 */
void _puts(char *str)
{
	int i = 0;

	if (!str)
		return;
	while (str[i] != '\0')
	{
		_putchar(str[i]);
		i++;
	}
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

/**
 * _putchar - writes the character c to stdout
 * @c: The character to print
 *
 * Return: On success 1.
 * On error, -1 is returned, and errno is set appropriately.
 */
int _putchar(char c)
{
	static int x;
	static char buf[1024];

	if (c == -1 || x >= 1024)
	{
		write(1, buf, x);
		x = 0;
	}
	if (c != -1)
		buf[x++] = c;
	return (1);
}

