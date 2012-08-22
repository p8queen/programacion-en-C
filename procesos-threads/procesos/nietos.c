#include <sys/types.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>

int main(int argc, char const *argv[])
{
	/* code */
	if(argc != 2){
		printf("Se espera un argumento: programa 4\n");
		return 1;
		}
	printf("Padre [pid]%d\n", getpid());
	pid_t pid;
	int i, n;
	n=atoi(argv[1]);
	for ( i = 0; i < n; ++i)
	{
		pid = fork();
		if(pid>0){
			wait(); //libera memoria
			exit(0); //mata padre
		}
		printf("proceso hijo: %d, padre: %d\n", getpid(), getppid());
	}
	sleep(2);

	return 0;
}