#include "shell.h"

/**
 * bfree - a function will its frees a pointer and NULLs the their address
 * @ptr: the address of the pointer to nood to free their memory
 *
 * Return: a 1 if freed and otherwise will get 0.
 *
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
