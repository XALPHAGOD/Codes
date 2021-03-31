#include <bits/stdc++.h>
using namespace std;
int main()
{
	int n;
	cin>>n;
	int arr[n],ll[n],rl[n];
	stack<int> st;
	for(int i=0;i<n;i++)
		cin>>arr[i];
	for(int i=0;i<n;i++)
	{
		if(st.empty())
		{
			st.push(i);	
			ll[i]=0;
			continue;
		}
		while(!st.empty() && arr[i]<=arr[st.top()])
		{st.pop();}
		ll[i]=(st.empty())?0:(st.top()+1);
		st.push(i);		
	}
	while(!st.empty())
	{st.pop();}
	
	for(int i=n-1;i>=0;i--)
	{
		if(st.empty())
		{
			st.push(i);
			rl[i]=n-1;
			continue;
		}
		while(!st.empty() && arr[i]<=arr[st.top()])
		{st.pop();}
		rl[i]=(st.empty())?(n-1):(st.top()-1);
		st.push(i);
	}
	int armx=0;
	for(int i=0;i<n;i++)
	{
		armx=max(armx,arr[i]*(rl[i]-ll[i]+1));
	}
	cout<<"Max area= "<<armx;
}
