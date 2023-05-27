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
