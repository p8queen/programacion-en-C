#include <stdio.h>
#include <signal.h>
#include <unistd.h>

int i;
int flagALRM = 1;
void mif(int signum){
	
	printf("recibi por medio de [%d]\n", signum);	
	i++;
	
}

void salidaALRM(int signum){
	flagALRM = 0;

	
}

int main(int argc, char *argv[])
{
	//kill(2284,SIGKILL);	
	//mientras sleep ejecuta mi funcion
	//si me mandan una señal a mi, hago mif
	i=0;
	signal(SIGUSR1, mif);
	signal(SIGALRM, salidaALRM);
	printf("mi pid [%d]\n",getpid());
	alarm(10);
	while (flagALRM)
	{
		pause();
	}
	
	 //espera 10 segundos, esperando una señal
	
		
	printf("cantidad de recepcion de señales: [%d]\n",i);
	return 0;
}

