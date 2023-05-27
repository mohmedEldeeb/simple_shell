#include "shell.h"

/**
 * sigintHandler - ctrl-C
 * @sig_num: signal number
 *
 * Return: void
 */
void sigintHandler(__attribute__((unused))int sig_num)
{
	_puts("\n");
	_puts("$ ");
	_putchar(-1);
}

/**
 **_strncat - two strings
 *@dest: first string
 *@src: second string
 *@n: amount of bytes to be used
 *Return: string
 */
char *_strncat(char *dest, char *src, int n)
{
	int x, j;
	char *s = dest;

	x = 0;
	j = 0;
	while (dest[x] != '\0')
		x++;
	while (src[j] != '\0' && j < n)
	{
		dest[x] = src[j];
		x++;
		j++;
	}
	if (j < n)
		dest[x] = '\0';
	return (s);
}

/**
 **_strncpy - copies a string
 *@dest: destination string to be copied
 *@src: source string
 *@n: amount of characters
 *Return: concatenated string
 */
char *_strncpy(char *dest, char *src, int n)
{
	int i, j;
	char *str = dest;

	i = 0;
	while (src[i] != '\0' && i < n - 1)
	{
		dest[i] = src[i];
		i++;
	}
	if (i < n)
	{
		j = i;
		while (j < n)
		{
			dest[j] = '\0';
			j++;
		}
	}
	return (str);
}
