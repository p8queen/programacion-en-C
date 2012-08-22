#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>
#include <fcntl.h>


int main(int argc, char *argv[])
{
	mkfifo("/tmp/fifo1",0777);	
	
	char letra = 'a';

	char leerLetra;
	int pid = fork();
	if (pid>0){
		int fd = open("/tmp/fifo1",O_WRONLY);
		while(letra <='z'){
			write(fd,&letra,1);
			letra++;
			//sleep(1);
			}
		close(fd);
	}else{
		int fdr = open("/tmp/fifo1",O_RDONLY);
		while (read(fdr,&leerLetra,1) > 0)
			printf("%c\n",leerLetra );
		close(fdr);
	}
	
	
	
	return 0;
}