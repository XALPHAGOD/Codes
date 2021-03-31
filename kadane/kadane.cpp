#include<iostream>
#include<bits/stdc++.h>
#include<cstring>
using namespace std;
int main()
{
	int i,j,n;
	cout<<"Enter no. of elements: ";
	cin>>n;
	int arr[n];
	for(i=0;i<n;i++)
		cin>>arr[i];
	int max_so_far=INT_MIN,curr_max=0;
	for(i=0;i<n;i++)
	{
		curr_max+=arr[i];
		if(curr_max<arr[i])
			curr_max=arr[i];	
		if(max_so_far<curr_max)
			max_so_far=curr_max;
	}
	cout<<max_so_far;
}