#include "shell.h"

/**
 * free_pointer - frees a pointer then sets address to NULL
 * @ptr: address to be freed
 * Return: 1 if sucessful, 0 if failed
 */
int free_pointer(void **ptr)
{
	if (ptr && *ptr)
	{
		free(*ptr);
		*ptr = NULL;
		return (1);
	}
	return (0);
}
