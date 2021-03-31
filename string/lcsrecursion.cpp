#include<iostream>
using namespace std;
static int cnt=0;
int lcs(string a,string b,int la,int lb)
{
	if(la==0 || lb==0)
		return 0;
	cnt++;
	if(a[la-1]==b[lb-1])
		return (1+lcs(a,b,la-1,lb-1));
	else
		return (max(lcs(a,b,la-1,lb),lcs(a,b,la,lb-1)));
}
int main()
{	
	string	a,b;
	cout<<"Enter string 1: ";
	getline(cin,a);
	cout<<"Enter string 2: ";
	getline(cin,b);
	cout<<"Ans= "<<lcs(a,b,a.length(),b.length())<<" ";
	cout<<cnt;		
}							
							
							
							