#include <sys/types.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>

int main(int argc, char const *argv[])
{
	/* se crean n hijos recibidos por parametro */
	printf("Padre [pid]%d\n", getpid());
	pid_t pid;
	int i, x;
	if (argc<2){ perror("se espara a.out n-hijos"); exit(1);}
	x=atoi(argv[1]);
	for ( i = 0; i < x; ++i)
	{
		pid = fork();
		if(pid==0){
			printf("getppid: %d\n", getppid());
			exit(0); //termina el proceso
			// o i=x+1
		}

	}
	sleep(2);

	return 0;
}