#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/wait.h>

/**
 * main - the main function
 * Return: returns 0 on success
 */

int main(void)
{
	pid_t child_pid;
	int status, i = 5;
	char *argv[] = {"/bin/ls", "-l", "/tmp", NULL};

	while (i)
	{
		child_pid = fork();

		if (child_pid == -1)
		{
			perror("fork");
			exit(-1);
		}
		else if(child_pid == 0)
		{
			if (execve(argv[0], argv, NULL) == -1)
			{
				perror("execve");
				exit(-1);
			}
		}
		else
		{
			wait(&status);
			i--;
		}
	}
	return (0);
}
