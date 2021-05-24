#include<bits/stdc++.h>
using namespace std;
#define pb push_back
int cnt;
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
        if(!vis[i]){
            
        }
    }
}