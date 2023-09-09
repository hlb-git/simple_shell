#include <stdio.h>

/**
 * main - prints arguements
 * @ac: number of arguements
 * @av: NULL terminated array containing all the args
 * Return: returns 0 on success
 */

int main(int ac __attribute__((unused)), char **av)
{
	while (*av)
	{
		printf("%s\n", *av);
		av++;
	}
	return (0);
}
