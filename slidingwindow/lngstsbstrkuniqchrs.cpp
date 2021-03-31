#include<iostream>
#include<cstring>
using namespace std;
// variable size window
int main()
{	
	string s;
	cout<<"Enter a string: ";
	getline(cin,s);
	int i=0,j=0,k,count=0,mx=0;
	cout<<"Enter k: ";
	cin>>k;
	int temp[26];
	memset(temp,0,sizeof(temp));
	while(j<s.length())
	{
		if(count<=k)
		{
			if(count==k)
				mx=max(mx,j-i);	
			if(temp[s[j]-'a']==0)
				count++;
			temp[s[j]-'a']++;
			j++;
		}
		else
		{
			temp[s[i]-'a']--;
			if(temp[s[i]-'a']==0)
				count--;
			i++;
		}	
	}
	cout<<"Ans= "<<mx;
}