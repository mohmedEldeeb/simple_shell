#include "shell.h"

/**
 * check_chain - chaining based on last status
 * @info: the parameter struct
 * @buf: the char buffer
 * @p: address of current
 * @i: starting position in buf
 * @len: length of buf
 *
 * Return: Void
 */

void check_chain(info_t *info, char *buf, size_t *p, size_t i, size_t len)
{
	size_t x = *p;

	if (info->cmd_buf_type == 2)
	{
		if (info->status)
		{
			buf[i] = 0;
			x = len;
		}
	}
	if (info->cmd_buf_type == 1)
	{
		if (!info->status)
		{
			buf[i] = 0;
			x = len;
		}
	}

	*p = x;
}

/**
 * is_chain - test if current char in buffer
 * @info: the parameter struct
 * @buf: the char buffer
 * @p: address of current
 *
 * Return: 1, 0 otherwise
 */
int is_chain(info_t *info, char *buf, size_t *p)
{
	size_t x = *p;

	if (buf[x] == '|' && buf[x + 1] == '|')
	{
		buf[x] = 0;
		x++;
		info->cmd_buf_type = 1;
	}
	else if (buf[x] == '&' && buf[x + 1] == '&')
	{
		buf[x] = 0;
		x++;
		info->cmd_buf_type = 2;
	}
	else if (buf[x] == ';') /* found end of this command */
	{
		buf[x] = 0; /* replace semicolon with null */
		info->cmd_buf_type = 3;
	}
	else
		return (0);
	*p = x;
	return (1);
}
