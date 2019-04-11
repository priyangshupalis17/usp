#include<stdio.h>
#include<stdlib.h>
#include<signal.h>

void signalhan(int sig)
{
	printf("Caught signal Floating point error : %d\n",sig);
	exit(0);
}

int main()
{
	int a,b;
	signal(SIGFPE,signalhan);
	printf("Enter two numbers numbers :");
	scanf("%d%d",&a,&b);
	printf("The Quotient is %d\n",a/b);
}
