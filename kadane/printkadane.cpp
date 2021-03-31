#include<iostream>
#include<bits/stdc++.h>
#include<cstring>
using namespace std;
int main()
{
	int i,j,start,end,s,n,max_so_far,curr_max;
	cout<<"Enter no. of elements: ";
	cin>>n;
	int arr[n];
	for(i=0;i<n;i++)
		cin>>arr[i];
	
	start=0,end=0,s=0,max_so_far=INT_MIN,curr_max=0;

	for(i=0;i<n;i++)
	{
		curr_max+=arr[i];
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
	cout<<"Max= "<<max_so_far<<", "<<start<<" to "<<end;
}