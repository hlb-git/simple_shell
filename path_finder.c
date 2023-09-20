#include "main.h"
char *_strcpcat(char *dest, char *path, char *cmd);
/**
 * find_path - finds the path of the inputed command
 * @cmd: the command to find its path
 * Return: returns a pointer to the found command
 */

char *find_path(char *cmd)
{
	char *full_path, *token, *original_path,  *path, *tok_path[256];
	int count = 0, i = 0;
	struct stat check;

	original_path = getenv("PATH");
	path = dupstr(original_path);
	if (original_path == NULL)

	{
		perror("PATH environment variable not set.");
		return (NULL);
	}

	if (stat(cmd, &check) == 0)
		return (cmd);
	token = strtok(path, ":");
	while (token)
	{
		tok_path[i] = token;
		i++;
		token = strtok(NULL, ":");
	}
	tok_path[i] = NULL;
	free(path);
	i = 0;
	while (tok_path[i])
	{
		for (count = 0; tok_path[i][count]; count++)
		{}
		if (tok_path[i][count - 1] != '/')
		{
			full_path = (char *)malloc(_strlen(tok_path[i]) + _strlen(cmd) + 2);
			if (full_path == NULL)
			{
				perror("malloc");
				return (NULL);
			}
			_strcpcat(full_path, tok_path[i], cmd);
			if (stat(full_path, &check) == 0)
				break;
			free(full_path);
		}
		i++;
	}
	if (stat(full_path, &check) == -1)
		return (NULL);
	return (full_path);
}

/**
 * _strcpcat - function to copy and concatenate a path with a command
 * @dest: destination to store result
 * @path: path to be added
 * @cmd: command typed by user
 * Return: pointer to the destination
 */
char *_strcpcat(char *dest, char *path, char *cmd)
{
	_strcpy(dest, path);
	_strcat(dest, "/");
	_strcat(dest, cmd);

	return (dest);
}
