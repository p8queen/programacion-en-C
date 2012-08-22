#include <stdio.h>
#include <stdio.h>
#include <signal.h>
#include <unistd.h>

int i;
int flagALRM = 1;
/*void mif(int signum){
	
	printf("recibi por medio de [%d]\n", signum);	
	i++;
	
}*/

void salidaALRM(int signum){
	flagALRM = 0;
}

int main(int argc, char *argv[])
{
	//ESTE EJERCICIO GENERA UN PADRE Y n HIJOS CON EL MISMO PADRE
	//fd = create
    int cant = atoi(argv[1]);
    pid_t hijos[cant];
    pid_t pid;
    int i = 0;
	signal(SIGALRM, salidaALRM);

    for(i = 0; i<cant; i++){
        pid = fork();
        if (pid==0){
			hijos[i] = getpid();
			sleep(4);
			printf("soy hijo nro: [%d]\n",hijos[i] );
            /*signal(sigusr1,fhijo);
            while(1)
				pause()  //lo bloquea hasta que recibe señal. 
            */
            
            return 0;
                
        }else if(pid>0){
    
            
        }else{
            perror("ERROR\n");
            
        }
        
    }
	
	///
	
	
	
	//signal(SIGUSR1, mif);
	//matar hijos
	alarm(1);
	pause();
	for (i=0; i < cant; ++i){
		printf("hijo-id: %d\n", hijos[i]);
		kill(hijos[i], SIGKILL);
		wait();
	}
	return 0;
}

