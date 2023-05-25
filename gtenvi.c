#include "shell.h"

/**
 * get_environ_var - This function returns a copy
 * of our environment variables as a string array.
 * @info: container for potential arguments.
 * Return: A copy of a string array.
 */
char **get_environ_var(info_t *info)
{
	if (!info->environ_var || info->envi_changed)
	{
		info->environ_var = list_to_strings(info->env_list);
		info->envi_changed = 0;
	}

	return (info->environ_var);
}

/**
 * rm_environ_var - A variable is removed with this function.
 * @info: container for potential arguments.
 * @var: The variable to be removed.
 * Return: 1 if successful, 0 if unsuccessful.
 */
int rm_environ_var(info_t *info, char *var)
{
	list_t *node = info->env_list;
	size_t i = 0;
	char *p;

	if (!node || !var)
		return (0);

	while (node)
	{
		p = starts_with(node->str, var);
		if (p && *p == '=')
		{
			info->envi_changed = delete_node_at_index(&(info->env_list), i);
			i = 0;
			node = info->env_list;
			continue;
		}
		node = node->next;
		i++;
	}
	return (info->envi_changed);
}

/**
 * ini_environ_var - initialization of a new environment variable.
 * @info: container for potential arguments.
 * @var: variable to be initialized or modified.
 * @value: The value of the environment variable.
 * Return: Always 0.
 */
int ini_environ_var(info_t *info, char *var, char *value)
{
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
	node = info->env_list;
	while (node)
	{
		p = starts_with(node->str, var;)
		if (p && *p == '=')
		{
			free(node->str);
			node->str = buf;
			info->envi_changed = 1;
			return (0);
		}
		node = node->next;
	}
	add_node_end(&(info->env_list), buf, 0);
	free(buf);
	info->envi_changed = 1;
	return (0);
}
