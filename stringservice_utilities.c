#include "shell.h"

/**
 * _strcpy - it copy a string
 * @dest: it destination area
 * @src: it source area
 *
 * Return: pointer to destination
 */
char *_strcpy(char *dest, char *src)
{
	/*take in var declaration commands*/
	int i = 0;

	if (dest == src || src == NULL)
		return (dest);

	while (src[i])
	{
		dest[i] = src[i];
		i++;
	}
	dest[i] = '\0';
	return (dest);
}

/**
 * _strdup - it duplicate a string
 * @str: it a string that duplicate
 *
 * Return: pointer to the duplicated string
 */
char *_strdup(const char *str)
{
	/*take in var declaration commands*/
	int length = 0;
	char *ret;

	if (str == NULL)
		return (NULL);

	while (*str++)
		length++;

	ret = malloc(sizeof(char) * (length + 1));
	if (!ret)
		return (NULL);

	for (length++; length--;)
		ret[length] = *--str;

	/*return value*/
	return (ret);
}

/**
 * _puts - it is print an input string.
 * @str: the printed string to perform
 *
 * Return: This returns Nothing
 */
void _puts(char *str)
{
	/*take in var declaration commands*/
	int i = 0;

	if (!str)
		return;

	while (str[i] != '\0')
	{
		_putchar(str[i]);
		i++;
	}
}

/**
 * _putchar - It will writes the character c to stdout
 * @c: The printed  character.
 *
 * Return: On success 1.
 * On err, -1 is returned.
 */
int _putchar(char c)
{
	/*take in var declaration commands*/
	static int i;
	static char buf[WRITE_BUF_SIZE];

	if (c == BUF_FLUSH || i >= WRITE_BUF_SIZE)
	{
		write(1, buf, i);
		i = 0;
	}
	if (c != BUF_FLUSH)
		buf[i++] = c;

	return (1);
}

