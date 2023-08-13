#include "shell.h"

/**
 **_strncpy - this function will copies a string
 *
 *@dest: the destination of our string need to be copied for
 *@src: is our source string
 *@n: will be the amount of characters need to be copied
 *Return: the concatenated string
 *
 */


char *_strncpy(char *dest, char *src, int n)
{
	int i, j;
	char *s = dest;

	i = 0;
	while (src[i] != '\0' && i < n - 1)
	{
		dest[i] = src[i];
		i++;
	}
	if (i < n)
	{
		j = i;
		while (j < n)
		{
			dest[j] = '\0';
			j++;
		}
	}
	return (s);
}

/**
 **_strncat - this function will concatenates 2 strings
 *@dest: dest of the first string
 *@src: src of the second string
 *@n: the amount need of bytes to be maximally used
 *
 *Return: the concatenated string
 */


char *_strncat(char *dest, char *src, int n)
{
	int i, j;
	char *s = dest;

	i = 0;
	j = 0;
	while (dest[i] != '\0')
		i++;
	while (src[j] != '\0' && j < n)
	{
		dest[i] = src[j];
		i++;
		j++;
	}
	if (j < n)
		dest[i] = '\0';
	return (s);
}

/**
 **_strchr - function will locates a character, in the string
 *
 *@s: the string need for to be parsed
 *@c: the character to be look for and check
 *Return: (s) a pointer to the memory area s
 *
 */


char *_strchr(char *s, char c)
{
	do {
		if (*s == c)
			return (s);
	} while (*s++ != '\0');

	return (NULL);
}
