#include "shell.h"

/**
 * exit_shell - This function exits the shell.
 * @info: A structure that contains potential arg
 * to maintain constant function prototype.
 * Return: Exits with a given exit status (0) if info.argv[0] != "exit".
 */

int exit_shell(info_t *info)
{
int exit_status;

	if (info->argv[1])
{
		exit_status = _erratoi(info->argv[1]);
	if (exit_status == -1)
{
	info->status = 2;
	print_error(info, "Illegal number: ");
	_exputs(info->argv[1]);
	_exputchar('\n');
	return (1);
	}
	info->err_num = _erratoi(info->argv[1]);
	return (-2);
	}
	info->err_num = -1;
	return (-2);
}

/**
 * chng_dir - This function changes the current directory of the process.
 * @info: A structure containing potential arguments. Used to maintain
 * constant function prototype.
 * Return: Always 0.
 */
int chng_dir(info_t *info)
{
	char *s, *dir, buffer[1024];
	int chdir_ret;

	s = getcwd(buffer, 1024);
	if (!s)
	_puts("TODO: >>getcwd failure emsg here<<\n");
	if (!info->argv[1])
	{
	dir = get_env_var(info, "HOME=");
	if (!dir)
	chdir_ret =
	chdir((dir = get_env_var(info, "PWD=")) ? dir : "/");
	else
	chdir_ret = chdir(dir);
	}
	else if (_strcmp(info->argv[1], "-") == 0)
	{
	if (!get_env_var(info, "OLDPWD="))
	{
	 _puts(s);
	_putchar('\n');
	return (1);
	}
	_puts(get_env_var(info, "OLDPWD=")), _putchar('\n');
	chdir_ret =
	chdir((dir = get_env_var(info, "OLDPWD=")) ? dir : "/");
	}
	else
	chdir_ret = chdir(info->argv[1]);
	if (chdir_ret == -1)
	{
	print_error(info, "can't cd to ");
	_exputs(info->argv[1]), _exputchar('\n');
	}
	else
	{
	_setenv(info, "OLDPWD", get_env_var(info, "PWD="));
	_setenv(info, "PWD", getcwd(buffer, 1024));
	}
	return (0);
}

/**
 * dis_hlp - This function displays help information.
 * @info: A structure that contains ,potential arg
 * to maintain constant function prototype.
 * Return: Always 0.
 */
int dis_hlp(info_t *info)
{
	char **arg_array;

	arg_array = info->argv;
	_puts("Calling for assistance operates. Unimplemented functionality\n");
	if (0)
	_puts(*arg_array);
	return (0);
}
