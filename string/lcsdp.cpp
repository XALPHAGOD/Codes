#include<iostream>
#include<cstring>
#include<bits/stdc++.h>
using namespace std;
static int mat[10001][10001];
void printlcs(string a,string b,int la,int lb)
{
	int i=la+1,j=lb+1;
	string x;
	while(i>0 && j>0)
	{
		if(a[i-1]==b[j-1])
		{
			x+=a[i-1];
			i--;
			j--;
		}
		else if(mat[i-1][j]>mat[i][j-1])
			i--;
		else
			j--;
	}
	reverse(x.begin(),x.end());
	cout<<x<<"\n";
}
int main()
{	
	string	a,b;
	cout<<"Enter string 1: ";
	getline(cin,a);
	cout<<"Enter string 2: ";
	getline(cin,b);
	int la=a.length(),lb=b.length(),i,j;
	for(i=0;i<=la;i++)
		mat[i][0]=0;
	for(i=0;i<=lb;i++)
		mat[0][i]=0;
	for(i=1;i<=la;i++)
	{
		for(j=1;j<=lb;j++)
		{
			if(a[i-1]==b[j-1])
				mat[i][j]=1+mat[i-1][j-1];
			else
				mat[i][j]=max(mat[i-1][j],mat[i][j-1]);	
		}	
	}
	cout<<"Ans= "<<mat[la][lb]<<"\n";
	printlcs(a,b,la,lb);
	/*for(i=0;i<=la;cout<<"\n",i++)
		for(j=0;j<=lb;j++)
			cout<<mat[i][j]<<" ";
	*/	
}							
							
							
							