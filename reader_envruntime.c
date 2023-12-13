#include "shell.h"

/**
 * _unsetenv - it will removes a variable environment.
 * @info: the parameter argument struct.
 * @var: the string variable env property.
 * Return: 1 on terminate, otherwise 0.
 */
int _unsetenv(info_t *info, char *var)
{
	/*take in var declaration commands*/
	list_t *node = info->env;
	size_t i = 0;
	char *p;

	if (!node || !var)
		return (0);

	while (node)
	{
		p = starts_with(node->str, var);
		if (p && *p == '=')
		{
			info->env_changed = delete_node_at_index(&(info->env), i);
			i = 0;
			node = info->env;
			continue;
		}
		node = node->next;
		i++;
	}
	return (info->env_changed);
}

/**
 * _setenv - Initialize a new environ var, handles existing
 * @info: the parameter argument struct.
 * @var: the string variable enviro property.
 * @value: the string variable enviro value.
 * Return: always 0 success.
 */
int _setenv(info_t *info, char *var, char *value)
{
	/*take in var declaration commands*/
	char *buf = NULL;
	list_t *node;
	char *p;

	if (!var || !value)
		return (0);

	buf = malloc(_strlen(var) + _strlen(value) + 2);
	if (!buf)
		return (1);

	_strcpy(buf, var);
	_strcat(buf, "=");
	_strcat(buf, value);

	node = info->env;
	while (node)
	{
		p = starts_with(node->str, var);
		if (p && *p == '=')
		{
			free(node->str);
			node->str = buf;
			info->env_changed = 1;
			return (0);
		}
		node = node->next;
	}

	add_node_end(&(info->env), buf, 0);
	free(buf);
	/*return value*/
	info->env_changed = 1;
	return (0);
}

/**
 * get_environ - it will returns string array copy of our environment.
 * @info: the parameter argument struct.
 * Return: always 0 success.
 */
char **get_environ(info_t *info)
{
	/* call function argument*/
	if (!info->environ || info->env_changed)
	{
		info->environ = list_to_strings(info->env);
		info->env_changed = 0;
	}
	/*return argu*/
	return (info->environ);
}