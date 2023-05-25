#include "shell.h"

/**
 * is_exe_cmd - determines if a file is an executable command
 * @info: information struct
 * @path: file path
 * Return: 1 if true, 0 if false
 */

int is_exe_cmd(info_t *info, char *path)
{
	struct stat st;

	(void)info;
	if (!path || stat(path, &st))
		return (0);

	if (st.st_mode & S_IFREG)
	{
		return (1);
	}
	return (0);
}

/**
 * dupChars - this function duplicates characters in a string
 * @pathstr: the string to duplicate characters from
 * @start: starting index
 * @stop: stopping index
 * Return: new buffer pointer
 */

char *dupChars(char *pathstr, int start, int stop)
{
	static char buf[1024];
	int i = 0, k = 0;

	for (k = 0, i = start; i < stop; i++)
		if (pathstr[i] != ':')
			buf[k++] = pathstr[i];
	buf[k] = 0;
	return (buf);
}

/**
 * find_cmd_path - used to find the full path of a command in the PATH string
 * @info: information struct
 * @pathstr: the string PATH
 * @cmd: command to find
 * Return: full path if successful or NULL
 */

char *find_cmd_path(info_t *info, char *pathstr, char *cmd)
{
	int i = 0, curr_pos = 0;
	char *path;

	if (!pathstr)
		return (NULL);
	if ((_strlen(cmd) > 2) && startsWith(cmd, "./"))
	{
		if (is_exe_cmd(info, cmd))
			return (cmd);
	}
	while (1)
	{
		if (!pathstr[i] || pathstr[i] == ':')
		{
			path = dupChars(pathstr, curr_pos, i);
			if (!*path)
				_strcat(path, cmd);
			else
			{
				_strcat(path, "/");
				_strcat(path, cmd);
			}
			if (is_exe_cmd(info, path))
				return (path);
			if (!pathstr[i])
				break;
			curr_pos = i;
		}
		i++;
	}
	return (NULL);
}
