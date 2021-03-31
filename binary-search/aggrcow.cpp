#include <bits/stdc++.h>
using namespace std;
int main()
{
	int t;
	cin>>t;
	while(t--)
	{
		int n,cow;
		cin>>n>>cow;
		int arr[n];
		for(int i=0;i<n;i++)
			cin>>arr[i];
		sort(arr,arr+n);
		int l=0,m,h=arr[n-1],currval=0;
		while(l<=h)
		{
			m=l+(h-l)/2;
			int cnt=0,st=0;
			for(int i=1;i<n;i++)
			{
				if(arr[i]-arr[st]>=mid)
					cnt++,st=i;	
			}
			if(cnt<cow)
				low=mid+1;
			else
			{
				curval=mid;
				high=mid-1;
			}	
		}
		cout<<curval<<"\n";
	}
}
