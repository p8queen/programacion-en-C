#include <stdio.h>
#include <signal.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>

int i;
void mif(int signum){
	
	printf("recibi la señal chau\n");	
	
	
}

int main(int argc, char *argv[])
{
	signal(SIGUSR1, mif);
	printf("mi pid [%d]\n",getpid());
	int fd = open("proceso-pid.txt",O_CREAT|O_WRONLY,0777);
	if(fd<0){
		perror("no pude crear archivo\n");
		return 1;
		}
	pid_t h = getpid();
	write(fd,&h,sizeof(pid_t));
	close(fd);
	pause(); 
	return 0;
}

