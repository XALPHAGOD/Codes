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
	int max_sum_so_far=INT_MIN,max_sum_till_here=0;		//msf=INT_MIN to work for all -ve values
	for(i=0;i<n;i++)
	{
		max_sum_till_here+=arr[i];
		if(max_sum_till_here<arr[i])
			max_sum_till_here=arr[i];	
		if(max_sum_so_far<max_sum_till_here)
			max_sum_so_far=max_sum_till_here;
	}
	cout<<max_sum_so_far;
}