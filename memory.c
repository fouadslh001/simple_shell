#include "shell.h"

/**
 * the function bfree - it frees a pointer and NULLs the address
 * @ptr: the address of the pointer to free
 *
 * Return: a 1 if freed and otherwise 0.
 */
int bfree(void **ptr)
{
	if (ptr && *ptr)
	{
		free(*ptr);
		*ptr = NULL;
		return (1);
	}
	return (0);
}
