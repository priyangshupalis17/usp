#include<stdio.h>
#include<unistd.h>
#include<fcntl.h>
#include<sys/stat.h>
#include<sys/types.h>

int main(int argc, char* argv[])
{
	struct stat statv;
	int i;
	for(i=1;i<argc;i++){
		lstat(argv[i],&statv);
		if (S_ISDIR(statv.st_mode))
			printf("%s is a directory\n", argv[i]);
		else if (S_ISREG(statv.st_mode))
			printf("%s is a rergular file\n", argv[i]);
		else if (S_ISBLK(statv.st_mode))
			printf("%s is a block device file\n", argv[i]);
		else if (S_ISCHR(statv.st_mode))
			printf("%s is a character device file\n", argv[i]);
		else if (S_ISLNK(statv.st_mode))
			printf("%s is a link file\n", argv[i]);
		else if (S_ISFIFO(statv.st_mode))
			printf("%s is a fifo file\n", argv[i]);
		else printf("nothing matched\n");
	}
	return 0;	
}

