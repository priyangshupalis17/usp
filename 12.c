#include<stdio.h>
#include<stdlib.h>

int testf(int finish[],int j)
{
	int i;
	for(i=0;i<j;i++)
		if(finish[i]==0)
			return 0;
	return 1;
}
	
int main()
{
	int alloc[20][20],max[20][20],avail[20],need[20][20];
	int work[20],finish[20],p,r,res[20],num,order[20],k=0,i,j;

	printf("Enter no of process\n");
	scanf("%d",&p);
	printf("Enter no of resources\n");
	scanf("%d",&r);

	printf("Enter alloc matrix\n");
	for(i=0;i<p;i++)
		for(j=0;j<r;j++)
			scanf("%d",&alloc[i][j]);

	printf("Enter max matrix\n");
	for(i=0;i<p;i++)
		for(j=0;j<r;j++)
			scanf("%d",&max[i][j]);

	printf("Enter avail matrix\n");
	for(j=0;j<r;j++)
	{	scanf("%d",&avail[j]);
		work[j]=avail[j];
	}

	printf("Enter max instances\n");
	for(i=0;i<r;i++)
		scanf("%d",&res[i]);

	printf("Need matrix is\n");
	for(i=0;i<p;i++)
	{	for(j=0;j<r;j++)
		{
			need[i][j]=max[i][j]-alloc[i][j];
			printf("%d  ",need[i][j]);
		}
		printf("\n");
	}

	for(i=0;i<p;i++)
		finish[i]=0;

	int valid=1;
	while(valid)
	{
		for(i=0;i<p;i++)
		{	num=0;
			if(finish[i]==0)
			{
				for(j=0;j<r;j++)
				{
					if(need[i][j]<=work[j])
						num++;
				}
	
				if(num==r)
				{
					for(j=0;j<r;j++)
					{	
						work[j]+=alloc[i][j];
					}
					finish[i]=1;
					order[k++]=i;
				}
			}
			for(j=0;j<r;j++)
				if(work[j]>res[j])		//res = max instances
					valid=0;

			if(!valid || testf(finish,p))
				break;
		}
		if(!valid || testf(finish,p))
			break;

	}
		
	if(testf(finish,p))
	{
		printf("Safe state\nSafe sequenceis :\n");
		for(i=0;i<k;i++)
			printf("P%d  ",order[i]);
		printf("\n");
	}
	else
		printf("Safe sequence doesnot exist\n");	
	
	return 0;
}
