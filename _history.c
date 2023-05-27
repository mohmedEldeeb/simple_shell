#include "shell.h"

/**
 * get_history_file - gets the history file
 * @info: parameter struct
 *
 * Return: allocated string containg history file
 */

char *get_history_file(info_t *info)
{
	char *buf, *dir;

	dir = _togetenv(info, "HOME=");
	if (!dir)
		return (NULL);
	buf = malloc(sizeof(char) *
	(_strlen(dir) + _strlen(".simple_shell_history") + 2));
	if (!buf)
		return (NULL);
	buf[0] = 0;
	_strcpy(buf, dir);
	_strcat(buf, "/");
	_strcat(buf, ".simple_shell_history");
	return (buf);
}

/**
 * build_history_list - adds entry to a history linked list
 * @info: Structure containing potential arguments. Used to maintain
 * @buf: buffer
 * @linecount: the history linecount, histcount
 *
 * Return: Always 0
 */
int build_history_list(info_t *info, char *buf, int linecount)
{
	list_t *node = NULL;

	if (info->history)
		node = info->history;
	node_end(&node, buf, linecount);

	if (!info->history)
		info->history = node;
	return (0);
}

/**
 * renumber_history - renumbers history linked list after changes
 * @info: Structure containing potential arguments
 *
 * Return: new histcount
 */
int renumber_history(info_t *info)
{
	list_t *n = info->history;
	int i = 0;

	while (n)
	{
		n->num = i++;
		n = n->next;
	}
	return (info->histcount = i);
}

/**
 * read_history - reads history from file
 * @infos: the parameter struct
 *
 * Return: histcount, 0 otherwise
 */

int read_history(info_t *infos)
{
	int i, last = 0, linecount = 0;
	ssize_t fd, rdlen, fsize = 0;
	struct stat st;
	char *bufr = NULL, *filename = get_history_file(infos);

	if (!filename)
		return (0);
	fd = open(filename, O_RDONLY);
	free(filename);
	if (fd == -1)
		return (0);
	if (!fstat(fd, &st))
		fsize = st.st_size;
	if (fsize < 2)
		return (0);
	bufr = malloc(sizeof(char) * (fsize + 1));
	if (!bufr)
		return (0);

	rdlen = read(fd, bufr, fsize);
	bufr[fsize] = 0;
	if (rdlen <= 0)
		return (free(bufr), 0);

	close(fd);
	for (i = 0; i < fsize; i++)
		if (bufr[i] == '\n')
		{
			bufr[i] = 0;
			build_history_list(infos, bufr + last, linecount++);
			last = i + 1;
		}
	if (last != i)
		build_history_list(infos, bufr + last, linecount++);
	free(bufr);
	infos->histcount = linecount;
	while (infos->histcount-- >= 4096)
		delete_node_at_index(&(infos->history), 0);
	renumber_history(infos);
	return (infos->histcount);
}
