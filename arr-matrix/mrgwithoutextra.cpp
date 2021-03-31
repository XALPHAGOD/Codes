#include <bits/stdc++.h>
using namespace std;
int main()
{
	//1 2 5 7
	//3 4 5 9

	int m,n,i,j,last;
	cin>>m>>n;
	int a[m],b[n];
	for(i=0;i<m;i++)
		cin>>a[i];
	for(i=0;i<n;i++)
		cin>>b[i];

	for(i=n-1;i>=0;i--)
	{
		last=a[m-1];
		for(j=m-2;j>=0 && b[i]<a[j];j--)
			a[j+1]=a[j];	
		if(j!=m-2 || b[i]<last)
		{
			a[j+1]=b[i];
			b[i]=last;
		}

	}
	for(i=0;i<m;i++)
		cout<<a[i]<<" ";
	for(i=0;i<n;i++)
		cout<<b[i]<<" ";
}
