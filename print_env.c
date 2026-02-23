/**
 * File: print_env.c
 * Auth: Eljan Badalov
 * Desc: Prints all environment variables
 */
#include "main.h"
/**
 * print_env - prints the environment variables
 *
 * Return: nothing
 */
void print_env(void)
{
	int i = 0;

	while (environ[i])
	{
		printf("%s\n", environ[i]);
		i++;
	}
}
