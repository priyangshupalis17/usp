#include<stdio.h>
#include<sys/time.h>
#include<sys/resource.h>
#include<sys/types.h>
#include<unistd.h>
int main(int argc,char **argv)
{
	int which=PRIO_PROCESS;
	int id;
	int prio,set;
	id = getpid();
	printf("Previous Requested Assigned\n");
	for(int i=-20;i<20;i+=2)
	{                            
		prio=getpriority(which,id);
		printf("%5d ",prio);

		printf("   %d",i);
		setpriority(which,id,i);
		prio=getpriority(which,id);
		printf("     %d \n",prio);
	}
	return 0;
}
	
