#include "shell.h"

/**
 *_eputs - function will prints an input string we enter
 *
 * @str: the string to need to be printed.
 * Return: Nothing
 */


void _eputs(char *str)
{
	int i = 0;

	if (!str)
		return;
	while (str[i] != '\0')
	{
		_eputchar(str[i]);
		i++;
	}
}

/**
 * _eputchar - function to write the character c to stderr stream
 * @c: The character to we need to be printed
 *
 * Return: 1 means success the processe .
 * On error, -1 is returned, for fail the processe.
 */


int _eputchar(char c)
{
	static int i;
	static char buf[WRITE_BUF_SIZE];

	if (c == BUF_FLUSH || i >= WRITE_BUF_SIZE)
	{
		write(2, buf, i);
		i = 0;
	}
	if (c != BUF_FLUSH)
		buf[i++] = c;
	return (1);
}

/**
 * _putfd - function writes the character of c to given fd
 * @c: The character to be printedd
 * @fd: The filedescriptor to write for
 *
 * Return: On success 1. processe
 * On error, -1 is returned, fail the processse.
 */


int _putfd(char c, int fd)
{
	static int i;
	static char buf[WRITE_BUF_SIZE];

	if (c == BUF_FLUSH || i >= WRITE_BUF_SIZE)
	{
		write(fd, buf, i);
		i = 0;
	}
	if (c != BUF_FLUSH)
		buf[i++] = c;
	return (1);
}

/**
 *_putsfd - functio prints the input of string
 * @str: this is the string we need to be printed
 * @fd: the filedescriptor to write for
 *
 *
 * Return: the number of chars put
 */


int _putsfd(char *str, int fd)
{
	int i = 0;

	if (!str)
		return (0);
	while (*str)
	{
		i += _putfd(*str++, fd);
	}
	return (i);
}
