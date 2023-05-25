#include "shell.h"

/**
 * _exputs - This function prints a string to stderr.
 * @str: string to print.
 * Return: Empty
 */

void _exputs(char *str)
{
	int i = 0;

	if (!str)
		return;
	while (str[i] != '\0')
	{
		_exputchar(str[i]);
		i++;
	}
}

/**
 * _exputchar - This function writes a character to stderr.
 * @c: The character to be written
 *
 * Return: On success 1, On error -1.
 */
int _exputchar(char c)
{
	static int i;
	static char buf[WRITE_BUF_SIZE];

	if (c == BUF_FLUSH || i >= WRITE_BUF_SIZE)
	{
		write(2, buf, i);
		i = 0;
	}
	if (c != BUF_FLUSH)
		buf[i++] = c;
	return (1);
}

/**
 * writeToFD - This function writes a character
 * to a given file descriptor.
 * @c: The character to be written
 * @fd: The file descriptor to write.
 * Return: On success 1, On error -1.
 */
int writeToFD(char c, int fd)
{
	static int i;
	static char buf[WRITE_BUF_SIZE];

	if (c == BUF_FLUSH || i >= WRITE_BUF_SIZE)
	{
		write(fd, buf, i);
		i = 0;
	}
	if (c != BUF_FLUSH)
		buf[i++] = c;
	return (1);
}

/**
 * printToFD - This function prints a string
 * to a given file descriptor.
 * @str: string to print.
 * @fd: The file descriptor to write.
 * Return: The number of characters written.
 */

int printToFD(char *str, int fd)
{
	int i = 0;

	if (!str)
		return (0);
	while (*str)
	{
		i += writeToFD(*str++, fd);
	}
	return (i);
}
