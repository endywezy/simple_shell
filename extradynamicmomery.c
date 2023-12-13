#include "shell.h"

/**
 **_memset - this is a constant byte with fills memory
 *@s: it pointer to area in memory
 *@b: the byte to fill *s with
 *@n: it is filled amount of bytes
 *Return: (s) the memory area s to pointer
 */
char *_memset(char *s, char b, unsigned int n)
{
	/*take in var declaration commands*/
	unsigned int i;

	for (i = 0; i < n; i++)
		s[i] = b;
	/*Return Value*/
	return (s);
}

/**
 * ffree - it  is a string frees of strings
 * @pp: the string of strings
 */
void ffree(char **pp)
{
/*take in var declaration commands*/
	char **a = pp;

	if (!pp)
		return;
	while (*pp)
		free(*pp++);
	free(a);
}

/**
 * _realloc - It reallocates a block of memory.
 * @ptr: it pointer to previous, mallocated block.
 * @old_size: previous block of byte size
 * @new_size: new block of byte size.
 *
 * Return: it pointer to da ol'bl ock na meen.
 */
void *_realloc(void *ptr, unsigned int old_size, unsigned int new_size)
{
	/*take in var declaration commands*/
	char *p;

	if (!ptr)
		return (malloc(new_size));
	if (!new_size)
		return (free(ptr), NULL);
	if (new_size == old_size)
		/*Return pointer*/
		return (ptr);

	p = malloc(new_size);
	if (!p)
		return (NULL);

	old_size = old_size < new_size ? old_size : new_size;
	while (old_size--)
		p[old_size] = ((char *)ptr)[old_size];
	free(ptr);
	/*Returns p*/
	return (p);
}

