#include "main.h"
#define MAX_ARGS 256

/**
 * main - function to create a simple shell
 * Return: always 0;
 */
int main(void)
{
	handle_user_input();
	return (0);
}
/**
 * execute_command - Execute a command with its arguments in a child process.
 * @args: An array of strings representing the command and its arguments.
 */
void execute_command(char *args[])
{
	int status;
	char *file_path;

	file_path = find_path(args[0]);
	if (file_path != NULL)
	{
		pid_t child_pid = fork();

		if (child_pid < 0)
		{
			perror("fork");
			exit(EXIT_FAILURE);
		}
		else if (child_pid == 0)
		{
			if (execve(file_path, args, environ) == -1)
			{
				perror("execve");
				exit(EXIT_FAILURE);
			}
		}
		else
		{
			wait(&status);
			free(file_path);
		}
	}
	else
	{
		write(1, ":( command does not exist\n", 27);
	}
}

/**
 * handle_user_input - Handle user input and the main shell logic.
 */
void handle_user_input(void)
{
	char *token, *input = NULL;
	size_t input_size = 0;
	int input_length, arg_count;

	while (1)
	{
		char *args[MAX_ARGS]; /* Create an array for command and its arguments */

		printf("#cisfun$ ");
		input_length = getline(&input, &input_size, stdin);

		if (input_length == -1)
		{
			perror("getline");
			break; /* Exit on error or EOF */
		}

		if (input_length > 0 && input[input_length - 1] == '\n')
			input[input_length - 1] = '\0'; /* Remove trailing newline character */

		token = strtok(input, " "); /* Tokenize the input */

		if (token == NULL)
			continue; /* Empty line, prompt again */

		arg_count = 0;
		while (token != NULL)
		{
			args[arg_count++] = token;
			token = strtok(NULL, " ");
		}
		args[arg_count] = NULL; /* Null-terminate the argument array */

		if (_strcmp(args[0], "exit") == 0)
		{
			exit(EXIT_SUCCESS); /* Exit the shell if "exit" is entered */
		}
		execute_command(args);
	}
	free(input); /* Free allocated memory */
}
