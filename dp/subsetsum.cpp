#include<iostream>
using namespace std;

int main()
{
	int i,j,n,k;					
	cout<<"Enter no. of elemsnts: ";	
	cin>>n;				//6		
	int a[n];					
	cout<<"Enter elements: ";				 
	for(i=0;i<n;i++)		// 1 11 7 5 3 4		
		cin>>a[i];
	cout<<"Enter sum: ";
	cin>>k;				// 10
	bool temp[n+1][k+1];		//  0 1 2 3 4 5 6 7 8 9 10
	for(i=1;i<=k;i++)		//0 T F F F F F F F F F  F 
		temp[0][i]=false;	//1 T T F F F F F F F F  F  1 	
	for(i=0;i<=n;i++)		//2 T T F F F F F F F F  F  11 
		temp[i][0]=true;	//3 T T F F F F F T T F  F  7	
	for(i=1;i<=n;i++)		//4 T T F F F T T T T F  F  5
	{				//5 T T F T T T T T T T  T  3
		for(j=1;j<=k;j++)	//6 T T	F T T T T T T T  T  4
		{
			if(j<a[i-1])
				temp[i][j]=temp[i-1][j];
			else
				temp[i][j]=temp[i-1][j] || temp[i-1][j-a[i-1]]; // count num of subsets replace || by + make necessary changes to array datatype
		}			 //if temp[i-1][j] is true then inclusion of new element does not affect subset sum as it was previously satisfied 
	}				 //temp[i-1][j-a[i-1]] denotes that if x=j-a[i-1] (a[i-1] is new inclusion element) then if the element from prev row was satisfying the sum of val x
	if(temp[n][k])
		cout<<"True \n";
	else
		cout<<"False \n";
	/*
	for(i=0;i<=n;cout<<"\n",i++)
	{
		for(j=0;j<=k;j++)
			cout<<temp[i][j]<<" ";
	}
	*/
}
