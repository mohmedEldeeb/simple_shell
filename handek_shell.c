#include "shell.h"

/**
 * hsh - main shell loop
 * @info: the parameter & return info struct
 * @av: the argument vector from main()
 *
 * Return: 0 on success, 1 on error, or error code
 */

int to_hsh(info_t *info)
{
	ssize_t r = 0;
	int ddd = 0;

	while (r != -1 && ddd != -2)
	{
		clear_info(info);
		if (interactive(info))
			_puts("$ ");
		_eputchar(-1);
		r = get_input(info);
		if (r != -1)
			;
		else if (interactive(info))
			_putchar('\n');
		free_info(info, 0);
	}
	free_info(info, 1);
	if (!interactive(info) && info->status)
		exit(info->status);
	if (ddd == -2)
	{
		if (info->err_num == -1)
			exit(info->status);
		exit(info->err_num);
	}
	return (ddd);
}
