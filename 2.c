#include<stdio.h>
#include<sys/stat.h>
#include<sys/types.h>

int main(int argc, char **argv)
{
	int i;
	struct stat filename;
	if(argc == 1)
	{
		printf("\nGive File name\n");
		return 0;
	}
	for(i=1;i<argc;i++)
	{
		printf("%20s",argv[i]);
		lstat(argv[i],&filename);
		
		if(S_ISREG(filename.st_mode))
			printf("\tRegular file\n");
			
		else if(S_ISDIR(filename.st_mode))
			printf("\tDirectory file\n");
			
		else if(S_ISBLK(filename.st_mode))
			printf("\tBlock file\n");
			
		else if(S_ISCHR(filename.st_mode))
			printf("\tCharacter file\n");
			
		else if(S_ISLNK(filename.st_mode))
			printf("\tLink file\n");
	}
	
	return 0;
}
