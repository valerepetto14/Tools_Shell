#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <signal.h>
#include <sys/wait.h>
#define BLANCO_T   "\x1b[37m"
#define VERDE_T        "\x1b[32m"

/**
 *ContTokens - leer una linea y printearla
 *@cadena1: cadena
 *Return: num
 */
int ContTokens(char *cadena1)
{
	int cont = 0;
	char *token1;

	token1 = strtok(cadena1, " ");
	while (token1 != NULL)
	{
		token1 = strtok(NULL, " ");
		cont++;
	}
	return (cont);
}
/**
 *main - simple shell
 *Return: Always 0
 **/
void cargar(char *copycadena, char *cadena)
{
	char *copycadena = NULL;
	char *token = NULL;
	ZZZZ
}

int main(int argc, char *argv[], char **env)
{
	pid_t hijo;
	ssize_t bytes_leidos;
	size_t numero_bytes = 0;
	int iter = 0, tokens = 0;
	char *copycadena, *token, **argv, *cadena = NULL;

	while (1)
	{
		iter = 0;
		printf(VERDE_T "$cisfun " BLANCO_T);
		bytes_leidos = getline(&cadena, &numero_bytes, stdin);
		if (cadena[0] == '\n')
		{
			free(cadena);
			cadena = NULL;
			continue;
		}
		else if (bytes_leidos == -1 || cadena[0] == EOF)
		{
			break;
		}
		else
		{
			copycadena = strdup(cadena);
			cadena = strtok(cadena, "\n");
			tokens = ContTokens(copycadena);
			argv = calloc(tokens + 1, sizeof(char *));
			token = strtok(cadena, " ");

			while (token != NULL && iter < tokens) /*Lleno el array*/
			{
				argv[iter] = token;
				iter++;
				token = strtok(NULL, " ");
			}
			argv[tokens] = NULL;

			hijo = fork();

			if (hijo == 0) /*Dentro del hijo*/
			{
				if (execve(argv[0], argv, NULL) == -1) /*Tratamos de ejecutar el comando*/
				{
					free(cadena);
					free(argv);
					free(copycadena);
					perror(" ERROR");
					return (0);
				}
			}
			else /*Estoy en el padre*/
			{
				wait(NULL);
			}
			free(cadena);
		}
		free(copycadena);
		free(argv);
		bytes_leidos = 0;
		cadena = NULL;
	}
	free(cadena);
	return (0);
}
