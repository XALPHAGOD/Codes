#include <bits/stdc++.h>
#define pb push_back
using namespace std;

vector<int> order;
void dfs(int src,vector<int> adj[],vector<bool> &vis)
{
    vis[src]=true;
    for(auto x:adj[src])
    {
        if(!vis[x])
            dfs(x,adj,vis);
    }
    order.pb(src);      //finishing time alt to stack
}
void rvdfs(int src,vector<int> adj[],vector<bool> &vis)
{
    vis[src]=true;
    for(auto x:adj[src])
    {
        if(!vis[x])
            dfs(x,adj,vis);
    }
}
int main()
{
    int n,e;
    cin>>n>>e;
    vector<int> adj[n],rev[n];
    for(int i=0;i<e;i++)
    {
        int x,y;
        cin>>x>>y;
        adj[x].pb(y);
        rev[y].pb(x);       //check
    }
    vector<bool> vis(n),vis1(n);
    for(int i=0;i<n;i++)
    {
        if(!vis[i])
            dfs(i,adj,vis);     //dfs for finding order
    }
    int scc=0;
    for(int i=n-1;i>=0;i--)
    {
        if(!vis1[order[i]])
        {
            rvdfs(order[i],rev,vis1);       //count SCC in rev-order
            scc++;
        }
    }
    cout<<scc;
}