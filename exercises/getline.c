#include <stdio.h>
#include <stdlib.h>

/**
 * main - main function
 * Return: 0 on success
 */

int main(void)
{
	size_t n = 10;
	char *ptr = malloc(sizeof(char) * n);

	printf("$");
	getline(&ptr, &n, stdin);
	printf("%s", ptr);
	return 0;
}

