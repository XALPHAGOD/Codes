#include<iostream>
#include<bits/stdc++.h>
#include<cstring>
using namespace std;
int main()
{
	int i,j,n,s=0,e,t;
	cin>>n;
	e=n-1;
	int arr[n];
	for(i=0;i<n;i++)
		cin>>arr[i];
	int x=n;
	cout<<"\n";
	for(i=0;i<x;cout<<"\n")
	{
		if(arr[i]==0)
		{
			t=arr[i];
			arr[i]=arr[s];
			arr[s]=t;	
			s++;
			i++;
		}
		else if(arr[i]==2)
		{
			t=arr[i];
			arr[i]=arr[e];
			arr[e]=t;
			e--;
			x--;
		}
		else
			i++;
		for(j=0;j<n;j++)
		cout<<arr[j]<<" ";

	}
	
	
}