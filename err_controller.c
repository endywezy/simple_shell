#include "shell.h"

/**
 * _eputs - it will be able to prints a string input to stderr.
 * @str: the string data to be print.
 *
 * Return: Nothing.
 */
void _eputs(char *str)
{
	/*take in var declaration commands*/
	int i = 0;

	if (!str)
	return;
	while (str[i] != '\0')
	{
		_eputchar(str[i]);
		i++;
	}
}

/**
 * _putsfd - it will prints an input string to a given file descriptor.
 * @str: the string data to be print.
 * @fd: this fd write to the  file descriptor.
 *
 * Return: it is  number of characters write.
 */
int _putsfd(char *str, int fd)
{
	/*take in var declaration commands*/
	int i = 0;

	if (!str)
		return (0);
	while (*str)
	{
		i += _putfd(*str++, fd);
	}
		return (i);
}

/**
 * _putfd - it will be able to writes character c to a given file descriptor.
 * @c: this is the character to printed.
 * @fd: this is to write file descriptor .
 *
 * Return: success 1.
 * On err, -1 is return,
 *
 */
int _putfd(char c, int fd)
{
	/*take in var declaration commands*/
	static int i;
	static char buf[WRITE_BUF_SIZE];

	if (c == BUF_FLUSH || i >= WRITE_BUF_SIZE)
	{
		write(fd, buf, i);
		i = 0;
	}
	if (c != BUF_FLUSH)
		buf[i++] = c;
	return (1);
}


/**
 * _eputchar - it will writes the character c to stderr.
 * @c: this is the character to print.
 *
 * Return: success 1.
 * On err, -1 is return.
 */
int _eputchar(char c)
{
	/*take in var declaration commands*/
	static int i;
	static char buf[WRITE_BUF_SIZE];

	if (c == BUF_FLUSH || i >= WRITE_BUF_SIZE)
	{
		write(2, buf, i);
		i = 0;
	}
	if (c != BUF_FLUSH)
		buf[i++] = c;
	return (1);
}
