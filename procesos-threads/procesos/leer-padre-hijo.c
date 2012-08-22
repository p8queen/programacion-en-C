#include <sys/types.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/stat.h>
#include <unistd.h>
#include <fcntl.h>

int main(int argc, char const *argv[])
{
	struct stat st;
	stat("texto.txt",&st);
	int size = st.st_size;
	int fd = open("texto.txt",O_RDONLY);
	pid_t pid = fork();
	if(pid==0){
		//hijo
		lseek(fd,size/2,SEEK_SET);

	}else{
		//padre
		lseek(fd,0,SEEK_SET);
	}
	
	int res=0;
	char letra;
	int count = 0;
	while(size--){
		res = read(fd,&letra,1);
		if(res==-1){
			perror("no puede leer letra");
			exit(1);
		}else if(res == 0){
			break;
		}else{
			if(letra=='a')
				count++;
		}
	}
	printf("count %d \n",count);


	close(fd);

	return 0;
}