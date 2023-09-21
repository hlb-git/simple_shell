#include "main.h"

/**
 * find_path - sets ordinary cmd_len to executable one with the path.
 * @arg: cmd_len input of user form the command line.
 * @env: enviroment variable.
 * Return:  0 on success and -1 if it didn't perform the task.
 */

int find_path(char **arg, char **env)
{
	char *token = NULL, *env_val = NULL, *full_path = NULL;
	size_t path_len, cmd_len;
	struct stat check;

	if (stat(*arg, &check) == 0)
		return (-1);
	env_val = get_env(env); /*gets the value of the PATH enviroment variable*/
	if (!env_val)
		return (-1);
	token = strtok(env_val, ":");
	cmd_len = _strlen(*arg);
	while (token)
	{
		path_len = _strlen(token);
		full_path = malloc(sizeof(char) * (path_len + cmd_len + 2));
		if (!full_path)
		{
			free(env_val);
			return (-1);
		}
		full_path = _strcpy(full_path, token);
		_strcat(full_path, "/");
		_strcat(full_path, *arg);
		/* the above operations contatinats the command with the each token path*/
		if (stat(full_path, &check) == 0)
		{
			*arg = full_path;
			free(env_val);
			return (0);
		}
		free(full_path);
		token = strtok(NULL, ":");
	}
	free(env_val);
	return (-1);
}
