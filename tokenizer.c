#include "shell.h"

/**
 * splitStr - splits a string into an array of words,
 * using a specified delimiter
 * @str: input string
 * @d: delimiter string
 * Return: array of strings on success, NULL on failure
 */

char **splitStr(char *str, char *d)
{
	int i, j, k, m, numWords = 0;
	char **words;

	if (str == NULL || str[0] == 0)
		return (NULL);
	if (!d)
		d = " ";
	for (i = 0; str[i] != '\0'; i++)
		if (!isDelimiter(str[i], d) && (isDelimiter(str[i + 1], d) || !str[i + 1]))
			numWords++;

	if (numWords == 0)
		return (NULL);
	words = malloc((1 + numWords) * sizeof(char *));
	if (!words)
		return (NULL);
	for (i = 0, j = 0; j < numWords; j++)
	{
		while (isDelimiter(str[i], d))
			i++;
		k = 0;
		while (!isDelimiter(str[i + k], d) && str[i + k])
			k++;
		words[j] = malloc((k + 1) * sizeof(char));
		if (!words[j])
		{
			for (k = 0; k < j; k++)
				free(words[k]);
			free(words);
			return (NULL);
		}
		for (m = 0; m < k; m++)
			words[j][m] = str[i++];
		words[j][m] = 0;
	}
	words[j] = NULL;
	return (words);
}

/**
 * split_str - function splits a string into an array of words,
 * using a specified delimiter.
 * @str: the input string
 * @d: the delimiter character
 * Return: pointer to an array of strings, or NULL on failure
 */

char **split_str(char *str, char d)
{
	int i, j, k, m, numWords = 0;
	char **words;

	if (str == NULL || str[0] == 0)
		return (NULL);
	for (i = 0; str[i] != '\0'; i++)
		if ((str[i] != d && str[i + 1] == d) ||
			(str[i] != d && !str[i + 1]) || str[i + 1] == d)
			numWords++;
	if (numWords == 0)
		return (NULL);
	words = malloc((1 + numWords) * sizeof(char *));
	if (!words)
		return (NULL);
	for (i = 0, j = 0; j < numWords; j++)
	{
		while (str[i] == d && str[i] != d)
			i++;
		k = 0;
		while (str[i + k] != d && str[i + k] && str[i + k] != d)
			k++;
		words[j] = malloc((k + 1) * sizeof(char));
		if (!words[j])
		{
			for (k = 0; k < j; k++)
				free(words[k]);
			free(words);
			return (NULL);
		}
		for (m = 0; m < k; m++)
			words[j][m] = str[i++];
		words[j][m] = 0;
	}
	words[j] = NULL;
	return (words);
}
