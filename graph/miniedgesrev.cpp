#include<bits/stdc++.h>
#define pb push_back
using namespace std;
 int main(){
     int n,e;
     cin>>n>>e;
     vector<pair<int,int>> adj[n];
     for(int i=0;i<e;i++)
     {
         int x,y;
         cin>>x>>y;
         adj[x].pb({y,0});
         adj[y].pb({x,1});
     }

     int src,dest;
     cin>>src>>dest;

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
             if(!vis[x.first])
             {
                 pq.push({x.second+p.first,x.first});
             }
         }
     }
     cout<<dist[dest];
 }