#include "main.h"

/**
 * getline_cmd - this is where the user input is captured
 * Return: returns a pointer to the string from the gertline function
 */

char *getline_cmd(void)
{
	char *input = NULL;
	size_t len_string = 0;

	if (isatty(STDIN_FILENO)) /* this checks if its used in interactive mode*/
		write(STDOUT_FILENO, "$ ", 2); /* the prompt that displays*/

	if (getline(&input, &len_string, stdin) == -1)
	{
		free(input); /*frees up that space to avoid the mem leakage problem*/
		return (NULL);
	}
	return (input);
}
