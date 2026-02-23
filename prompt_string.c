/**
 * File: prompt_string.c
 * Auth: Eljan Badalov
 * Desc: Prints the shell prompt if interactive
 */
#include "main.h"
/**
 * print_prompt - prints the shell prompt
 * @status: 1 if shell is interactive
 *
 * Return: nothing
 */
void print_prompt(int status)
{
	if (status)
		printf("#cisfun$ ");
	else
		errno = 0;
}
