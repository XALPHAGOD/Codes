#include<iostream>
using namespace std;

int main()
{
	int i,j,n,k;					// j     0 1 2 3 4 5 6 7 8 9 10 11 12
	cout<<"Enter no. of coins: ";			//     0 1 0 0 0 0 0 0 0 0 0  0  0  0  
	cin>>n;						//a[i] 1 1 1 1 1 1 1 1 1 1 1  1  1  1 
	int a[n];					//     2 1 1 2 2 3 3 4 4 5 5  6  6  7
	cout<<"Enter types: ";				//     5 1 1 2 2 3 4 5 6 7
	for(i=0;i<n;i++)				//     8 1 1 2 2 3 4 5 6 8
		cin>>a[i];
	cout<<"Enter value: ";				
	cin>>k;						//       0 1 2 3 4 5 6 7 8 9 10 11 12 13 14 15 16										
	int temp[n+1][k+1];				//     0		
	for(i=0;i<=k;i++)				//     8 1 0 0 0 0 0 0 0 1 0  0  0  0  
		temp[0][i]=0;				//     5 1 0 0 0 0 1 0 0 1 0  1  0  0
	for(i=0;i<=n;i++)				//     2 1 0 1 0 1 1 1 1 2 1  2  1  1 
		temp[i][0]=1;				//     1 1 1 2 2 3 4 5 6 8 
	for(i=1;i<=n;i++)				
	{
		for(j=1;j<=k;j++)			//   	 1 1 2 2 3 4 5 6 8 9  12  13  // 8 2 5 1  
		{					// optimised temp[k+1]=initially set all to 0, temp[0]=1, i from 0 to <=n, j from j to <=k, temp[j]+=temp[j-a[i]], space complex=O(n)
			if(j<a[i-1])
				temp[i][j]=temp[i-1][j];
			else
				temp[i][j]=temp[i-1][j]+temp[i][j-a[i-1]];
		}
	}
	cout<<"Ans= "<<temp[n][k]<<"\n";
	for(i=0;i<=n;cout<<"\n",i++)
	{
		for(j=0;j<=k;j++)
			cout<<temp[i][j]<<" ";
	}
}
