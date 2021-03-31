#include <bits/stdc++.h>
using namespace std;
void precomp(string pat,int lps[])
{
	lps[0]=0;
	int len=0,j=1;
	while(j<pat.size())
	{
		if(pat[j]==pat[len])
		{
			len++;
			lps[j++]=len;
		}
		else	
		{
			if(len!=0)
				len=lps[len-1];
			else
				lps[j++]=0;
		}
	}
}
void lps(string pat,string text)
{
	int lpsarr[pat.length()];
	precomp(pat,lpsarr);
	
	for(int x=0;x<pat.length();x++)cout<<pat[x]<<" ";
	cout<<"\n";
	for(int x=0;x<pat.length();x++)cout<<lpsarr[x]<<" ";
	cout<<"\n";
	
	int i=0,j=0;
	while(j<text.length())
	{
		if(pat[i]==text[j])
		{
			i++;
			j++;
		}
		if(i==pat.length())
		{
			cout<<"Found at index: "<<j-i;
			return;
		}
		else if(pat[i]!=text[j])
		{
			if(i!=0)
				i=lpsarr[i-1];
			else
				j++;
		}	
	}
	cout<<"Not Found";
}
int main()
{
	string pat,text;
	cout<<"Enter pattern: ";
	getline(cin,pat);
	cout<<"Enter text: ";
	getline(cin,text);
	lps(pat,text);	
}
