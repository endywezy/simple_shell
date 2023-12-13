#include "shell.h"

/**
 * add_node - it adds a node to start of list.
 * @head: it is to address of pointer to head node.
 * @str: it is node of str field.
 * @num: it used by history node index
 *
 * Return: new_head.
 */
list_t *add_node(list_t **head, const char *str, int num)
{
	list_t *new_head = malloc(sizeof(list_t));

	if (!head)
		return (NULL);
	if (!new_head)
		return (NULL);
	_memset((void *)new_head, 0, sizeof(list_t));
	new_head->num = num;
	new_head->str = str ? _strdup(str) : NULL;
	if (!new_head->str)
	{
		free(new_head);
		return (NULL);
	}
	new_head->next = *head;
	*head = new_head;
	return (new_head);
}

/**
 * add_node_end - it adds a node to start of list.
 * @head: it address pointer to node head.
 * @str: it is node of str field.
 * @num: it used by history node index
 *
 * Return: new_node.
 */
list_t *add_node_end(list_t **head, const char *str, int num)
{
	list_t *new_node = malloc(sizeof(list_t));

	if (!head)
		return (NULL);
	if (!new_node)
		return (NULL);
	_memset((void *)new_node, 0, sizeof(list_t));
	new_node->num = num;
	new_node->str = str ? _strdup(str) : NULL;
	if (!new_node->str)
	{
		free(new_node);
		return (NULL);
	}
	if (*head)
	{
		list_t *node = *head;

		while (node->next)
			node = node->next;
		node->next = new_node;
	}
	else
		*head = new_node;
	/*it iill Return New Node */
	return (new_node);
}

/**
 * print_list_str - It is to print only str element of a list_t linked list.
 * @h: it is first node pointer to.
 *
 * Return: returns i.
 */
size_t print_list_str(const list_t *h)
{
	/*take in var declaration commands*/
	size_t i = 0;

	while (h)
	{
		_puts(h->str ? h->str : "(nil)");
		_puts("\n");
		h = h->next;
		i++;
	}
	return (i);
}

/**
 * delete_node_at_index - it is to node deletes at given index.
 * @head: it address pointer to node head.
 * @index: set of index to delete node.
 *
 * Return: 1 on success, 0 bad.
 */
int delete_node_at_index(list_t **head, unsigned int index)
{
	list_t *node = *head, *prev_node = NULL;
	unsigned int i = 0;

	if (!head || !*head)
		return (0);
	if (!index)
	{
		*head = (*head)->next;
		free(node->str);
		free(node);
		return (1);
	}
	while (node)
	{
		if (i == index)
		{
			prev_node->next = node->next;
			free(node->str);
			free(node);
			return (1);
		}
		i++;
		prev_node = node;
		node = node->next;
	}
	return (0);
}

/**
 * free_list - it frees a list of all nodes.
 * @head_ptr: it address pointer to node head.
 *
 * Return: returns void.
 */
void free_list(list_t **head_ptr)
{
	list_t *node = *head_ptr, *next_node = NULL;

	if (!head_ptr || !*head_ptr)
		return;
	while (node)
	{
		next_node = node->next;
		free(node->str);
		free(node);
		node = next_node;
	}
	*head_ptr = NULL;
}

