#include <bits/stdc++.h>
using namespace std;
void printpal(string s,int l,int h)
{
    for(int i=l;i<=h;i++)
        cout<<s[i];
    cout<<"\n";
}
int main() {
	//code
	int t;
	cin>>t;
	while(t--)
	{
	    string s,res;
	    cin>>s;
	    int maxl=0,i,l,h,st=0,en=0;
	    for(i=1;i<s.length();i++)
	    {
	       l=i-1;
	       h=i;
	       while(s[l]==s[h] && l>=0 && h<s.length())
	       {
	           if(h-l+1>maxl)
	           {
	               maxl=h-l+1;
	               st=l;
	               en=h;
	           }
	           l--;
	           h++;
	       }
	       
	       l=i-1;
	       h=i+1;
	       while(s[l]==s[h] && l>=0 && h<s.length())
	       {
	           if(h-l+1>maxl)
	           {
	               maxl=h-l+1;
	               st=l;
	               en=h;
	           }
	           l--;
	           h++;
	       }
	    }
	    printpal(s,st,en);
	}
	return 0;
}