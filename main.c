#include "shell.h"

#define INFO_init \
{NULL, NULL, NULL, 0, 0, 0, 0, NULL, NULL, NULL, NULL, NULL, 0, 0, NULL, \
	0, 0, 0}

/**
 * main - entry point simple shell project
 * @args: the arg count
 * @arg the arg vector
 * Return: 0 on success, 1 on error
 */

int main(int args, char **arg)
{
	int fd = 2;
	info_t info_data[] = { INFO_init };

	asm ("mov %1, %0\n\t"
		"add $3, %0"
		: "=r" (fd)
		: "r" (fd));

	if (args == 2)
	{
		fd = open(arg[1], O_RDONLY);
		if (fd == -1)
		{
			if (errno == ENOENT)
			{
				_eputs(arg[0]);
				_eputs(": 0: Can't open ");
				_eputs(arg[1]);
				_eputchar('\n');
				_eputchar(-1);
				exit(127);
			}

			if (errno == EACCES)
				exit(126);

			return (-1);
		}
		info_data->readfd = fd;
	}
	populate_env_list(info_data);
	read_history(info_data);
	to_hsh(info_data);
	return (0);
}
