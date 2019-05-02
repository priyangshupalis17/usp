#include<iostream>
#include<algorithm>
using namespace std;

int main()
{
	int n, a[10], head, seek = 0, break_pos=0;
	float avg_seek;
	cout<<"Enter the size of queue: ";
	cin>>n;
	cout<<"Enter the value of cylinders : ";
	for(int i=0;i<n;i++)
		cin>>a[i]; 
	
	cout<<"Enter the head pos:  ";
	cin>>head;

	sort(a, a+n);
	for(int i=0;i<n-1;i++)
	{
		if(head < a[0])
			break_pos = 0;
		if((a[i] < head) && (a[i+1] > head))
			break_pos = i;
		if(head > a[n-1])
			break_pos = n-1;
	}
	if(head<a[0])
	{
		cout<<"Move head from "<<head<<" to 0"<<" with seek "<<head<<endl;
		seek+=head;
		head = 0;
		for(int i=0;i<n;i++)
		{
			cout<<"Move head from "<<head<<" to "<<a[i]<<" with seek "<<abs(a[i]-head)<<endl;
			seek+=abs(a[i]-head);
			head = a[i];
		}
	}
	else
	{
		for(int i=break_pos;i>=0;i--)
		{
			cout<<"Move head from "<<head<<" to "<<a[i]<<" with seek "<<abs(a[i]-head)<<endl;
			seek+=abs(a[i]-head);
			head = a[i];
		}
		cout<<"Move head from "<<head<<" to "<<0<<" with seek "<<head<<endl;
		seek+=head;
		head = 0;
		for(int i=break_pos+1;i<n;i++)
		{
			cout<<"Move head from "<<head<<" to "<<a[i]<<" with seek "<<abs(a[i]-head)<<endl;
			seek+=abs(a[i]-head);
			head = a[i];
		}
	}
	cout<<endl<<"Total Seek : "<<seek;
	avg_seek = seek/(float)n;
	cout<<endl<<"Avg seek : "<<avg_seek<<endl;
	
	return 0;
}
