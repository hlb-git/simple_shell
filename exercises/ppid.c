#include <stdio.h>
#include <unistd.h>

/**
 * main - the entry point of the program
 * Return: returns the ppid of the parent process
 */

int main(void)
{
	pid_t my_ppid;

	my_ppid = getppid();

	printf("%u\n", my_ppid);
	return (0);
}
