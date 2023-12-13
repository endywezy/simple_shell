#include "shell.h"
#include "string.h"

/**
 * is_cmd - The file check if a file is an executable command
 * @info: the parameter argument struct.
 * @path: path to the file
 *
 * Return: 1 if true, 0
 */
int is_cmd(info_t *info, char *path)
{
	(void)info;
	if (path != NULL)
	{
		struct stat st;

		if (stat(path, &st) == 0)
		{
			if (S_ISREG(st.st_mode))
			{
				return (1);
			}
		}
	}
	return (0);
}

/**
 * dup_chars - characters duplication
 * @pathstr: the PATH string
 * @start: to begin or starting the index
 * @stop: to end or  stopping the index
 *
 * Return: pointer to new buffer
 */
char *dup_chars(char *pathstr, int start, int stop)
{
	/*take in var declaration commands*/
	static char buf[1024];
	int i, k;

	for (k = 0, i = start; i < stop; i++)
		if (pathstr[i] != ':')
			buf[k++] = pathstr[i];
	buf[k] = '\0';
	return (buf);
}

/**
 * find_path - This function finds command in the PATH string
 * @info: the parameter argument struct.
 * @pathstr: the PATH string
 * @cmd: the command to find
 *
 * Return: full path of cmd if found or NULL
 */
char *find_path(info_t *info, char *pathstr, char *cmd)
{
	/*take in var declaration commands*/
	int i = 0, curr_pos = 0;
	char *path;

	if (!pathstr)
		return (NULL);

	if ((_strlen(cmd) > 2) && starts_with(cmd, "./"))
		return (is_cmd(info, cmd) ? cmd : NULL);

	while (1)
	{
		if (!pathstr[i] || pathstr[i] == ':')
		{
			path = dup_chars(pathstr, curr_pos, i);
			if (!*path)
				_strcat(path, cmd);
			else
				_strcat(path, "/");
			_strcat(path, cmd);

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
