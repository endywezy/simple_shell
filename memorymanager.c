#include "shell.h"

/**
 * bfree - it is frees a pointer, the address NULLs.
 * @ptr: it free address of the pointer to free
 *
 * Return: 0 otherwise, 1 if freed.
 */
int bfree(void **ptr)
{
	if (ptr && *ptr)
	{
		free(*ptr);
		*ptr = NULL;
		return (1);
	}
	/*Returns Value 0*/
	return (0);
}
