#include "shell.h"

/**
 * interactive_mode - This function checks if the shell
 * is in interactive mode.
 * @info: A pointer to the struct.
 * Return: 1 if the shell is in interactive mode, 0 if not.
 */

int interactive_mode(info_t *info)
{
	return (isatty(STDIN_FILENO) && info->readfd <= 2);
}

/**
 * char_delim - This function checks if
 * a character is a delimiter.
 * @c: The character to check
 * @delim: The delimiter string
 * Return: 1 if the character is a delimiter, 0 if not
 */
int char_delim(char c, char *delim)
{
	while (*delim)
		if (*delim++ == c)
			return (1);
	return (0);
}

/**
 * char_alpha - This function checks if a
 * character is alphabetic.
 * @c: The character to check
 * Return: 1 if the character is alphabetic, 0 if not.
 */

int char_alpha(int c)
{
	if ((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z'))
		return (1);
	else
		return (0);
}

/**
 * str_to_int - This function converts a
 * string to an integer.
 * @s: The string to be converted
 * Return: 0 if there are no numbers in the string,
 * the converted number otherwise
 */

int str_to_int(char *s)
{
	int i, sign = 1, flag = 0, output;
	unsigned int result = 0;

	for (i = 0; s[i] != '\0' && flag != 2; i++)
	{
		if (s[i] == '-')
			sign *= -1;

		if (s[i] >= '0' && s[i] <= '9')
		{
			flag = 1;
			result *= 10;
			result += (s[i] - '0');
		}
		else if (flag == 1)
			flag = 2;
	}

	if (sign == -1)
		output = -result;
	else
		output = result;

	return (output);
}
