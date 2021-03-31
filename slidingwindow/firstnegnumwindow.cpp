#include<iostream>
#include<cstring>
using namespace std;

int main()
{	
	int n,k,i,j;
	cout<<"Enter n: ";
	cin>>n;
	int a[n];
	cout<<"Enter elements: ";
	for(i=0;i<n;i++)	
		cin>>a[i];
	cout<<"Enter k: ";
	cin>>k;
	int temp[n-k+1],tr=-1,tf=0;
	i=0,j=0;
	while(j<n)
	{
		if(a[j]<0)
			temp[++tr]=a[j];
	
		if((j-i+1)<k)
			j++;
		else
		{
			if(tf>tr)
				cout<<"0 ";
			else
				cout<<temp[tf]<<" ";
			
			if(a[i]<0) //indicates that 1st element of current window is negative and will be the front element of queue as well as the output and dequeuing it 
				tf++;
			i++;
			j++;	
		}
	}
}