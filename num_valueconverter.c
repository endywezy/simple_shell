#include "shell.h"

/**
 * interactive - if shell is in interactive mode it will return value true
 * @info: potential arguments containing struct
 * Return: 0 otherwise, 1 if interactive mode.
 */
int interactive(info_t *info)
{
/*return*/
	return (isatty(STDIN_FILENO) && info->readfd <= 2);
}

/**
 *is_delim - It will checks if a character is a delimiter
 * @q: it checks the char
 * @delim: string in the delimiter
 * Return: 0 if false, 1 if true.
 */
int is_delim(char q, char *delim)
{
	for (; *delim; delim++)
	{
	if (*delim == q)
	{
		return (1);
		}
	}
	return (0);
}

/**
 * is_alphabetic - will check the alphabetic character
 * @q: it is character to check
 * Return: 0 otherwise, 1 if q is alphabetic.
 */
int is_alphabetic(int q)
{
/*return*/
	return ((q >= 'a' && q <= 'z') || (q >= 'A' && q <= 'Z'));
}

/**
 * _atoi - it is an integer to converts a string
 * @s: It is string to be convert.
 * Return: converted number otherwise, 0 if no numbers in the string.
 */
int _atoi(char *s)
{
	int k = 0, sign = 1, flag = 0, output = 0;

	for (k = 0; s[k] != '\0' && flag != 2; k++)
	{
		if (s[k] == '-')
		{
			sign *= -1;
		}
			if (s[k] >= '0' && s[k] <= '9')
			{
				flag = 1;
				output *= 10;
				output += (s[k] - '0');
			} else if (flag == 1)
			{
			flag = 2;
		}
	}
	/*Returns output*/
	return ((sign == -1) ? -output : output);
}
