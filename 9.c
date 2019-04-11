#include<stdio.h>
#include<stdlib.h>
#define VAL 0
#define SIZE 6
int mutex=1,full=0,empty=SIZE;
int x=VAL;

int wait(int s)
{
	return --s;
}

int signal(int s)
{
	return ++s;
}

void producer()
{
	empty=wait(empty);
	mutex=wait(mutex);
	x++;
	printf("Producer producing : %d\n",x);
	mutex=signal(mutex);
	full=signal(full);
}

void consumer()
{
	full=wait(full);
	mutex=wait(mutex);
	printf("Consumer consuming %d\n",x);
	x--;
	mutex=signal(mutex);
	empty=signal(empty);
}

int main()
{
	int num,c=0;

	
	while(1)
	{
		printf("\nEnter 1-Producer\n2-Consumer\n3-exit\n");
		scanf("%d",&num);
		switch(num)
		{
			case 1: if(mutex && empty>0)
				producer();
				else
					printf("full buffer\n");
				break;
			case 2: if(mutex && full>0)
				consumer();
				else
					printf("empty buffer\n");
				break;
			case 3:
			default: c=1; 
				exit(0);
		}
		if(c)
			break;
	}

	return 0;
}
	

