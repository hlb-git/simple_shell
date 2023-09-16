#include "main.h"

/**
 * find_path - finds the path of the inputed command
 * @cmd: the command to find its path
 * Return: returns a pointer to the found command
 */

char *find_path(char *cmd)
{
	char *tok_path[256];
	char *full_path, *token, *path = getenv("PATH");
	int count = 0, i = 0;
	struct stat check;

	if (path == NULL)
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
	i = 0;
	while (tok_path[i])
	{
		for (count = 0; tok_path[i][count]; count++)
		{}
		if (tok_path[i][count - 1] != '/')
        {
            /* Allocate memory for full_path and construct it separately*/
            full_path = (char *)malloc(strlen(tok_path[i]) + strlen(cmd) + 2);
            if (full_path == NULL)
            {
                perror("malloc");
                return NULL;
            }
            strcpy(full_path, tok_path[i]);
            strcat(full_path, "/");
            strcat(full_path, cmd);

            if (stat(full_path, &check) == 0)
                break;
            free(full_path);
        }
        i++;
	}
	return (full_path);
}
