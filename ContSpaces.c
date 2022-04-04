#include <stdio.h>
#include <string.h>
#include <sys/wait.h>
#include <stdlib.h>


int main(char *cadena)
{ 
    char cadena[];
    int cont = 0;
    char *token1;
    token1 = strtok(cadena, " ");
          while (token1 != NULL)
          {
                  token1 = strtok(NULL, " ");
 		  cont++;
          }
    printf("%i\n", cont);
    return 0;
}
