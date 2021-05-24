#include<bits/stdc++.h>
#define pb push_back
using namespace std;
 int main(){
     int n,e;
     cin>>n>>e;
     vector<pair<int,int>> adj[n];
     for(int i=0;i<e;i++)
     {
         int x,y,wt;
         cin>>x>>y>>wt;
         adj[x].pb({y,wt});
         adj[y].pb({x,wt});
     }

     int src;
     cin>>src;

     vector<int> dist(n);
     vector<bool> vis(n,false);
     priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> pq;

     pq.push({0,src});
     dist[src]=0;

     while(!pq.empty()){
         pair<int,int> p=pq.top();
         pq.pop();

         if(vis[p.second])
            continue;

         vis[p.second]=true;
         dist[p.second]=p.first;

         for(auto x:adj[p.second])
         {
             if(!vis[x.first])      //if vis means previously visited with lower path value
             {
                 pq.push({x.second+p.first,x.first});
             }
         }
     }
     for(int i=0;i<n;i++)
        cout<<i<<" "<<dist[i]<<"\n";
 }