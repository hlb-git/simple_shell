#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>

/**
 * main - simple shell
 * Return: 0 or error code
 */

int main(void)
{
	char *token, *input = NULL;
	size_t input_size = 0;
	int status, arg_count;
	pid_t child_pid;

	while (1)
	{
		int input_length;
		char *args[256];/* Create an array for command and its arguments */
		printf("#Lov&Ngo_shell$ ");
		input_length = getline(&input, &input_size, stdin);
		if (input_length == -1)
		{
			perror("getline");
			break;/* Exit on error or EOF*/
		}
		if (input_length > 0 && input[input_length - 1] == '\n')
			input[input_length - 1] = '\0';/* Remove trailing newline character */
		token = strtok(input, " ");/* Tokenize the input */
		if (token == NULL)
			continue;/* Empty line, prompt again */
		arg_count = 0;
		while (token != NULL)
		{
			args[arg_count++] = token;
			token = strtok(NULL, " ");
		}
		args[arg_count] = NULL;/* Null-terminate the argument array */
		child_pid = fork();/* create a child process */
		if (child_pid < 0)
		{
			perror("fork");
			exit(EXIT_FAILURE);
		} else if (child_pid == 0)
		{
			if (execve(args[0], args, NULL) == -1)
			{
				perror("execve");
				exit(EXIT_FAILURE);
			}
		} else
		{
			wait(&status);
		}
	}
	free(input); /* Free allocated memory */
	return (0);
}
