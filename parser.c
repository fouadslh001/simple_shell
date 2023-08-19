#include "shell.h"

/**
 * is_cmd - it will determines this function if a file is executable command
 * @info: the info of struct
 *
 * @path: path for the file
 *
 * Return: 1 true and 0 otherwise or false
 */


int is_cmd(info_t *info, char *path)
{
	struct stat st;

	(void)info;
	if (!path || stat(path, &st))
		return (0);

	if (st.st_mode & S_IFREG)
	{
		return (1);
	}
	return (0);
}

/**
 * dup_chars - function that it will duplicate the characters
 * @pathstr: the PATH of string characters
 *
 * @start: starting of the a index
 * @stop: wil stopping the index
 *
 * Return: a pointer to new buffer
 */


char *dup_chars(char *pathstr, int start, int stop)
{
	static char buf[1024];
	int i = 0, k = 0;

	for (k = 0, i = start; i < stop; i++)
		if (pathstr[i] != ':')
			buf[k++] = pathstr[i];
	buf[k] = 0;
	return (buf);
}

/**
 * find_path - functionn it finds this cmd in the PATH string
 * @info: the info of the struct
 *
 * @pathstr: the PATH to the String
 * @cmd: the Command we need to find
 *
 * Return: will get thefull path of cmd if found or NULL
 */

char *find_path(info_t *info, char *pathstr, char *cmd)
{
	int i = 0, curr_pos = 0;
	char *path;

	if (!pathstr)
		return (NULL);
	if ((_strlen(cmd) > 2) && starts_with(cmd, "./"))
	{
		if (is_cmd(info, cmd))
			return (cmd);
	}
	while (1)
	{
		if (!pathstr[i] || pathstr[i] == ':')
		{
			path = dup_chars(pathstr, curr_pos, i);
			if (!*path)
				_strcat(path, cmd);
			else
			{
				_strcat(path, "/");
				_strcat(path, cmd);
			}
			if (is_cmd(info, path))
				return (path);
			if (!pathstr[i])
				break;
			curr_pos = i;
		}
		i++;
	}
	return (NULL);
}
