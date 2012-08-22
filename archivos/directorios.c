#include <stdio.h>
#include <dirent.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>

//recorre directorio y detecta directorios
int main(int argc, char *argv[])
{
	DIR* dirinfo = opendir("..");
	struct dirent* data;
	struct stat stData;
	data=readdir(dirinfo);
	while (data!=NULL)
	{
		printf("name: %s, type: %d ",data->d_name,data->d_type);
		int res=stat(data->d_name,&stData);
		printf("modo:  [%d], ",stData.st_mode);
		if ((stData.st_mode & S_IFMT) == S_IFDIR)
			printf("%s: es un directorio \n",data->d_name);
		else	
			printf("%s: NO es un directorio \n",data->d_name);
		data=readdir(dirinfo);	
	}
	closedir(dirinfo);  
	return 0;
}

