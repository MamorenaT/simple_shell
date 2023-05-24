#include "shell.h"

/**
 * buffer_commands: This function buffers chained commands and
 * returns the number of bytes read.
 * @info: A struct containing information about the command
 * @buf: A pointer to the buffer
 * @len: A pointer to the length of the buffer
 * @return The number of bytes read
 */
ssize_t buffer_commands(info_t *info, char **buf, size_t *len)
{
	ssize_t r = 0;
	size_t len_p = 0;

	if (!*len)
	{
		free(*buf);
		*buf = NULL;
		signal(SIGINT, sigintHandler);
#if USE_GETLINE
		r = getline(buf, &len_p, stdin);
#else
		r = _getline(info, buf, &len_p);
#endif
		if (r > 0)
		{
			if ((*buf)[r - 1] == '\n')
			{
				(*buf)[r - 1] = '\0';
				r--;
			}
			info->linecount_flag = 1;
			remove_comments(*buf);
			build_history_list(info, *buf, info->histcount++);

			{
				*len = r;
				info->cmd_buf = buf;
			}
		}
	}
	return (r);
}

/**
 * getInput: this function gets a line of input.
 * @info: A struct containing information about the command
 * @return The number of bytes read
 */
ssize_t getInput(info_t *info)
{
	static char *buf;
	static size_t i, j, len;
	ssize_t r = 0;
	char **buf_p = &(info->arg), *p;

	_putchar(BUF_FLUSH);
	r = buffer_commands(info, &buf, &len);
	if (r == -1) /* EOF */
		return (-1);
	if (len)
	{
		j = i;
		p = buf + i;

		check_chain(info, buf, &j, i, len);
		while (j < len)
		{
			if (is_chain(info, buf, &j))
				break;
			j++;
		}

		i = j + 1;
		if (i >= len)
		{
			i = len = 0;
			info->cmd_buf_type = CMD_NORM;
		}

		*buf_p = p;
		return (_strlen(p));
	}

	*buf_p = buf;
	return (r);
}

/**
 * reads_buff - This function reads a buffer.
 * @info: A struct containing information about the command
 * @buf: The buffer pointer.
 * @i: The size pointer.
 * Return: r
 */
ssize_t reads_buff(info_t *info, char *buf, size_t *i)
{
	ssize_t r = 0;

	if (*i)
		return (0);
	r = read(info->readfd, buf, READ_BUF_SIZE);
	if (r >= 0)
		*i = r;
	return (r);
}

/**
 * get_next_line - This function gets the next
 * line of input from STDIN.
 * @info: A struct containing information about the command
 * @ptr: A pointer to the buffer, preallocated or NULL
 * @length: The size of preallocated ptr buffer if not NULL
 * Return: s
 */
int get_next_line(info_t *info, char **ptr, size_t *length)
{
	static char buf[READ_BUF_SIZE];
	static size_t i, len;
	size_t k;
	ssize_t r = 0, s = 0;
	char *p = NULL, *new_p = NULL, *c;

	p = *ptr;
	if (p && length)
		s = *length;
	if (i == len)
		i = len = 0;

	r = read_buffer(info, buf, &len);
	if (r == -1 || (r == 0 && len == 0))
		return (-1);

	c = _strchr(buf + i, '\n');
	k = c ? 1 + (unsigned int)(c - buf) : len;
	new_p = _realloc(p, s, s ? s + k : k + 1);
	if (!new_p) /* MALLOC FAILURE! */
		return (p ? free(p), -1 : -1);

	if (s)
		_strncat(new_p, buf + i, k - i);
	else
		_strncpy(new_p, buf + i, k - i + 1);

	s += k - i;
	i = k;
	p = new_p;

	if (length)
		*length = s;
	*ptr = p;
	return (s);
}

/**
 * block_ctrl_c - This function blocks ctrl-C.
 * @sig_num: signal number
 * Return: Empty
 */
void block_ctrl_c(__attribute__((unused))int sig_num)
{
	_puts("\n");
	_puts("$ ");
	_putchar(BUF_FLUSH);
}
