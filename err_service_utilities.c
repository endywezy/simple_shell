#include "shell.h"

/**
 * print_error -It will print an err message.
 * @info: the parameter argument and return info struct.
 * @estr: this specific string containing err type.
 *
 * Return: Void.
 */
void print_error(info_t *info, char *estr)
{
	/*pass an argu*/
	_eputs(info->fname);
	_eputs(": ");
	print_d(info->line_count, STDERR_FILENO);
	_eputs(": ");
	_eputs(info->argv[0]);
	_eputs(": ");
	_eputs(estr);
}

/**
 * _erratoi - it is function that converts string to integer.
 * @s: it is the string that convert.
 *
 * Return: 0 if there is none in string, otherwise, -1 on err.
 */
int _erratoi(char *s)
{
	/*take in var declaration commands*/
	int i = 0;
	unsigned long int result = 0;

	if (*s == '+')
		s++;

	/*converts a string of digits to an intege*/
	for (i = 0; s[i] != '\0'; i++)
	{
		if (s[i] >= '0' && s[i] <= '9')
		{
			result *= 10;
			result += (s[i] - '0');
			if (result > INT_MAX)
			return (-1);
		}
		else
			return (-1);
		}
			return (result);
}

/**
 * print_d - it is function that print a decimal (integer) number (base 10).
 * @input: it is an input.
 * @fd: this file write to the file descriptor.
 *
 * Return: printed character numbers.
 */
int print_d(int input, int fd)
{
	/*take in var declaration commands*/
	int (*__putchar)(char) = (fd == STDERR_FILENO) ? _eputchar : _putchar;
	int i, count = 0;
	unsigned int _abs_, current;

	/*pass an argu*/
	if (input < 0)
	{
		_abs_ = -input;
		__putchar('-');
		count++;
	}
	else
		_abs_ = input;

	current = _abs_;
	for (i = 1000000000; i > 1; i /= 10)
	{
	if (_abs_ / i)
		{
		__putchar('0' + current / i);
		count++;
		}
		current %= i;
	}

		__putchar('0' + current);
		count++;

	return (count);
}
/**
 * remove_comments - it is func to replaces first instance of '#' with '\0'.
 * @buf: it is the address of the modify string.
 *
 * Return: Void.
 */
void remove_comments(char *buf)
{
	/*take in var declaration commands*/
	int i;

	/*loop*/
	for (i = 0; buf[i] != '\0'; i++)
		if (buf[i] == '#' && (!i || buf[i - 1] == ' '))
		{
		buf[i] = '\0';
		break;
		}
}
/**
 * convert_number - It will converter funct and also clone of itoa.
 * @num: it is a Number.
 * @base: its is the Base.
 * @flags: respresent argument flags.
 *
 * Return: This function returns  String.
 */
char *convert_number(long int num, int base, int flags)
{
	/*take in var declaration commands*/
	static char *array;
	static char buffer[50];
	char sign = 0;
	char *ptr;
	unsigned long n = num;

	/*loops*/
	if (!(flags & CONVERT_UNSIGNED) && num < 0)
	{
		n = -num;
		sign = '-';
	}

	array = (flags & CONVERT_LOWERCASE) ? "0123456789abcdef" : "0123456789ABCDEF";
	ptr = &buffer[49];
	*ptr = '\0';

	do {
		*--ptr = array[n % base];
		n /= base;
	} while (n != 0);

	if (sign)
		*--ptr = sign;
	return (ptr);
}

