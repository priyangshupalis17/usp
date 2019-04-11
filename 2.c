#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>


int main(int argc,char *argv[])
{
	struct stat statv;

	for(int i = 1;i < argc;i++)
	{
		lstat(argv[i] , &statv);
		
		if(S_ISREG(statv.st_mode))
			printf("Regular file");
		if(S_ISBLK(statv.st_mode))
			printf("Block Device file");
		if(S_ISCHR(statv.st_mode))
			printf("character file");
		if(S_ISFIFO(statv.st_mode))
			printf("Fifo file");
		if(S_ISDIR(statv.st_mode))
			printf("directory");
		if(S_ISLNK(statv.st_mode))
			printf("LINK");
	}
	return 0;
}

