#include <stdio.h>
#include <signal.h>
#include <unistd.h>


int main(int argc, char **argv)
{
	printf("[%d]\n",getpid());
	signal(SIGUSR1, SIG_IGN);
	pause();
	printf("hola \n");
	return 0;
}

