#include<iostream>
#include<bits/stdc++.h>
#include<cstring>
using namespace std;
static int c=0;
void printperm(string s,int l,int r)
{
	if(l==r)
	{
		cout<<s<<"\n";
		c++;
		return;
	}
	sort(s.begin()+l,s.end());
	for(int i=l;i<=r;i++)
	{
		swap(s[i],s[l]);
		printperm(s,l+1,r);
		swap(s[i],s[l]);
	}
}

int main()
{
	string s;
	cout<<"Enter string: ";
	getline(cin,s);
	sort(s.begin(),s.end());
	printperm(s,0,s.length()-1);
	cout<<"Count="<<c;
}