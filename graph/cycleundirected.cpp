#include<bits/stdc++.h>
using namespace std;
bool isCyclic(int node,int parent,vector<vector<int>> &adj,vector<bool> &vis){
    vis[node]=true;
    for(int i:adj[node]){
        if(i==parent)
            continue;
        if(vis[i])
            return true;
        if(isCyclic(i,node,adj,vis)){
            cout<<i<<" ";
            return true;
        }
    }
    return vis[node]=false;
}
bool hasCycle(int n,vector<vector<int>> &adj){
    vector<bool> vis(n,false);
    for(int i=0;i<n;i++){
        if(isCyclic(i,-1,adj,vis)){
            cout<<i<<" ";
            return true;
        }
    }
    return false;
}
int main(){
    int n;
    cin>>n;
    int e;
    cin>>e;
    vector<vector<int>> adj(n);
    for(int i=0;i<e;i++){
        int from,to;
        cin>>from>>to;
        adj[from].push_back(to);
        adj[to].push_back(from);
    }
    if(hasCycle(n,adj))
        puts("YES");
    else
        puts("NO");
}