#include "shell.h"

/**
 * _myhistory - this function displays the history list, one command by a line, to preceded
 *    it with line numbers, when we starting at 0.
 * @info: Structure containing the potential arguments to enter. Used to maintain
 * this constant function prototype.
 *
 *  Return: Always 0 means sucssese of the processe.
 */


int _myhistory(info_t *info)
{
	print_list(info->history);
	return (0);
}



/**
 * unset_alias - sets an alias to strings.
 *
 * @info: the parameter of the struct to enter
 * @str: the strings of the alias.
 *
 * Return: Always 0 on success the procsesse, 1 on error or faill.
 */


int unset_alias(info_t *info, char *str)
{
	char *p, c;
	int ret;

	p = _strchr(str, '=');
	if (!p)
		return (1);
	c = *p;
	*p = 0;
	ret = delete_node_at_index(&(info->alias),
		get_node_index(info->alias, node_starts_with(info->alias, str, -1)));
	*p = c;
	return (ret);
}


/**
 * set_alias - sets the alias to string
 *
 * @info: parameter to the struct
 * @str: the string of this alias
 *
 *
 * Return: Always 0 on success the processe, 1 on error or faill.
 */


int set_alias(info_t *info, char *str)
{
	char *p;

	p = _strchr(str, '=');
	if (!p)
		return (1);
	if (!*++p)
		return (unset_alias(info, str));

	unset_alias(info, str);
	return (add_node_end(&(info->alias), str, 0) == NULL);
}



/**
 * print_alias - prints an of the alias string
 * @node: the alias node we expected
 *
 * Return: Always 0 on sucsse , 1 on error or faill
 */

int print_alias(list_t *node)
{
	char *p = NULL, *a = NULL;

	if (node)
	{
		p = _strchr(node->str, '=');
		for (a = node->str; a <= p; a++)
			_putchar(*a);
		_putchar('\'');
		_puts(p + 1);
		_puts("'\n");
		return (0);
	}
	return (1);
}



/**
 * _myalias - mimics the alias builtin man of alias
 *
 * @info: Structure containing expected arguments. Used to enter
 *   for constant function prototype.
 *
 *  Return: Always 0 means working good
 */

int _myalias(info_t *info)
{
	int i = 0;
	char *p = NULL;
	list_t *node = NULL;

	if (info->argc == 1)
	{
		node = info->alias;
		while (node)
		{
			print_alias(node);
			node = node->next;
		}
		return (0);
	}
	for (i = 1; info->argv[i]; i++)
	{
		p = _strchr(info->argv[i], '=');
		if (p)
			set_alias(info, info->argv[i]);
		else
			print_alias(node_starts_with(info->alias, info->argv[i], '='));
	}

	return (0);
}
