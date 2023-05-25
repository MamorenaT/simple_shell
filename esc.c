#include "shell.h"

/**
 **copyString - copies a string to another string
 *@destination: the string destination  to be copied to
 *@source: the source string
 *@max_bytes: the maximum number of bytes to be copied
 *Return: Strings that have been concatenated
 */
char *copyString(char *destination, char *source, int max_bytes)
{
	int i, j;
	char *result = destination;

	i = 0;
	while (source[i] != '\0' && i < max_bytes - 1)
	{
		destination[i] = source[i];
		i++;
	}
	if (i < max_bytes)
	{
		j = i;
		while (j < max_bytes)
		{
			destination[j] = '\0';
			j++;
		}
	}
	return (result);
}

/**
 **concatenateStrings - concatenates two strings
 *@string1: the first string to be concatenated.
 *@string2: the second string to be concatenated.
 *@max_bytes: the maximum number of bytes to be used
 *Return: the string that has been concatenated.
 */
char *concatenateStrings(char *string1, char *string2, int max_bytes)
{
	int i, j;
	char *result = string1;

	i = 0;
	j = 0;
	while (string1[i] != '\0')
		i++;
	while (string2[j] != '\0' && j < max_bytes)
	{
		string1[i] = string2[j];
		i++;
		j++;
	}
	if (j < max_bytes)
		string1[i] = '\0';
	return (result);
}

/**
 **find_char - finds a character in a string
 *@str: the string to be searched
 *@cha: the character to look for
 *Return: str pointer to the memory area
 */
char *find_char(char *str, char cha)
{
	do {
		if (*str == cha)
			return (str);
	} while (*str++ != '\0');

	return (NULL);
}
