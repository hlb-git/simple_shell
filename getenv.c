#include "main.h"

/**
 * get_env- finds and return a pointer to the variable PATH.
 * @env: enviroment variable of the kernel
 * Return: a pointer to the string of the PATH variable.
 */

char *get_env(char **env)
{
	size_t index = 0, var = 0, count = 5;
	char *path = NULL;

	for (index = 0; _strncmp(env[index], "PATH=", 5); index++)
		;
	/**
	 * this loop above compares the first 5 characters of the
	 * enviroment variable if they match PATH= ...
	 * if it matches the loop breaks
	 */

	if (env[index] == NULL)
		return (NULL); /* if the loop doesn't match any, return NULL */

	for (count = 5; env[index][var]; var++, count++)
		; /* this loop here counts the number of characters in the env*/

	path = malloc(sizeof(char) * (count + 1));

	if (path == NULL)
		return (NULL);

	for (var = 5, count = 0; env[index][var]; var++, count++)
		path[count] = env[index][var];
	/*copies the value of the characters after the PATH= to the path pointer*/
	path[count] = '\0';
	return (path);
}
