/**
 * File: init_path.c
 * Auth: Eljan Badalov
 * Desc: Initializes and frees the PATH variable array for the shell
 */
#include "main.h"
char **path_var = NULL;

/**
 * find_path - finds the PATH entry in the environment variables
 * @var: environment variables array
 * @i: row index (updated by function)
 * @j: column index (updated by function)
 *
 * Return: nothing
 */
void find_path(char **var, int *i, int *j)
{
	while (var[*i])
	{
		while (var[*i][*j])
		{
			if (var[*i][*j] == PATH[*j])
			{
				if (var[*i][*j] == '=')
					return;
				(*j)++;
			}
			else
				break;
		}
		(*i)++;
		*j = 0;
	}
	*i = 0;
	*j = 0;
}
/**
  * get_path - init path array
  * @env: environment variables array pointer
  * Return: path array
  */
char **get_path(char **env)
{
	int i = 0, j = 0;
	char **array;

	find_path(env, &i, &j);
	if (i == 0 && j == 0)
	{
		return (NULL);
	}
	j++;
	array = _strtok(env[i] + j, ':');
	if (!array)
	{
		free(array);
		return (NULL);
	}
	return (array);
}
/**
 * free_path - free path buffer
 */
void free_path(void)
{
	int i = 0;

	if (!path_var)
		return;
	while (path_var[i])
		free(path_var[i++]);
	free(path_var);
}
