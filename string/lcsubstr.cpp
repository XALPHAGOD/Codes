#include<bits/stdc++.h>
#include<cstring>
using namespace std;
int main()
{	
	string	a,b;
	cout<<"Enter string 1: ";
	getline(cin,a);
	//cout<<"Enter string 2: ";
	//getline(cin,b);
	b=a;
	reverse(b.begin(),b.end());
	int la=a.length(),lb=b.length(),mat[la+1][lb+1],i,j,maxi=0,pos;
	for(i=0;i<=la;i++)
		mat[i][0]=0;
	for(i=0;i<=lb;i++)
		mat[0][i]=0;
	for(i=1;i<=la;i++)
	{
		for(j=1;j<=lb;j++)
		{
			if(a[i-1]==b[j-1])
			{
				mat[i][j]=1+mat[i-1][j-1];
				if(mat[i][j]>maxi)
				{
					maxi=mat[i][j];
					pos=i-1;
				}
			}
			else
				mat[i][j]=0;	
		}	
	}
	cout<<"Ans= "<<maxi<<"\n";

	while(maxi--)
	{
		cout<<a[pos--];	
	}
	/*for(i=0;i<=la;cout<<"\n",i++)
		for(j=0;j<=lb;j++)
			cout<<mat[i][j]<<" ";*/	
}							
							
							
							