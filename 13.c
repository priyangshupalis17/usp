#include<stdio.h>
int buf[100],n,m;
int str[100];

int opt_pos(int pos)
{
	int i,j,count=0,access[m];
	for(i=0;i<m;i++)
	{
		access[i]=99;
	}
	for(i=0;i<m;i++)
	{
		for(j=pos+1;j<n;j++)
		{
			if(buf[i]==str[j])
			{
				access[i]=j;
				break;
			}
		}
	}
	int max;
	max=access[0];
	int max_pos=0;
	for(i=0;i<m;i++){
		if(access[i]>max)
		{
			max=access[i];
			max_pos=i;
		}
	}
	return max_pos;
}

int isfound(int a)
{
	int i;
	for(i=0;i<m;i++)
	{
		if (buf[i]==a)
			return 1;
	}
	return 0;
}

void printbuf()
{
	int i;
	for(i=0;i<m;i++)
		printf("%d | ",buf[i]);
	printf("\n");
	
}

void opt()
{
	int fault=0,i,pos;
	for(i=0;i<m;i++)
	{
		buf[i]=str[i];
		printf("page reference : %d\n",str[i]);
		printbuf();
		fault++;
	}
	for(i=m;i<n;i++)
	{
		if(isfound(str[i])==0)
		{
			pos=opt_pos(i);
			buf[pos]=str[i];
			fault++;
		}
		printf("page reference : %d\n",str[i]);
		printbuf();
	}
	printf("Number of page faults is %d\n",fault);
}

void fifo()
{
	int i,pos,pointer=-1,fault=0;
	for(i=0;i<n;i++)
	{
		if(isfound(str[i])==0)
		{
			pos=(++pointer)%m;
			buf[pos]=str[i];
			fault++;
		}
		printf("Page reference : %d\n",str[i]);
		printbuf();
	}
	printf("Number of page faults is %d\n",fault);
}

int main()
{
	int i;
	printf("Enter the number of characters to be added to the buffer\n");
	scanf("%d",&n);
	printf("Enter the characters\n");
	for(i=0;i<n;i++)
		scanf(" %d",&str[i]);
	printf("Enter the size of the buffer\n");
	scanf("%d",&m);
	printf("Fifo page replacement\n");
	for(i=0;i<m;i++)
		buf[i]=-1;
	fifo();
	printf("Optimal page replacement\n");
	for(i=0;i<m;i++)
		buf[i]=-1;
	opt();
	return 0;
}

