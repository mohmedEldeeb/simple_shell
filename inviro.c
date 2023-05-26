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

	for (i = 0; var_environ[i]; i++)
		node_end(&n, var_environ[i], 0);

	infos->env = n;
	return (0);
}
