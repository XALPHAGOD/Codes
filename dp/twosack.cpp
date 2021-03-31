#include<iostream>
#include<bits/stdc++.h>
#include<cstring>
using namespace std;
int cneg(int *arr, int n)
{
	int i,c=0;
	for(i=0;i<n;i++)
		if(arr[i]<0)
			c++;
	if(c==n)
		return 1;
	else
		return 0;
}
int main()
{
	int i,j,start,end,s,n,max_so_far,curr_max,sum=0;
	cout<<"Enter no. of elements: ";
	cin>>n;
	int arr[n];
	for(i=0;i<n;i++)
		cin>>arr[i];
	
	if(cneg(temp,l1)==1)
	{
		
	}
	else{
	start=0,end=0,s=0,max_so_far=INT_MIN,curr_max=0;

	for(i=0;i<n;i++)
	{
		curr_max+=arr[i];
		if(max_so_far<=curr_max)
		{
			max_so_far=curr_max;
			start=s;
			end=i;
		}

		if(curr_max<0)
		{
			curr_max=0;
			s=i+1;
		}
	}

	/*for(i=start;i<=end;i++)
		cout<<arr[i]<<" ";
	*/

	int l1=end-start+1;
	int temp[l1];
	for(i=start;i<=end;sum+=arr[i],i++)
		temp[i-start]=arr[i]*(-1);
	if(cneg(temp,l1)==1)
		cout<<"Max= "<<sum;
	else
	{
		start=0,end=0,s=0,max_so_far=INT_MIN,curr_max=0;

		for(i=0;i<l1;i++)
		{
			curr_max+=temp[i];
			if(max_so_far<curr_max)
			{
				max_so_far=curr_max;
				start=s;
				end=i;
			}
	
			if(curr_max<0)
			{
				curr_max=0;
				s=i+1;
			}
		}
		
		cout<<"Max= "<<(sum+max_so_far);
	}}
}