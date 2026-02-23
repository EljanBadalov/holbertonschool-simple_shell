/**
 * File: exec_comm.c
 * Auth: Eljan Badalov
 * Desc: Executes a command using fork and execve
 */
#include "main.h"
/**
 * exec_c - executes a command provided by the user
 * @fcommand: NULL-terminated array of command arguments
 *
 * Return: exit status code of the executed command, or 1 on failure
 */
int exec_c(char **fcommand)
{
	pid_t pid;
	int r_code;

	pid = fork();
	if (pid == 0)
		r_code = execve(fcommand[0], fcommand, environ);
	else
	{
		wait(&r_code);
		return (WEXITSTATUS(r_code));
	}
	return (r_code);
}
