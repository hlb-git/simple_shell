#include <stdio.h>
#include <stdlib.h>

extern char **environ;

/**
 * main - main function
 * Return: returns 0 on success
 */

int main(void)
{
	int i = 0;

	while (environ[i])
	{
		printf("%s\n", environ[i]);
		i++;
	}
	return (0);
}
