#include<iostream>
#include<climits>
using namespace std;

int main()
{
	int i,j,n,k;					
	cout<<"Enter no. of coins: ";		
	cin>>n;						
	int a[n];					
	cout<<"Enter types: ";				// 1 8 5 2 k=11				 
	for(i=0;i<n;i++)					
		cin>>a[i];
	cout<<"Enter sum: ";				//   0 1 2 3 4 5 6 7 8 9 10 11
	cin>>k;						// 0 0 x x x x x x x x x  x  x
	int temp[n+1][k+1]; 				// 1 0 1 2 3 4 5 6 7 8 9 10 11
	for(i=1;i<=k;i++)				// 8 0 1 2 3 4 5 6 7 1 2  3  4
		temp[0][i]=INT_MAX-1;			// 5 0 1 2 3 4 1 2 3 1 2  2  3
	for(i=0;i<=n;i++)				// 2 0 1 1 2 2 1 2 2 1 2  2  3
		temp[i][0]=0;				// min(temp[i-1][j],temp[i][j-a[i]]+1)
	for(i=1;i<=n;i++)
	{
		for(j=1;j<=k;j++)
		{
			if(j<a[i-1])
				temp[i][j]=temp[i-1][j];
			else
				temp[i][j]=min(temp[i-1][j],temp[i][j-a[i-1]]+1);
		}
	}
	cout<<"Res= "<<temp[n][k];
}
