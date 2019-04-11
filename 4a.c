#include<stdio.h>
#include<sys/time.h>
#include<sys/resource.h>
#include<unistd.h>

int main()
{
	int prio, i;
	prio=getpriority(PRIO_PROCESS, 0);
	printf("The priority of the current process is %d \n",prio);
	for(i= -20 ; i<20; i=i+4 )
	{
		prio=getpriority(PRIO_PROCESS, 0);
		if(setpriority(PRIO_PROCESS,0,i)==-1)
			perror("setpriority");
		else{
			
			printf("%d : old priority %d: new priority\n",prio, i);
		}
	}
	return 0;
}
