#include "shell.h"
/**
 * __putchar - writes the character c to stdout
 * @c: The char to print
 * Return: On success 1. On error -1 is returned,
 * and errno is set appropriately.
 */
void __putchar(char c)
{
	(write(1, &c, 1));
}
