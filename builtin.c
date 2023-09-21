#include "main.h"

/**
 * exit_cmd - this exits the whole progragram if called
 * @arg: the tokenized array command of commands.
 * @input: the original string from the getline
 * @_exit: value of exit status
 */

void exit_cmd(char **arg, char *input, int _exit)
{
	int exit_status = 0;

	if (!arg[1]) /* frees the used memory if there is no specified exit status*/
	{
		free(input);
		free(arg);
		exit(_exit);
	}

	exit_status = atoi(arg[1]); /* if there is exit status is supplied */

	free(input);
	free(arg);
	exit(exit_status);
}

/**
 *my_getenv - this function gets all the enviroment variables in the kernel
 *@env: the enviroment variable
 */

void my_getenv(char **env)
{
	size_t index = 0;

	while (env[index])
	{
		write(STDOUT_FILENO, env[index], _strlen(env[index]));
		write(STDOUT_FILENO, "\n", 1);
		index++;
	}
}
