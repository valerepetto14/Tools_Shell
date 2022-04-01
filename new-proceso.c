#include <stdio.h>
#include <sys/types.h>
#include <unistd.h>
int main (void)
{
	int i;
	int padre;
	padre = 1;
	fprintf(stdout, "´Este es el proceso padre con ID %ld\n", (long)getppid());
	for (i=0; i < 3; i++)
	{
		if (padre == 1)
		{
			if (fork() == 0) /* Proceso hijo */
			{
				fprintf(stdout, "´Este es el proceso hijo con id %ld\n",(long)getpid());
				printf("%d\n",padre);
				padre = 0;
			}
		}
	}
	return 0;
}

