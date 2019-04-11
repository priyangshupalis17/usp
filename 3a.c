#include<stdio.h>
#include<unistd.h>
#include<sys/types.h>
#include<sys/wait.h>
#include<stdlib.h>

int main()
{
	int x,status;
	char str[30];
	x = fork();
	
	if(x < 0)
	{
		printf("Process cannot be created sucessfully");
	}
	
	else if( x==0)
	{
		 printf("In Child Process\n");
		 printf("My process ID : %d\n", getpid());
   		 printf("My parent's ID: %d\n\n", getppid());
   		 printf("Enter a command  : ");
   		 scanf("%s",str);
   		 system(str);
   		 exit(0);
   	}
   	
   	else
   	{
   		wait(&status);
   		printf("\nIn Parent Process\n"); 
    	printf("Parent pid = %d\n", getpid()); 
    	printf("Child pid = %d\n", x); 
    }
}
