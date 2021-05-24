#include<bits/stdc++.h>
using namespace std;
#define pb push_back
int cnt;
void findBridges(int node,int par,vector<vector<int>> &adj,vector<bool> &vis,vector<int> &inCur,vector<int> &lowInNei){

    vis[node]=true;
    inCur[node]=cnt++;
    lowInNei[node]=inCur[node];

    for(int nei:adj[node]){
        if(nei==par)
            continue;

        if(!vis[nei]){

            findBridges(nei,node,adj,vis,inCur,lowInNei);

            if(lowInNei[nei]>inCur[node]){
                cout<<node<<" - "<<nei<<"\n";
            }

            lowInNei[node]=min(lowInNei[node],lowInNei[nei]);
        }
        else{
            lowInNei[node]=min(lowInNei[node],inCur[nei]);
        }
    }
}
int main(){
    int n;
    cin>>n;
    int e;
    cin>>e;
    vector<vector<int>> adj(n+1);
    for(int i=0;i<e;i++){
        int x,y;
        cin>>x>>y;
        adj[x].pb(y);
        adj[y].pb(x);
    }
    cout<<"\n\n";
    vector<bool> vis(n+1,false);
    vector<int> inCur(n+1,-1),lowInNei(n+1,-1);     //inCur=discovery of current node, lowInNei=earlier time in which any neighbour/self can be reached
    cnt=0;

    for(int i=1;i<=n;i++){       //for disconnected components
        if(!vis[i])
            findBridges(i,-1,adj,vis,inCur,lowInNei);
    }
}