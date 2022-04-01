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
	char *argv[] = {"/bin/ls", "-l", "./", NULL};

	while (iter < 5)
	{
		pid = fork();

		if (pid == 0)
		{
			printf("Before execve\n");
			if (execve(argv[0], argv, NULL) == -1)
			{
				perror("Error:");
				return (1);
			}
			printf("After execve\n");
		}
		else if (pid < 0)
		{
			perror("anda mal");
			return (-1);
		}
		else
		{
			wait(NULL);
		}
		printf("Proceso PADRE = %d\n", getpid());
		iter++;
	}
	return (0);
}
