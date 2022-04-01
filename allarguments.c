#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
/**
 * main - mian
 * @ac: int
 * @av: array of string
 * Return: int
 **/
int main(__attribute__((unused)) int ac, char **av)
{
	while (*(av) != NULL)
	{
		printf("%s\n",*(av));
		av++;
	}	
}
