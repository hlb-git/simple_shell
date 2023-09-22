#include "main.h"
#include <limits.h>

/**
 * _isdigit - check if a given string is a number
 * @str: input string
 * Return: 1 if string is a number. 0 in otherwise.
 */
int _isdigit(const char *str)
{
	unsigned int i;

	for (i = 0; str[i]; i++)
	{
		if (str[i] < 48 || str[i] > 57)
			return (0);
	}
	return (1);
}
/**
 * exit_cmd - this exits the whole progragram if called
 * @arg: the tokenized array command of commands.
 * @argv: name of the shell
 * @input: the original string from the getline
 * @_exit: value of exit status
 */

void exit_cmd(char *argv, char **arg, char *input, int _exit)
{
	int exit_status = 0, is_digit, str_len, big_number;

	if (!arg[1]) /* frees the used memory if there is no specified exit status*/
	{
		free(input);
		free(arg);
		exit(_exit);
	}

	exit_status = atoi(arg[1]); /* if there is exit status is supplied */
	is_digit = _isdigit(arg[1]);
	str_len = _strlen(arg[1]);
	big_number = exit_status > INT_MAX;
	if (!is_digit || str_len > 10 || big_number)
	{
		fprintf(stderr, "%s: 1: %s: Illegal number: %s\n", argv, arg[0], arg[1]);
		free(input);
		free(arg);
		exit(2);
	}
	free(input);
	free(arg);
	exit(exit_status % 256);
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
