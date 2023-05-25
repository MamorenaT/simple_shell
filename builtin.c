#include "shell.h"

/**
 * disp_history - This function displays the history list,
 * one command per line, preceded by line numbers, starting at 0.
 * @info: A structure that contains potential arg,
 * to maintain constant function prototype.
 * Return: Always 0
 */
int disp_history(info_t *info)
{
	print_list(info->history);
	return (0);
}

/**
 * unset_alias - This function unsets an alias by
 * setting it to an empty string.
 * @info: parameter struct
 * @str: the string alias
 * Return: Always 0 on success, 1 if failed
 */
int unset_alias(info_t *info, char *str)
{
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
 * set_alias - his function sets an alias to a string.
 * @info: parameter struct pointer
 * @str: string alias pointer.
 * Return: Always 0 on success, 1 if failed.
 */
int set_alias(info_t *info, char *str)
{
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
 * print_alias - This function prints an alias string.
 * @node: alias node
 * Return: Always 0 on success, 1 if failed.
 */
int print_alias(list_t *node)
{
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
 * alias - This function mimics the alias builtin (man alias).
 * @info: contains potential arguments
 *  Return: Always 0
 */
int alias(info_t *info)
{
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
