#include <bits/stdc++.h>
#include <unordered_map>
#include <vector>
#include <stack>
#define pb push_back
using namespace std;
bool cyclic(int node,vector<int> adj[],vector<bool> vis,vector<bool> &st)
{
	if(st[node])
		return true;
	st[node]=true;
	for(int i=0;i<adj[node].size();i++)
	{
		if(!vis[adj[node][i]] && cyclic(adj[node][i],adj,vis,st))
			return true;
	}
	st[node]=false;
	return false;
}
bool iscyclic(vector<int> adj[],int n)
{
	vector<bool> vis(n,false),st(n,false);
	for(int i=0;i<n;i++)
	{
		vis[i]=true;
		if(cyclic(i,adj,vis,st))
			return true;
	}
	return false;
}
int main()
{
	int n,e;
	cout<<"No. of nodes, edges: ";
	cin>>n>>e;
	vector<int> adj[n];
	for(int i=0;i<e;i++)
	{
		int a,b;
		cin>>a>>b;
		adj[a].pb(b);
	}
	if(iscyclic(adj,n))
		cout<<"Yes";
	else
		cout<<"No";
}
