#include "shell.h"
/**
 * _myhistory - it will displays list line number in the history
 * @info: potential arguments containing struct
 *
 * Return:  0 success
 */
int _myhistory(info_t *info)
{
	print_list(info->history);
	/*return value*/
	return (0);
}

/**
 * unset_alias - it will unsets an alias.
 * @info: Parameter potential arguments containing struct.
 * @str: it is a string alias.
 *
 * Return: 1 on error, 0 on success.
 */
int unset_alias(info_t *info, char *str)
{
	/*take in var declaration commands*/
	char *p, c;
	int ret;

	p = _strchr(str, '=');
	if (!p)
		return (1);
	c = *p;
	*p = 0;
	ret = delete_node_at_index(&(info->alias),
	get_node_index(info->alias, node_starts_with(info->alias, str, -1)));
	*p = c;
	return (ret);
}

/**
 * set_alias - it will unsets or sets an alias.
 * @info: Parameter potential arguments containing struct.
 * @str: it is a string alias.
 *
 * Return: 1 on error, 0 on success.
 */
int set_alias(info_t *info, char *str)
{
	/*take in var declaration commands*/
	char *p;

	p = _strchr(str, '=');
	if (!p)
	return (1);
	if (!*++p)
		return (unset_alias(info, str));

	unset_alias(info, str);
	return (add_node_end(&(info->alias), str, 0) == NULL);
}

/**
 * print_alias - it will prints an alias string.
 * @node: it is alias node.
 *
 * Return: 1 on error, 0 on success.
 */
int print_alias(list_t *node)
{
	/*take in var declaration commands*/
	char *p = NULL, *a = NULL;

	if (node)
	{
		p = _strchr(node->str, '=');
		for (a = node->str; a <= p; a++)
			_putchar(*a);
		_putchar('\'');
		_puts(p + 1);
		_puts("'\n");
		return (0);
	}
		return (1);
}

/**
 * _myalias - it will displays, unsets, or sets aliases.
 * @info: Parameter potential arguments containing struct.
 *
 * Return: Always 0
 */
int _myalias(info_t *info)
{
	/*take in var declaration commands*/
	int i = 0;
	char *p = NULL;
	list_t *node = NULL;

	if (info->argc == 1)
	{
		node = info->alias;
		while (node)
			{
			print_alias(node);
			node = node->next;
			}
		return (0);
	}

	for (i = 1; info->argv[i]; i++)
		{
		p = _strchr(info->argv[i], '=');
		if (p)
			set_alias(info, info->argv[i]);
		else
			print_alias(node_starts_with(info->alias, info->argv[i], '='));
		}
		return (0);
}

