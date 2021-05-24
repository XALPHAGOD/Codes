#include<bits/stdc++.h>
using namespace std;
typedef pair<int,pair<int,int>> pp;

int findAbsoluteParentPathCompression(int n,vector<int> &absParent){
    if(absParent[n]==-1)
        return n;
    return absParent[n]=findAbsoluteParentPathCompression(absParent[n],absParent);      //path compression
}

int main(){
    int n;
    cin>>n;
    vector<int> absParent(n,-1);
    vector<int> rank(n,0);
    int e;
    cin>>e;
    priority_queue<pp, vector<pp>, greater<pp>> pq;
    for(int i=0;i<e;i++)
    {
        int wt,from,to;
        cin>>wt>>from>>to;
        pq.push({wt,{min(from,to),max(from,to)}});
    }
    cout<<"\n\n";

    int cost=0;
    while(!pq.empty()){
        pp x=pq.top();
        pq.pop();
        int parA= findAbsoluteParentPathCompression(x.second.first, absParent);
        int parB= findAbsoluteParentPathCompression(x.second.second, absParent);

        if(parA==parB)
            continue;

        if(rank[parA]==rank[parB]){     //union
            absParent[parA]=parB;
            rank[parB]++;
        }
        else if(rank[parA]<rank[parB]){
            absParent[parA]=parB;
        }
        else{
            absParent[parB]=parA;
        }
        cost+=x.first;
        cout<<x.second.first<<" - "<<x.second.second<<"\t"<<x.first<<"\n";
    }
    cout<<"\nCost= "<<cost;
}