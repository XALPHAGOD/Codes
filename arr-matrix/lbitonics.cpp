#include <bits/stdc++.h>
using namespace std;
int main()
{
	int n;
	cout<<"Enter no. elements: ";
	cin>>n;
	vector<int> a,temp1(n),temp2(n);
	for(int i=0;i<n;i++)
	{
		int x;
		cin>>x;
		a.push_back(x);
	}
	for(int i=0;i<n;i++)
		temp1[i]=temp2[i]=1;
	int mx=1,mn=1;
	for(int i=0;i<n-1;i++)
	{
		for(int j=i+1;j<n;j++)
		{
			if(a[j]>a[i] && temp1[j]<=temp1[i])
			{
				temp1[j]=temp1[i]+1;
				mx=max(mx,temp1[j]);
			}
		}
	}
	for(int i=0;i<n-1;i++)
	{
		for(int j=i+1;j<n;j++)
		{
			if(a[j]<a[i] && temp2[j]<=temp2[i])
			{
				temp2[j]=temp2[i]+1;
				mn=max(mn,temp2[j]);
			}
		}
	}
	int mbs=0;
	for(int i=0;i<n;i++)	
		mbs=max(mbs,temp1[i]+temp2[i]-1);
	cout<<"LBS= "<<mx<<" "<<mn<<" "<<mbs;
}