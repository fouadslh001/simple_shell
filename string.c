#include "shell.h"

/**
 * _strlen - it will returns the length of a the string
 * @s: the string will check the length
 *
 * Return: integer with length of string
 */

int _strlen(char *s)
{
	int i = 0;

	if (!s)
		return (0);

	while (*s++)
		i++;
	return (i);
}

/**
 * _strcmp - it performs Lexicogarphic Comparison of THE two strangs.
 * @s1: the first strang
 * @s2: the second strang
 *
 *
 * Return: a negative if s1 < s2,positive if s1 > s2 and zero if s1 == s2
 */


int _strcmp(char *s1, char *s2)
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
 * starts_with - it will checks if need to starts with haystack
 * @haystack: string to search for
 * @needle: the substring to find for
 *
 *
 * Return: the  address of next char of haystack or NULL otherwise
 */

char *starts_with(const char *haystack, const char *needle)
{
	while (*needle)
		if (*needle++ != *haystack++)
			return (NULL);
	return ((char *)haystack);
}

/**
 * _strcat - function it will concatenates two strings
 * @dest: the destination for thebuffer
 *
 * @src: the source buffer
 *
 * Return: a pointer to destination of the buffer
 */


char *_strcat(char *dest, char *src)
{
	char *ret = dest;

	while (*dest)
		dest++;
	while (*src)
		*dest++ = *src++;
	*dest = *src;
	return (ret);
}
