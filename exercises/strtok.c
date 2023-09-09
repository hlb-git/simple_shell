#include <string.h>
#include <stdio.h>

/**
 * main - main function
 * Return: returns 0 on success
 */

int main(void)
{
	char ptr[] = "this is a test";
	char delim[] = " ";
	char *tok;

	tok = strtok(ptr, delim);

	while (tok)
	{
		printf("%s\n", tok);
		tok = strtok(NULL, delim);
	}
	return (0);
}
