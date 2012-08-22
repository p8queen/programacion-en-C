#include <sys/types.h>
#include <unistd.h>
#include <stdio.h>

int main(int argc, char const *argv[])
{
	/* code */
	pid_t pid = fork();
	switch(pid){
		case -1:
			perror("error fork");
			break;
		case 0:
			//hijo
			sleep(2);
			printf("hijo %d, getpid: %d, getppid: %d\n",pid,getpid(),getppid());
			break;
		default:
			//padre	
			printf("padre %d, getpid: %d, getppid: %d\n",pid,getpid(), getppid());
	}

	return 0;
}
