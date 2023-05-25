#include "shell.h"

/**
 * getStringLength - returns the length of a given string
 * @s: The string whose length is to be determined
 * Return: The length of the string.
 */

int getStringLength(char *s)
{
	int i = 0;

	if (!s)
		return (0);

	while (*s++)
		i++;
	return (i);
}

/**
 * compareStrings - compares two strings lexicographically
 * @s1: The first string to be compared.
 * @s2: The second string to be compared.
 * Return: Negative if s1 < s2, positive if s1 > s2, zero if s1 == s2.
 */

int compareStrings(char *s1, char *s2)
{
	while (*s1 && *s2)
	{
		if (*s1 != *s2)
			return (*s1 - *s2);
		s1++;
		s2++;
	}
	if (*s1 == *s2)
		return (0);
	else
		return (*s1 < *s2 ? -1 : 1);
}

/**
 * startsWith - checks if a string starts with a given substring
 * @haystack: The string to search.
 * @needle: The substring to find.
 * Return: The address of the next character of haystack or NULL.
 */

char *startsWith(const char *haystack, const char *needle)
{
	while (*needle)
		if (*needle++ != *haystack++)
			return (NULL);
	return ((char *)haystack);
}

/**
 * concatenateStrings - this function concatenates two strings
 * @dest: The destination buffer.
 * @src: The source buffer.
 * Return: A pointer to the destination buffer.
 */

char *concatenateStrings(char *dest, char *src)
{
	char *ret = dest;

	while (*dest)
		dest++;
	while (*src)
		*dest++ = *src++;
	*dest = *src;
	return (ret);
}
