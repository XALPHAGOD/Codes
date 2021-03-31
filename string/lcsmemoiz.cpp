//improved recursion by memoization reduce solving same subproblems
#include<iostream>
#include<cstring>
using namespace std;
static int mat[101][101];
static int cnt=0;
int lcs(string a,string b,int la,int lb)
{
	if(la==0 || lb==0)
		return 0;
	if(mat[la-1][lb-1]!=(-1))
		return mat[la-1][lb-1];
	cnt++;
	if(a[la-1]==b[lb-1])
		return mat[la-1][lb-1]=(1+lcs(a,b,la-1,lb-1));
	else
		return mat[la-1][lb-1]=(max(lcs(a,b,la-1,lb),lcs(a,b,la,lb-1)));
}
int main()
{	
	string	a,b;
	cout<<"Enter string 1: ";
	getline(cin,a);
	cout<<"Enter string 2: ";
	getline(cin,b);
	int la=a.length(),lb=b.length();
	memset(mat,-1,sizeof(mat));
	cout<<"Ans= "<<lcs(a,b,la,lb)<<" ";
	cout<<cnt;	
}							
							
							
							