#include "shell.h"

/**
 * getListLength - function gives the length of a linked list.
 * @h: first node of the list
 * Return: the size of the list
 */

size_t getListLength(const list_t *h)
{
	size_t i = 0;

	while (h)
	{
		h = h->next;
		i++;
	}
	return (i);
}

/**
 * getListStrings - returns an array of strings of the linked list
 * @head: first node of the list
 * Return: an array of strings
 */

char **getListStrings(list_t *head)
{
	list_t *node = head;
	size_t i = getListLength(head), j;
	char **strs;
	char *str;

	if (!head || !i)
		return (NULL);
	strs = malloc(sizeof(char *) * (i + 1));
	if (!strs)
		return (NULL);
	for (i = 0; node; node = node->next, i++)
	{
		str = malloc(_strlen(node->str) + 1);
		if (!str)
		{
			for (j = 0; j < i; j++)
				free(strs[j]);
			free(strs);
			return (NULL);
		}

		str = _strcpy(str, node->str);
		strs[i] = str;
	}
	strs[i] = NULL;
	return (strs);
}

/**
 * printList - function print all elements of a linked list
 * @h: first node of the list
 * Return: the size of the list
 */

size_t printList(const list_t *h)
{
	size_t i = 0;

	while (h)
	{
		_puts(convertNumber(h->num, 10, 0));
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
 * getNodeStartsWith - returns a string node that starts with prefix
 * @node: first node of the list
 * @prefix: str to match
 * @c: the char after prefix to match
 * Return: the match node or fail
 */

list_t *getNodeStartsWith(list_t *node, char *prefix, char c)
{
	char *p = NULL;

	while (node)
	{
		p = startsWith(node->str, prefix);
		if (p && ((c == -1) || (*p == c)))
			return (node);
		node = node->next;
	}
	return (NULL);
}

/**
 * getNodeIndex - this function gets the index of a node
 * @head: first node of the list
 * @node: node pointer
 * Return: node index or -1
 */

ssize_t getNodeIndex(list_t *head, list_t *node)
{
	size_t i = 0;

	while (head)
	{
		if (head == node)
			return (i);
		head = head->next;
		i++;
	}
	return (-1);
}
