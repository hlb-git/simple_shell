#include "main.h"

/**
 * get_token - tokenizes the string passed in the function
 * @input: comman user
 * Return: To a pointer
 */

char **get_token(char *input)
{
	char **user_command = NULL;
	char *token = NULL;
	size_t i = 0;
	int size = 0;

	if (input == NULL)
		return (NULL);

	for (i = 0; input[i]; i++)
	{
		if (input[i] == ' ')
			size++;
	}
	if ((size + 1) == _strlen(input))
		return (NULL); /*this checks if only space is passed in*/

	user_command = malloc(sizeof(char *) * (size + 2));
	if (user_command == NULL)
		return (NULL);

	token = _strtok(input, " \n\t\r");

	/**
	 * The line above tokenizes the preceeding string if it sees
	 * either space, newline, tab, etc.
	 * this fixes the error we used to have in our output
	 */

	for (i = 0; token != NULL; i++)
	{
		user_command[i] = token;
		token = _strtok(NULL, " \n\t\r");
	}
	user_command[i] = NULL; /* NULL terminate the pointer to array pointer*/
	return (user_command);
}
