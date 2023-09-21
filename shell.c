#include "main.h"

/**
 * main - the programm starts here
 * @argc:count of argumnents
 * @argv: arguments
 * @env: environment
 * Return: _exit = 0.
 */

int main(int argc, char **argv, char **env)
{
	char *get_command = NULL, **tokzed_cmd = NULL;
	int path_value = 0, _exit = 0, n = 0;
	(void)argc; /* this is not used */

	while (1)
	{
		get_command = getline_cmd(); /*just like our formal getline funtion */
		if (get_command) /* if the the user didnt just press enter */
		{
			path_value++;
			tokzed_cmd = get_token(get_command);
			if (!tokzed_cmd)
			{
				free(get_command);
				continue;
			}
			if ((!_strcmp(tokzed_cmd[0], "exit")) && tokzed_cmd[1] == NULL)
				exit_cmd(tokzed_cmd, get_command, _exit);
			if (!_strcmp(tokzed_cmd[0], "env"))
				my_getenv(env);
			else
			{
				n = find_path(&tokzed_cmd[0], env);
				_exit = fork_it(tokzed_cmd, argv, env, get_command, path_value, n);
				if (n == 0)
					free(tokzed_cmd[0]);
			}
			free(tokzed_cmd);
		}
		else
		{
			if (isatty(STDIN_FILENO))
				write(STDOUT_FILENO, "\n", 1);
			exit(_exit);
		}
		free(get_command);
	}
	return (_exit);
}
