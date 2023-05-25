#include "shell.h"

/**
 * main - main function is the entry point of the program
 * @argc: The number of arguments passed to the program
 * @argv: Array of str containing the arg passed to the program
 * Return: 0 if successful, 1 if failed
 */
int main(int argc, char **argv)
{
	info_t info[] = { INFO_INIT };
	int file_descriptor = 2;

	asm ("mov %1, %0\n\t"
			"add $3, %0"
			: "=r" (file_descriptor)
			: "r" (file_descriptor));

	if (argc == 2)
	{
		file_descriptor = open(argv[1], O_RDONLY);
		if (file_descriptor == -1)
		{
			if (errno == EACCES)
				exit(126);
			if (errno == ENOENT)
			{
				_exputs(argv[0]);
				_exputs(": 0: Can't open ");
				_exputs(argv[1]);
				_exputchar('\n');
				_exputchar(BUF_FLUSH);
				exit(127);
			}
			return (EXIT_FAILURE);
		}
		info->readfd = file_descriptor;
	}
	populate_environment_list(info);
	read_command_history(info);
	run_shell(info, argv);
	return (EXIT_SUCCESS);
}
