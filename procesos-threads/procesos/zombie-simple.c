#include <sys/types.h>
#include <unistd.h>
#include <stdio.h>

int main(int argc, char const *argv[])
{
	/* code */
	pid_t pid = fork();
	if(pid==0){
		return 0;
	}else{
		sleep(10);
		printf("Mi hijo está muerto\n");
		wait(); /*matamos al zombie, usar siempre 
				wait(null) si no deja compilar waitpid */
		
	}


	return 0;
}