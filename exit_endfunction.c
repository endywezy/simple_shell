#include "shell.h"

/**
 * _strchr - It is a function that locates character in string.
 * @s: It is a string that parsed.
 * @c: it is the character to look for.
 *
 * Return: (s) a pointer to the memory area s.
 */
char *_strchr(char *s, char c)
{
	/*loops*/
	while (*s != '\0')
	{
	if (*s == c)
		return (s);
	s++;
	}
	return (NULL);
}

/**
 * _strncat - It is a function that concatenates two strings.
 * @dest: it is the first string.
 * @src:  It is the second string.
 * @n: It is the number of bytes to be maximally used.
 *
 * Return: string concatenated.
 */
char *_strncat(char *dest, char *src, int n)
{
	/*take in var declaration commands*/
	int i, j;
	char *s = dest;
	/*loops*/
	for (i = 0; dest[i] != '\0'; i++)
	;

	for (j = 0; src[j] != '\0' && j < n; i++, j++)
		dest[i] = src[j];

	if (j < n)
		dest[i] = '\0';
	return (s);
}

/**
 * _strncpy - It’s the copies a string.
 * @dest: It’s the string to be copied to destination.
 * @src: It is the string source.
 * @n: it is number of characters to be copied.
 *
 * Return: string concatenated.
 */
char *_strncpy(char *dest, char *src, int n)
{
	/*take in var declaration commands*/
	int i, j;
	char *s = dest;

	for (i = 0; src[i] != '\0' && i < n - 1; i++)
		dest[i] = src[i];

	for (j = i; j < n; j++)
		dest[j] = '\0';

	return (s);
}

