/**
 * File: find_file.c
 * Auth: Eljan Badalov
 * Desc: Finds the full path of a command using PATH directories
 */
#include "main.h"
/**
 * find_file - finds a command location in PATH directories
 * @command: user input command
 * @lk: set to 1 if returned command was built using PATH (needs free)
 *
 * Return: command itself if absolute/relative exists, a newly allocated
 * string if found via PATH, or NULL if not found
 */
char *find_file(char *command, int *lk)
{
	int i = 0, len;
	char *temp;
	struct stat st;

	if (command[0] == '/' || command[0] == '.')
		if (!stat(command, &st))
			return (command);
	if (!path_var)
		return (NULL);
	while (path_var[i])
	{
		len = strlen(path_var[i]);
		temp = strdup(path_var[i]);
		temp = realloc(temp, len + strlen(command) + 2);
		temp[len] = '/', temp[len + 1] = '\0';
		temp = strcat(temp, command);
		if (!stat(temp, &st))
		{
			(*lk)++;
			errno = 0;
			return (temp);
		}
		i++;
		free(temp);
	}
	return (NULL);
}
