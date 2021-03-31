#include<iostream>
#include<cstring>
using namespace std;
//variable sized window
int main()
{	
	int n,k,i,j,sum=0,mx=0;
	cout<<"Enter n: ";
	cin>>n;
	int a[n];
	cout<<"Enter elements: ";
	for(i=0;i<n;i++)	
		cin>>a[i];
	cout<<"Enter k: ";
	cin>>k;
	i=0,j=0;
	while(j<n) //  4 1 1 1 2 3 5  
	{
		if(sum<=k)
		{	
			if(sum==k)
				mx=max(mx,j-i);
			sum+=a[j];	
			j++;
		}	
		else
		{
			sum-=a[i];
			i++;
		}
	}
	cout<<"Ans= "<<mx;	
}