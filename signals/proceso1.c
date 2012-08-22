#include <stdio.h>
#include <signal.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>

int main(int argc, char *argv[])
{
	//int pid=atoi(argv[1]);
	//printf("%d\n",pid);
	int fd = open("proceso-pid.txt",O_RDONLY);
	if (fd<0){
		perror("no puedo leer archivo\n");
		return 1;
	}
	pid_t pid;
	read(fd,&pid,sizeof(pid_t));
	close(fd);
	kill(pid,SIGUSR1);	
	return 0;
}

