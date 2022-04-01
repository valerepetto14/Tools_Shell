#include <stdio.h>
#include <stdlib.h>
#define TAM_MAXIMO 10
/**
 * main - leer una linea y printearla
 * Return: num
 **/
int main(void)
{
	ssize_t bytes_leidos;
	size_t numero_bytes;
	//ssize_t y size_t son sinónimos de unsigned int
	char *cadena;
	/* Puedes pasar a getline los argumentos inicializados: */
	//numero_bytes = TAM_MAXIMO;
	//cadena = (char *) malloc (numero_bytes + 1);
	//bytes_leidos = getline(&cadena, &numero_bytes, stdin);
	//
	// O bien, más sencillo, poner el número a 0 y la cadena a NULL, para que
	//él mismo te haga
	//la reserva necesaria **/
	printf("$ ");
	numero_bytes = 0;
	cadena = NULL;
	bytes_leidos = getline(&cadena, &numero_bytes, stdin);

	if (bytes_leidos == -1)
	{
		printf("Error.\n");
	}
	else
	{
		printf("%s", cadena);
	}
	free(cadena);

	return (0);
}
