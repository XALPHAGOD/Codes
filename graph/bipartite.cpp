#include<bits/stdc++.h>
using namespace std;
int cnt=0;
bool solve(int node,vector<vector<int>> &adj,vector<bool> &vis,vector<int> &col){
    cnt++;
    vis[node]=true;
    for(int i:adj[node]){
        if(!vis[i]){
            if(col[i]==-1){
                col[i]=1-col[node];
                if(!solve(i,adj,vis,col))
                    return false;
            }
            else if(col[i]==col[node])
                return false;
        }
        else{
            if(col[i]==col[node])
                return false;
        }
    }
    return true;
}
bool isBipartite(int n,vector<vector<int>> &adj){
    vector<int> col(n,-1);
    vector<bool> vis(n,false);
    for(int i=0;i<n;i++){
        if(!vis[i]){
            col[i]=0;
            if(!solve(i,adj,vis,col))
                return false;
        }
    }
    cout<<"\n";
    for(int i=0;i<n;i++)
        cout<<i<<" "<<col[i]<<"\n";
    return true;
}
int main(){
    int n;
    cin>>n;
    int e;
    cin>>e;
    vector<vector<int>> adj(n);
    for(int i=0;i<e;i++){
        int x,y;
        cin>>x>>y;
        adj[x].push_back(y);
        adj[y].push_back(x);
    }
    if(isBipartite(n,adj))
        puts("YES");
    else
        puts("NO");

    cout<<cnt;
}