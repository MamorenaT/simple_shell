#include "shell.h"

/**
 * current_env - This function prints the current environment.
 * @info: A structure that contains potential arg,
 * to maintain constant function prototype.
 * Return: Always 0
 */
int current_env(info_t *info)
{
	print_list_str(info->env);
	return (0);
}

/**
 * get_env_var - This function gets the value of an environment variable.
 * @info: A structure that contains potential arg,
 * to maintain constant function prototype.
 * @name: The name of the environment variable.
 * Return: The value of the environment variable.
 */
char* get_env_var(info_t *info, const char *name)
{
	list_t *node = info->env;
	char *p;

	while (node)
	{
		p = starts_with(node->str, name);
		if (p && *p)
			return (p);
		node = node->next;
	}
	return (NULL);
}

/**
 * init_env_var - This function initializes a new environment
 * variable or modifies an existing one.
 * @info: A structure that contains potential arg,
 * to maintain constant function prototype.
 *  Return: Always 0
 */
int init_env_var(info_t *info)
{
	if (info->argc != 3)
	{
		_exputs("Incorrect number of arguments\n");
		return (1);
	}
	if (_setenv(info, info->argv[1], info->argv[2]))
		return (0);
	return (1);
}

/**
 * rmv_env_var - This function removes an environment variable.
 * @info: A structure that contains potential arg,
 * to maintain constant function prototype.
 * Return: Always 0
 */
int rmv_env_var(info_t *info)
{
	int i;

	if (info->argc == 1)
	{
		_exputs("Too few arguments.\n");
		return (1);
	}
	for (i = 1; i <= info->argc; i++)
		_unsetenv(info, info->argv[i]);

	return (0);
}

/**
 * pop_env_list - This function populates the environment linked list.
 * @info: A structure that contains potential arg,
 * to maintain constant function prototype.
 * Return: Always 0
 */
int pop_env_list(info_t *info)
{
	list_t *node = NULL;
	size_t i;

	for (i = 0; environ[i]; i++)
		add_node_end(&node, environ[i], 0);
	info->env = node;
	return (0);
}
