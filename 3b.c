#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<fcntl.h>
#include<sys/resource.h>

int main()
{
	FILE *fd;
	int p=fork();
	if(p<0)
	{
		perror("fork");
		return 0;
	}
	if (p>0)
		exit(EXIT_SUCCESS);
	umask(0);
	if(chdir("/")<0)
		exit(EXIT_FAILURE);
	close(STDIN_FILENO);
	close(STDOUT_FILENO);
	close(STDERR_FILENO);
	fd=fopen("/home/path/1RV/usp/hello.txt","w");
	while(1)
	{
		fprintf(fd,"Running\n");
		fflush(fd);
		sleep(3);
	}
	exit(EXIT_SUCCESS);
return 0;
}
