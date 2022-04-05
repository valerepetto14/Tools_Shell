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
char *find_PATH(char **env)
{
	char *ruta = NULL;
	char *token;
	char *copy;
	const char *name = "PATH";
	int iter = 0;

	for (iter = 0; env[iter] != NULL; iter++)
	{
		copy = strdup(env[iter]);
		token = strtok(copy, "=");
	if (strcmp(token, name) == 0)
	{
		token = strtok(NULL, "=");
		ruta = token;
	}
}
	return (ruta);
}
char **cargar(char *cadena, char **array)
{
	int iter = 0;
	char *copycadena = NULL;
	int tokens = 0;
	char *token = NULL;

	copycadena = strdup(cadena);
	cadena = strtok(cadena, "\n");
	tokens = ContTokens(copycadena);
	array = calloc(tokens + 1, sizeof(char *));
	token = strtok(cadena, " ");

	while (token != NULL && iter < tokens) /*Lleno el array*/
	{
		array[iter] = token;
		iter++;
		token = strtok(NULL, " ");
	}
		array[tokens] = NULL;
		free(copycadena);
		return (array);
}
list_t cargar_lista(char *path)
{
	if(path = NULL)
		return (NULL);
	

}

int main(int argc, char *argv[], char **env)
{
	pid_t hijo;
	ssize_t bytes_leidos;
	size_t numero_bytes = 0;
	char **array = NULL, *cadena = NULL;

	while (1)
	{
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
			array = cargar(cadena, array);
			hijo = fork();

			if (hijo == 0) /*Dentro del hijo*/
			{
				if (execve(array[0], array, NULL) == -1) /*Tratamos de ejecutar el comando*/
				{
					free(cadena);
					free(array);
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
		free(array);
		bytes_leidos = 0;
		cadena = NULL;
	}
	free(cadena);
	return (0);
}
