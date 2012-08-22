#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>
#include <fcntl.h>


int main(int argc, char *argv[])
{
	int fds[2];
	pipe(fds);
	if(fork()){
		char letra='a';
		while(letra <= 'z'){
			close(fds[0]);
			write(fds[1],&letra,1);	
			letra++;
			}
		
		
	}else{
		char letraLeida;
		close(fds[1]);
		while(read(fds[0],&letraLeida,1)>0)
			printf("%c\n",letraLeida );
		}
	
	return 0;
}