#include<bits/stdc++.h>
using namespace std;
typedef pair<int,pair<int,int>> pp;

class Compare
{
    public:
            bool operator()(pp &A,pp &B){
                // cout<<A.second.first<<" "<<B.second.first<<" "<<A.first<<" "<<B.first<<"\n";
                if(A.first==B.first)
                    return (A.second.second>B.second.second);
                return (A.first>B.first);
            }
};

int main(){
    int n;
    cin>>n;
    int e;
    cin>>e;


    vector<vector<pair<int,int>>> adj(n);
    for(int i=0;i<e;i++)
    {
        int wt,from,to;
        cin>>wt>>from>>to;
        adj[from].push_back({to,wt});
        adj[to].push_back({from,wt});
    }
    cout<<"\n\n";


    vector<bool> vis(n,false);
    priority_queue<pp, vector<pp>, Compare> pq;
    pq.push({0,{0,-1}});
    while (!pq.empty())
    {
        auto x= pq.top();
        pq.pop();
        if(vis[x.second.first])
            continue;
        vis[x.second.first]=true;
        if(x.second.second!=-1){
            cout<<x.second.second<<" - "<<x.second.first<<"\t"<<x.first<<"\n";
        }
        for(auto i:adj[x.second.first])
            pq.push({i.second,{i.first,x.second.first}});
    }
    
}