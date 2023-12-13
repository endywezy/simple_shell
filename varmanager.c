#include "shell.h"

/**
 * is_chain - It will scans if a chain delimeter is current char in bufer
 * @info: Structure containing potential arguments.
 * @buf: this char bufer
 *
 * @p: it address of current position in bufer
 *
 * Return: 0 otherwise 1 if chain delimeter.
 */
int is_chain(info_t *info, char *buf, size_t *p)
{
	/*take in var declaration commands*/
	size_t j = *p;

	if (buf[j] == '|' && buf[j + 1] == '|')
	{
		buf[j] = 0;
		j++;
		info->cmd_buf_type = CMD_OR;
	}
	else if (buf[j] == '&' && buf[j + 1] == '&')
	{
		buf[j] = 0;
		j++;
		info->cmd_buf_type = CMD_AND;
	}
	else if (buf[j] == ';')
	{
		buf[j] = 0;
		info->cmd_buf_type = CMD_CHAIN;
	}
	else
		return (0);

	*p = j;
		return (1);
}

/**
 * check_chain - it will continue chaining based on last status or stop
 * @info: it is parameter structure
 * @buf: that is char buffer
 * @p: it address of current position in bfer
 * @i: it start the position in bufer
 * @len: iden length of bufer
 *
 * Return: Void
 */
void check_chain(info_t *info, char *buf, size_t *p, size_t i, size_t len)
{
	/*take in var declaration commands*/
	size_t j = *p;

	if (info->cmd_buf_type == CMD_AND && info->status)
	{
		buf[i] = 0;
		j = len;
	}
	else if (info->cmd_buf_type == CMD_OR && !info->status)
	{
		buf[i] = 0;
		j = len;
	}

	*p = j;
}

/**
 * replace_alias - it will replaces an aliases in the tokenizing string
 * @info: it is parameter structure
 *
 * Return: 1 if replaced, 0 otherwise
 */
int replace_alias(info_t *info)
{
	/*take in var declaration commands*/
	int i;
	list_t *node;
	char *p;

	for (i = 0; i < 10; i++)
	{
	node = node_starts_with(info->alias, info->argv[0], '=');
	if (!node)
		return (0);

	free(info->argv[0]);
		p = _strchr(node->str, '=');
	if (!p)
		return (0);

	p = _strdup(p + 1);
	if (!p)
		return (0);

	info->argv[0] = p;
	}

	/*Return value*/
	return (1);
}

/**
 * replace_vars - I will replaces variables in the tokenized string
 * @info: it is parameter structure
 *
 * Return: 0 otherwise, 1 if replaced,
 */
int replace_vars(info_t *info)
{
	/*take in var declaration commands*/
	int i = 0;
	list_t *node;

	for (i = 0; info->argv[i]; i++)
	{
	if (info->argv[i][0] != '$' || !info->argv[i][1])
		continue;

	if (!_strcmp(info->argv[i], "$?"))
	{
		replace_string(&(info->argv[i]),
			_strdup(convert_number(info->status, 10, 0)));
		continue;
	}
	if (!_strcmp(info->argv[i], "$$"))
	{
		replace_string(&(info->argv[i]),
				_strdup(convert_number(getpid(), 10, 0)));
		continue;
	}
		node = node_starts_with(info->env, &info->argv[i][1], '=');

	if (node)
	{
		replace_string(&(info->argv[i]),
				_strdup(_strchr(node->str, '=') + 1));
		continue;
	}

		replace_string(&info->argv[i], _strdup(""));
	}

	return (0);
}

/**
 * replace_string - I will take and replaces string
 * @old: it an address of old string
 * @new: addresses the new string
 *
 * Return: 1 if replaced, 0 otherwise
 */
int replace_string(char **old, char *new)
{
	free(*old);
	*old = new;
	/*Return Value 0*/
	return (1);
}

