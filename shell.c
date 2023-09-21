#include "main.h"
#define MAX_ARGS 256
#include <signal.h>

void handle_signal(int signum);
void handle_EOF(int input_lenght, char *input);
/**
 * main - function to create a simple shell
 * @argc: arg count
 * @argv: arg vector
 * Return: always 0;
 */
int main(int argc, char *argv[])
{
	(void) argc;
	signal(SIGINT, handle_signal);

	handle_user_input(argv[0]);
	return (0);
}
/**
 * execute_command - Execute a command with its arguments in a child process.
 * @args: An array of strings representing the command and its arguments.
 * @str: name of the comman to start shell
 */
void execute_command(char *str, char *args[])
{
	int status, flag = 0;
	struct stat check;
	char *file_path;

	if (stat(args[0], &check) == 0)
		flag = 1;
	file_path = find_path(args[0]);
	if (file_path != NULL)
	{
		pid_t child_pid = fork();

		if (child_pid < 0)
		{
			perror("fork");
			if (!flag)
				free(file_path);
			exit(EXIT_FAILURE);
		}
		else if (child_pid == 0)
		{
			if (execve(file_path, args, environ) == -1)
			{
				perror(args[0]);
				if (!flag)
					free(file_path);
				exit(EXIT_FAILURE);
			}
		}
		else
		{
			wait(&status);
			if (!flag)
				free(file_path);
		}
	}
	else
	{
		perror(str);
	}
}

/**
 * handle_signal - function to intercept ^C signal
 * @signum: the signal integer
 */
void handle_signal(int signum)
{
	char *new_prompt = "\n$ ";

	(void)signum;
	signal(SIGINT, handle_signal);
	write(STDIN_FILENO, new_prompt, 3);
}

/**
 * handle_EOF - function to handle end of file
 * @input_length: length of the input
 * @input: pointer that we want to clear
 */
void handle_EOF(int input_length, char *input)
{
	int is_interactive = isatty(STDIN_FILENO);

	if (input_length == EOF)
	{
		if (is_interactive)
		{
			printf("exiting...\n");
			if (_strlen(input))
				free(input);
		}
		exit(EXIT_SUCCESS);
	}
}

/**
 * handle_user_input - Handle user input and the main shell logic.
 * @str: name of the command used to start shell
 */
void handle_user_input(char *str)
{
	char *token, *input = NULL;
	size_t input_size = 0;
	int input_length, arg_count, is_interactive = isatty(STDIN_FILENO);

	while (1)
	{
		char *args[MAX_ARGS]; /* Create an array for command and its arguments */

		if (is_interactive)
			write(0, "$ ", 2);
		input_length = getline(&input, &input_size, stdin);
		handle_EOF(input_length, input);
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
		if (_strcmp(args[0], "exit") == 0 && (args[1] != NULL))
		{
			free(input);
			exit(atoi(args[1])); /* Exit the shell if "exit" is entered */
		} else if (_strcmp(args[0], "exit") == 0)
		{
			free(input);
			exit(EXIT_SUCCESS);
		}
		execute_command(str, args);
	}
	free(input);
}
