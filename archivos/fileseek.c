#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <errno.h>
#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>  //exit_success, etc
#include <string.h>

int main(){
	int fd = open("entrada.txt",O_RDONLY,0777);
	if(fd==-1){
		perror("no se puede abrir archivo o no existe \n");
		return EXIT_FAILURE;
	}	
	int pos = lseek(fd,0,SEEK_CUR); //devuelve cantidad de bytes desde el inicio
	char basura[100];
	printf("estoy en la posic: %d\n",pos);
	read(fd,basura,2);
	pos = lseek(fd,0,SEEK_SET);  //seek_set 0 va al inicio, seek_end al final
	printf("despues de read, estoy enla pos: %d\n",pos);
	close(fd);
	return EXIT_SUCCESS;
}
