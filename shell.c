#include <stdio.h>
#include <stdlib.h>
/**
 * main - leer una linea y printearla
 * Return: num
 **/
int main(void)
{
	ssize_t bytes_leidos;
	size_t numero_bytes;
	char *cadena;

	printf("$");
	numero_bytes = 0;
	cadena = NULL;
	bytes_leidos = getline(&cadena, &numero_bytes, stdin);

	if (bytes_leidos == -1)
	{
		printf("Error.\n");
	}
	else
	{
		execve(cadena[])
	}
	free(cadena);

	return (0);
}
