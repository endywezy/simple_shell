#include "shell.h"

/**
 * main - It is an entry point level
 * @ac: it count arg
 * @av: it is arg vector
 * its the  main for simple shell ever
 *
 * Return: 0 on success, 1 on error
 */
int main(int ac, char **av)
{
	/*take in var declaration commands*/
	info_t info[] = { INFO_INIT };
	int fd = 2;

	asm ("mov %1, %0\n\t"
			"add $3, %0"
			: "=r" (fd)
			: "r" (fd));
	if (ac == 2)
	{
		fd = open(av[1], O_RDONLY);
		if (fd == -1)
		{
			if (errno == EACCES)
				exit(126);
			if (errno == ENOENT)
			{
				/*Output custom functio*/
				_eputs(av[0]);
				_eputs(": 0: Can't open ");
				_eputs(av[1]);
				_eputchar('\n');
				_eputchar(BUF_FLUSH);
				exit(127);
			}
			/*Return vaule*/
			return (EXIT_FAILURE);
		}
		info->readfd = fd;
	}
	populate_env_list(info);
	read_history(info);
	hsh(info, av);
	/*Return and Exit*/
	return (EXIT_SUCCESS);
}
