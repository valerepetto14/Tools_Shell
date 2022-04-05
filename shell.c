#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/wait.h>
/**
 *main - leer una linea y printearla
 *Return: num
 */
int ContTokens(char * cadena1)
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

/**
 *main - simple shell
 *Return: Always 0
 **/
int main(void)
{
	pid_t hijo;
	ssize_t bytes_leidos;
	size_t numero_bytes = 0;
	int iter = 0, tokens = 0;
	char *copycadena;
	char *cadena = NULL;
	char *token;
	char **argv;

	while (1)
	{
		iter = 0;
		bytes_leidos = getline(&cadena, &numero_bytes, stdin);
		if (bytes_leidos == -1 || cadena[0] == '\n')
		{
			continue;
		}
		else
		{
			if(cadena[0] == 'E'&& cadena[1] == 'x' && cadena[2] == 'i' && cadena[3] == 't')
			{
				break;
			}
			copycadena = strdup(cadena);
			cadena = strtok(cadena, "\n");
			tokens = ContTokens(copycadena);
			argv = calloc(tokens + 1, sizeof(char*));
			token = strtok(cadena, " ");
			while (token != NULL && iter < tokens) //LLENO EL ARRAY
			{
				argv[iter] = token;
				iter++;
				token = strtok(NULL, " ");
			}
			argv[tokens] = NULL;

			hijo = fork();
			if (hijo == 0) //DENTRO DEL HIJO
			{
				if (execve(argv[0], argv, NULL) == -1) //TRATAMOS DE EJECUTA EL COMANDO
				{
					free(cadena);
					free(copycadena);
					free(argv);
					perror(" ERROR");
					return (0);
				}
			}
			else //ESTOY EN EL PADRE
			{
				wait(NULL);
			}
			free(cadena);
		}
		bytes_leidos = 0;
		cadena = NULL;
		free(argv);
		free(copycadena);
	}
	free(cadena);
	return (0);
}
