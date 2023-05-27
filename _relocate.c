#include "shell.h"

/**
 * _realloc - reallocates a block of memory
 * @ptr: to previous malloc'ated block
 * @old_size: size of previous block
 * @new_size: size of new block
 *
 * Return: pointer to da ol'block nameen.
 */

void *_realloc(void *ptr, unsigned int old_size, unsigned int new_size)
{
	char *x;

	if (!ptr)
		return (malloc(new_size));
	if (!new_size)
		return (free(ptr), NULL);
	if (new_size == old_size)
		return (ptr);

	x = malloc(new_size);
	if (!x)
		return (NULL);

	old_size = old_size < new_size ? old_size : new_size;
	while (old_size--)
		x[old_size] = ((char *)ptr)[old_size];
	free(ptr);
	return (x);
}

/**
 * ffree - frees a string of strings
 * @pp: string of strings
 */
void ffree(char **pp)
{
	char **a = pp;

	if (!pp)
		return;
	while (*pp)
		free(*pp++);
	free(a);
}
