#include<bits/stdc++.h>
using namespace std;
typedef pair<int,int> pp;

void topo(int node,vector<vector<pp>> &adj,vector<bool> &vis,stack<int> &st){
    vis[node]=true;
    for(pp i:adj[node]){
        if(!vis[i.second])
            topo(i.second, adj, vis, st);
    }
    st.push(node);
}

int main(){
    int n,e;
    cin>>n>>e;
    vector<vector<pp>> adj(n+1);
    for(int i=0;i<e;i++){
        int wt,from,to;
        cin>>wt>>from>>to;
        adj[from].push_back({wt,to});
    }
    // vector<bool> vis(n+1,false);
    // vector<int> weight(n+1,INT_MAX);
    // priority_queue<pp, vector<pp>, greater<pp>> pq;
    // int src;
    // cin>>src;
    // int cnt=0;
    // pq.push({0,src});
    // cout<<"\n";
    // while (!pq.empty())
    // {
    //     cnt++;
    //     pp x= pq.top();
    //     cout<<x.second<<"\n";
    //     pq.pop();
    //     if(weight[x.second]>x.first){
    //         weight[x.second]=x.first;
    //         for(pp i:adj[x.second])
    //             pq.push({x.first+i.first,i.second});
    //     }
    // }
    // cout<<"\n";
    // for(int i=1;i<=n;i++)
    //     cout<<weight[i]<<" ";
    // cout<<"\n"<<cnt;

    int src;
    cin>>src;
    stack<int> st;
    vector<bool> vis(n+1,false);
    topo(src,adj,vis,st);

    vector<int> dist(n+1,INT_MAX);
    dist[src]=0;
    cout<<"\n";
    while(!st.empty()){
        int node= st.top();
        cout<<node<<"\n";
        st.pop();
        for(pp i:adj[node]){
            if((dist[node]+i.first)<dist[i.second])
                dist[i.second]=dist[node]+i.first;
        }
    }

    cout<<"\n\n";
    for(int i=1;i<=n;i++)
        cout<<dist[i]<<" ";
}