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

	pid = fork();
	if (pid == 0)
	{
		printf("Soy el hijo 1, Mi padre es= %d, Mi PID= %d\n", getppid(), getpid());
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
