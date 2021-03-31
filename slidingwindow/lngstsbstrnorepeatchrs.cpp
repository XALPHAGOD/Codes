#include<iostream>
#include<cstring>
using namespace std;

int main()
{	
	string s;
	cout<<"Enter a string: ";
	getline(cin,s);
	int temp[26],i=0,j=0,mx=0,count=0;
	memset(temp,0,sizeof(temp));
	//cout<<"l i j c m\n"; 
	while(j<s.length())
	{
		//cout<<s[j]<<" "<<i;
		if(temp[s[j]-'a']==0)
			count++;
		temp[s[j]-'a']++;
		j++;
		//cout<<" "<<j;
		if(count==(j-i))
			mx=max(mx,count);
		else
		{
			temp[s[i]-'a']--;
			if(temp[s[i]-'a']==0)
				count--;
			i++;
		}
		//cout<<" "<<count<<" "<<mx<<"\n";	
	}
	cout<<"Ans= "<<mx;
}