#include <bits/stdc++.h>
using namespace std;
int main()
{
	int n;
	cin>>n;
	int a[n],maxi,prof[n],mini;
	int i;
	for(i=0;i<n;i++)
		cin>>a[i];
	maxi=a[n-1];
	prof[n-1]=0;
	for(i=n-2;i>=0;i--)
	{
		maxi=max(maxi,a[i]);
		prof[i]=max(prof[i+1],maxi-a[i]);
	}	

	for(i=0;i<n;i++)
		cout<<prof[i]<<" ";
	cout<<"\n";

	mini=a[0];
	for(i=1;i<n;i++)
	{
		mini=min(mini,a[i]);
		prof[i]=max(a[i]-mini+prof[i],prof[i-1]);
	}
	for(i=0;i<n;i++)
		cout<<prof[i]<<" ";
	cout<<"\n";

	cout<<"Max Profit= "<<prof[n-1];
}
