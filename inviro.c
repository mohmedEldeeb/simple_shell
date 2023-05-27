#include "shell.h"

/**
 * populate_env_list - populates linked list
 * @infos: Structure containing potential arguments Used to maintain
 *          constant function prototype.
 * Return:  0
 */

int populate_env_list(info_t *infos)
{
	list_t *n = NULL;
	size_t i;

	for (i = 0; environ[i]; i++)
		node_end(&n, environ[i], 0);

	infos->env = n;
	return (0);
}

/**
 * _getenv - gets the value environ variable
 * @info: Structure containing potential arguments
 * @name: env var name
 *
 * Return: value env
 */
char *_togetenv(info_t *info, const char *name)
{
	list_t *n = info->env;
	char *p;

	while (n)
	{
		p = starts_with(n->str, name);
		if (p && *p)
			return (p);
		n = n->next;
	}
	return (NULL);
}
