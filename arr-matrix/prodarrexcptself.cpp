#include <bits/stdc++.h>
using namespace std;
int main()
{
	int n;
	cin>>n;
	int nums[n];
	for(int i=0;i<n;i++)
		cin>>nums[i];
	vector<long long int> res(n,1);
    	for(int i=1;i<n;i++)
		res[i]*=res[i-1]*nums[i-1];
	long long int temp=nums[n-1];
	for(int i=n-2;i>=0;temp*=nums[i],i--)
		res[i]*=temp;

	for(int i=0;i<n;i++)
		cout<<res[i]<<" ";
	cout<<"\n\n\n";
}
