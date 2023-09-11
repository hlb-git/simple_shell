#include <stdio.h>
#include <stdlib.h>

extern char **environ;

/**
 * main - the main function
 * @ac: the number of command line arguements
 * @av: the array of the arguements
 * @env: array of enviroment variables
 * Return: returns 0 on success
 */

int main(int ac __attribute__((unused)), char *av[] __attribute__((unused)), char *env[])
{
	printf("Address of env (main parameter): %p\n", (void *)env);
	printf("Address of environ (global variable): %p\n", (void *)environ);

	return (0);
}
