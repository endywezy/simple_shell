#include "shell.h"

/**
 * _strlen - It will returns the length of a string
 * @s: it is length to check string
 *
 * Return: string of integer length
 */
int _strlen(char *s)
{
	/*take in var declaration commands*/
	int i = 0;

	if (!s)
		return (0);

	while (*s++)
		i++;
	/*Return value*/
	return (i);
}

/**
 * _strcmp - it will perform lexicogarphic comparison of two seperat strangs.
 * @s1: it is first strang .
 * @s2: its is second strang
 *
 * Return: positive if s1 > s2, zero if s1 == s2, negative if s1 < s2.
 */
int _strcmp(char *s1, char *s2)
{
	while (*s1 && *s2 && *s1 == *s2)
	{
		s1++;
		s2++;
	}
	/*Return*/
	return (*s1 - *s2);
}

/**
 * starts_with - it will checks if needle starts on haystack.
 * @haystack: It searches string
 * @needle: it finds substring
 *
 * Return: NULL or if address of next char of haystack
 */
char *starts_with(const char *haystack, const char *needle)
{
	while (*needle && *needle == *haystack)
	{
		needle++;
		haystack++;
	}
	/*Returns*/
	return (*needle == '\0' ? (char *)haystack : NULL);
}

/**
 * _strcat - it is concatenates two seperate strings
 * @dest: it is destination buffer
 * @src:  it is source buffer
 *
 * Return: destination buffer to point
 */
char *_strcat(char *dest, char *src)
{
	/*take in var declaration commands*/
	char *ret = dest;

	while (*dest)
		dest++;
	while (*src)
		*dest++ = *src++;
	*dest = '\0';
	/*Return value*/
	return (ret);
}

