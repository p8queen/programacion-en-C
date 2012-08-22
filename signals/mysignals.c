#include <stdio.h>
#include <signal.h>
#include <unistd.h>

int i;
void mif(int signum){
	
	printf("recibi por medio de [%d]\n", signum);	
	i++;
	
}

int main(int argc, char *argv[])
{
	//kill(2284,SIGKILL);	
	//mientras sleep ejecuta mi funcion
	//si me mandan una señal a mi, hago mif
	i=0;
	signal(SIGUSR1, mif);
	printf("mi pid [%d]\n",getpid());
	//sleep(15); //15 segundos
	while (i<5)
		pause(); //bloquea el proceso, esperando una señal
	
		
	printf("cantidad de recepcion de señales: [%d]\n",i);
	return 0;
}

