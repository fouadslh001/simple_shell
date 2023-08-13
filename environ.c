#include "shell.h"



/**
 * _myenv - function that prints the current of environment
 * @info: Structure will containing a potential arguments. Used to maintain
 * and enter a constant function prototype.
 *
 * Return: Always 0 means evrythings work good.
 */

int _myenv(info_t *info)
{
	print_list_str(info->env);
	return (0);
}

/**
 * _getenv - function that gets, the value of a environ variable
 *
 * @info: Structure containing the potential arguments. will enter.
 * @name: env var name to enter
 *
 * Return: the value we need
 */

char *_getenv(info_t *info, const char *name)
{
	list_t *node = info->env;
	char *p;

	while (node)
	{
		p = starts_with(node->str, name);
		if (p && *p)
			return (p);
		node = node->next;
	}
	return (NULL);
}

/**
 * _mysetenv - it Initialize a new environment variable,
 * or will modify an existing one we need.
 *
 * @info: Structure containing the potential arguments. Used to enter
 * the constant function prototype.
 *
 *  Return: Always 0 means evrythings is working good.
 */

int _mysetenv(info_t *info)
{
	if (info->argc != 3)
	{
		_eputs("Incorrect number of arguements\n");
		return (1);
	}
	if (_setenv(info, info->argv[1], info->argv[2]))
		return (0);
	return (1);
}

/**
 * _myunsetenv - this function Remove and delate environment variable
 * @info: Structure containing potential arguments. Used to enter
 * for a constant function prototype.
 *
 * Return: Always 0 means working the processe
 */

int _myunsetenv(info_t *info)
{
	int i;

	if (info->argc == 1)
	{
		_eputs("Too few arguements.\n");
		return (1);
	}
	for (i = 1; i <= info->argc; i++)
		_unsetenv(info, info->argv[i]);

	return (0);
}

/**
 * populate_env_list - finction populates envirment a linked list
 * @info: Structure containing potential arguments. Used to enter
 *          for constant function prototype.
 *
 * Return: Always 0 evrythings work good
 */


int populate_env_list(info_t *info)
{
	list_t *node = NULL;
	size_t i;

	for (i = 0; environ[i]; i++)
		add_node_end(&node, environ[i], 0);
	info->env = node;
	return (0);
}
