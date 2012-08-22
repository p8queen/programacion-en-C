#include <stdio.h>
#include <pthread.h>
#include <unistd.h>
#include <stdlib.h>


void* mif(void *arg){
	printf("chau\n");
	return NULL;
}

int main(int argc, char const *argv[])
{
	pthread_t id;
	pthread_attr_t attr;
	if (pthread_attr_init(&attr) != 0)
	{
		perror("error init");
		exit(1);
	}
	if(pthread_create(&id, &attr,mif,NULL) != 0){
		perror("ERROR create");
	}
	printf("hola\n");

	pthread_join(id,NULL);//sleep(2);
	return 0;
}
