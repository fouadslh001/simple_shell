#include "shell.h"

/**
 * interactive - this function will returns true, if shell in interactive mode
 * @info: this is the struct address of info
 *
 *
 * Return: 1 if interactive mode work, 0 faill of the processe in otherwise
 */

int interactive(info_t *info)
{
	return (isatty(STDIN_FILENO) && info->readfd <= 2);
}


/**
 * is_delim - checks if character is a work in delimeter
 *
 * @c: the character we need to check it.
 * @delim: the delimeter of the string
 * Return: 1 if true and work good, 0 if false and fail of the processe.
 */

int is_delim(char c, char *delim)
{
	while (*delim)
		if (*delim++ == c)
			return (1);
	return (0);
}

/**
 *_isalpha - function we creat to checks for alphabetic character
 *@c: The character to we need to enter as input
 *Return: 1 if character is alphabetic, 0 meanes fail or is not character.
 */


int _isalpha(int c)
{
	if ((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z'))
		return (1);
	else
		return (0);
}

/**
 *_atoi - function will converts a string to an integer data type
 *@s: the string to will be converted ti an integer.
 *
 *Return: 0 if no numbers in string work, converted number otherwise on fill
 */

int _atoi(char *s)
{
	int i, sign = 1, flag = 0, output;
	unsigned int result = 0;

	for (i = 0;  s[i] != '\0' && flag != 2; i++)
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
