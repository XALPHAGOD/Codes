#include<iostream>
using namespace std;

int main()
{
	int i,j,x,n,k,p;					
	cout<<"Enter no. of types: ";		
	cin>>n;						
	int a[n];					
	cout<<"Enter types: ";								 
	for(i=0;i<n;i++)					
		cin>>a[i];
	cout<<"Enter Nth stair: ";			//   1 2 5 n=11				
	cin>>k;						//   0 1 2 3 4 5 6 7 8 9 10 11 		
	int temp[k+1];					// 1 1 1 1 1 1 1 1 1 1 1  1  1
	temp[0]=1;					// 2 1 1 2 3 5 8 
	for(i=1;i<=k;i++)				// 5 1 1 2 3 5 
		temp[i]=0;				// 11111 221 212 122 2111 1211 1121 1112 
							// 111111 222 2211-6 21111-5
	for(i=0;i<n;cout<<"\n",i++)	//O(n)
	{		
		for(j=a[i];j<=k;j++)	//O(k)
		{	
			p=0;
			for(x=0;x<=i;x++)	//O(n), calculating each fibonacci term
			{
				if((j-a[x])>=0)
					p+=temp[j-a[x]];
			}
			temp[j]=p;
		}
		for(j=0;j<=k;j++)
			cout<<temp[j]<<" ";
	}
	cout<<"Ans= "<<temp[k]<<"\n";			
}							
							
							
							