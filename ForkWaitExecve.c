#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>
#include <sys/wait.h>
/**
 * main - ver proceso padre e hijo
 *Return: int
 **/
int main(void)
{
	pid_t pid;
	int iter = 0;
while (iter < 5)
{
	pid = fork();
	int iter = 0;
	if (pid == 0)
	{
		
		return (0);
	}
	else if (pid < 0)
	{
		perror("anda mal");
		return (-1);
	}
	else
	{
		wait(NULL);
		return (1);
	}
	printf("Proceso PADRE = %d\n", getpid());
	return (0);
}
}
