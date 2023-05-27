#include "shell.h"

/**
 **_memset - fills memory with byte
 *@s: pointer to memory area
 *@b: byte to fill *s
 *@n: amount of bytes filled
 *Return: (s)
 */

char *_memset(char *s, char b, unsigned int n)
{
	unsigned int x;

	for (x = 0; x < n; x++)
		s[x] = b;
	return (s);
}

/**
 * bfree - frees a pointer and NULLs the address
 * @pt: address of the pointer to free
 *
 * Return: 1, otherwise 0.
 */
int bfree(void **pt)
{
	if (pt && *pt)
	{
		free(*pt);
		*pt = NULL;
		return (1);
	}
	return (0);
}
