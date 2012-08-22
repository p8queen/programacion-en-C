#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <errno.h>
#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>  //exit_success, etc
#include <string.h>

int main(){
	int iError = open("entrada.txt",O_RDONLY,0777);
	if (iError == -1){
		perror("error");
		return EXIT_FAILURE;
	}
	char texto[256];
	int leido;
	leido = read(iError,texto,255);
	texto[leido] = '\0';
	printf("%s \n", texto);
	printf("devuelve iError: %d y leido: %d \n",iError,leido);
	close(iError);
	
	//write
	int fd = open("escribir.txt",O_CREAT|O_WRONLY,0777);
	char *wtexto = "blah bla mucho texto \n";
	int escribir;
	escribir = write(fd,wtexto,strlen(wtexto));
	if (escribir<0){
		perror("");
		return EXIT_FAILURE;
	}
	
	return EXIT_SUCCESS;
}


