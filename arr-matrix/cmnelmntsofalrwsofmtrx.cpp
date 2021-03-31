#include <bits/stdc++.h>
using namespace std;
int main()
{
	int a[3][3];
	for(int i=0;i<3;i++)
		for(int j=0;j<3;j++)
			cin>>a[i][j];

	unordered_map<int,int> mp;
	vector<int> res;
	for(i=0;i<3;i++)
		mp[a[0][i]]=1;
	for(i=1;i<3;i++)
	{
		for(j=0;j<3;j++)
		{
			if(mp[a[i][j]]==i)
			{
				mp[a[i][j]]++;
				if(i==(3-1))
					res.push_back(a[i][j]);
			}
		}
	}
return res;
}
