#include "main.h"

/**
 * fork_it - creates a fork process
 *@arg: the command table
 *@argv: holds the name of the program
 *@env: enviroment variable
 *@input: the commands from getline function
 *@np: id of proces
 *@c: Checker add new test
 *Return: 0 success
 */

int fork_it(char **arg, char **av, char **env, char *input, int np, int c)
{
	pid_t child_pid;
	int status;
	char *format = "%s: %d: %s: not found\n";

	child_pid = fork();


	if (child_pid == 0)
	{
		if (execve(arg[0], arg, env) == -1)
		{
			fprintf(stderr, format, av[0], np, arg[0]);
			if (!c)
				free(arg[0]);
			free(arg);
			free(input);
			exit(errno);
		}
	}
	else
	{
		wait(&status);

		if (WIFEXITED(status) && WEXITSTATUS(status) != 0)
			return (WEXITSTATUS(status));
	}

	return (0);
}
