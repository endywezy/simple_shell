#include "shell.h"

/**
 * list_len - It is determines length of linked list.
 * @h: Its pointer to first node.
 *
 * Return: On return is size of list.
 */
size_t list_len(const list_t *h)
{
	/*take in var declaration commands*/
	size_t i = 0;

	while (h)
	{
		h = h->next;
		i++;
	}
	/*Return*/
	return (i);
}

/**
 * list_to_strings - It returns an array of strings of the list->str.
 * @head: its pointer to first node.
 *
 * Return: strings return array.
 */
char **list_to_strings(list_t *head)
{
	/*take in var declaration commands*/
	list_t *node = head;
	size_t i = list_len(head), j;
	char **strs;
	char *str;

	if (!head || !i)
		return (NULL);
	strs = malloc(sizeof(char *) * (i + 1));
	if (!strs)
		return (NULL);
	for (i = 0; node; node = node->next, i++)
	{
		str = _strdup(node->str);
	if (!str)
	{
	for (j = 0; j < i; j++)
		free(strs[j]);
	free(strs);
		return (NULL);
	}

		strs[i] = str;
	}
		strs[i] = NULL;
		return (strs);
}

/**
 * print_list - it print all elements in the  list_t linked list.
 * @h: it pointer to first node.
 *
 * Return:  This returns the size of list.
 */
size_t print_list(const list_t *h)
{
	/*take in var declaration commands*/
	size_t i = 0;

	while (h)
	{
		_puts(convert_number(h->num, 10, 0));
		_putchar(':');
		_putchar(' ');
		_puts(h->str ? h->str : "(nil)");
		_puts("\n");
		h = h->next;
		i++;
	}
	return (i);
}

/**
 * node_starts_with - string starts with prefix returns node whoever.
 * @node: it pointer to list head.
 * @prefix: it is a string to match.
 * @c:  next character after prefix to matches.
 *
 * Return: null or match node.
 */
list_t *node_starts_with(list_t *node, char *prefix, char c)
{
	/*take in var declaration commands*/
	char *p = NULL;

	while (node)
	{
	p = starts_with(node->str, prefix);
	if (p && ((c == -1) || (*p == c)))
		return (node);
	node = node->next;
	}
	return (NULL);
}

/**
 * get_node_index - it is to gets the index of a node.
 * @head: it pointer to list head.
 * @node: it pointer to the node.
 *
 * Return: -1 or node of index.
 */
ssize_t get_node_index(list_t *head, list_t *node)
{
	/*take in var declaration commands*/
	size_t i = 0;

while (head)
	{
	if (head == node)
		return (i);
	head = head->next;
		i++;
	}
	/*returns*/
	return (-1);
}
