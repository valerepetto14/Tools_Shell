#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/wait.h>
/**
 * main - leer una linea y printearla
 * Return: num
 **/
int main(void)
{
	pid_t hijo;
	ssize_t bytes_leidos;
	size_t numero_bytes = 0;
	int iter = 0;
	char *cadena = NULL;
	char *token;
	char *argv[4] = {NULL, NULL, NULL, NULL};

	while (1)
	{
		iter = 0;
		printf("#cisfun$ ");
		bytes_leidos = getline(&cadena, &numero_bytes, stdin);
		if (bytes_leidos == -1)
		{
			continue;
		}
		else if (cadena[0] == '\n')
		{
			argv[0] = NULL, argv[1] = NULL,argv[2] = NULL, argv[3] = NULL;
			wait(NULL);
			continue;
		}
		else
		{
			cadena = strtok(cadena, "\n");
			token = strtok(cadena, " ");
			while (token != NULL && iter < 3) //LLENO EL ARRAY
			{
				argv[iter] = token;
				iter++;
				token = strtok(NULL, " ");
			}

			hijo = fork();
			if (hijo == 0) //DENTRO DEL HIJO
			{
				if (execve(argv[0], argv, NULL) == -1) //TRATAMOS DE EJECUTA EL COMANDO
				{
					perror(" ERROR");
				}
			}
			else //ESTOY EN EL PADRE
			{
				argv[0] = NULL, argv[1] = NULL,argv[2] = NULL, argv[3] = NULL;
				wait(NULL);
				continue;
			}
		}
		free(cadena);
		bytes_leidos = 0;
		cadena = NULL;
		argv[0] = NULL, argv[1] = NULL,argv[2] = NULL, argv[3] = NULL;
	}
	free(cadena);
	return (0);
}
