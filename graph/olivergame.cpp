//Euler tour

#include<bits/stdc++.h>
using namespace std;
#define pb push_back

int c=0;
vector<int> in,out;

void dfs(int src,vector<int> adj[]){
    in[src]=++c;
    for(auto x:adj[src])
    {
        if(in[x]==0)
            dfs(x,adj);
    }
    out[src]=++c;
}
int main()
{
    ios_base::sync_with_stdio(false);       //very fast io
    cin.tie(NULL);

    int n;
    cin>>n;
    vector<int> adj[n+1];
    in.resize(n+1);
    out.resize(n+1);

    for(int i=0;i<n-1;i++)
    {
        int x,y;
        cin>>x>>y;
        adj[x].pb(y);
        adj[y].pb(x);
    }

    dfs(1,adj);

    int q;
    cin>>q;
    for(int i=0;i<q;i++)
    {
        int x,y,d;
        cin>>d>>y>>x;
        if(d==0)
        {
            if(in[y]<=in[x] && out[y]>=out[x])
                puts("YES");
            else
                puts("NO");
        }
        else
        {
            if(in[x]<=in[y] && out[x]>=out[y])
                puts("YES");
            else
                puts("NO");
        }
    }
}