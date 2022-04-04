#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/wait.h>
/**
 * main - leer una linea y printearla
 * Return: num
 **/
int ContSpaces(char * cadena1)
{
	int cont = 0;
	char * token1;
	token1 = strtok(cadena1, " ");
	while (token1 != NULL)
	{
		token1 = strtok(NULL, " ");
		cont++;
	}
	return (cont);
}

int main(void)
{
	pid_t hijo;
	ssize_t bytes_leidos;
	size_t numero_bytes = 0;
	int iter = 0, spaces = 0;
	char *copycadena;
	char *cadena = NULL;
	char *token;
	char **argv;

	while (1)
	{
		iter = 0;
		printf("#cisfun$ ");
		bytes_leidos = getline(&cadena, &numero_bytes, stdin);
		if (bytes_leidos == -1 || cadena[0] == '\n')
		{
			free(cadena);
			free(copycadena);
			continue;
		}
		else
		{
			copycadena = strdup(cadena);
			cadena = strtok(cadena, "\n");
			spaces = ContSpaces(copycadena);
			argv = malloc(sizeof(char *) * spaces);
			token = strtok(cadena, " ");
			while (token != NULL && iter <= spaces) //LLENO EL ARRAY
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
					free(argv);
					free(cadena);
				}
			}
			else //ESTOY EN EL PADRE
			{
				wait(NULL);
				free(copycadena);
				free(cadena);
				free(argv);
				continue;
			}
		}
		free(cadena);
		free(argv);
		free(copycadena);
		bytes_leidos = 0;
		cadena = NULL;
	}
	free(argv);
	free(cadena);
	return (0);
}


