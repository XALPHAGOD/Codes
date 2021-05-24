#include<bits/stdc++.h>
using namespace std;
typedef vector<pair<int,pair<int,int>>> pp;
#define pb push_back
int main(){
    int n;
    cin>>n;
    int e;
    cin>>e;
    pp edges;
    for(int i=0;i<e;i++){
        int wt,from,to;
        cin>>wt>>from>>to;
        edges.pb({wt,{from,to}}); 
    }
    int src;
    cin>>src;

    vector<int> dist(n+1,INT_MAX);      //1 indexing
    dist[src]=0;

    for(int i=0;i<n-1;i++){     //relax for n-1 times
        for(int j=0;j<e;j++){
            pair<int,pair<int,int>> x=edges[j];
            int wt=x.first, from=x.second.first, to=x.second.second;

            if(dist[from]==INT_MAX)
                continue;

            if(dist[from]+wt<dist[to]){     //relaxation
                dist[to]=dist[from]+wt;
            }
        }

        cout<<"\n";
        for(int j=1;j<=n;j++)
            cout<<dist[j]<<" ";
    }

    bool fl= false;

    for(int j=0;j<e;j++){           //try to relax for 1 more time to see if any change, if any change then -ve wt cycle is present
        pair<int,pair<int,int>> x=edges[j];
        int wt=x.first, from=x.second.first, to=x.second.second;

        if(dist[from]==INT_MAX)
            continue;

        if(dist[from]+wt<dist[to]){
            fl=true;
            dist[to]=dist[from]+wt;
        }
    }

    if(fl){
        cout<<"\n\nNegative Cycle\n";
        for(int j=1;j<=n;j++)
            cout<<dist[j]<<" ";
    }
    else
        cout<<"\n\nNo Negative Cycle";
    
}