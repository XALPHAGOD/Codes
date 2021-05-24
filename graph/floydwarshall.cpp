#include<bits/stdc++.h>
using namespace std;
int main(){
    int n;
    cin>>n;
    int e;
    cin>>e;
    vector<vector<int>> adj(n+1, vector<int> (n+1, INT_MAX));
    for(int i=0;i<=n;i++)   
        adj[i][i]=0;
    
    for(int i=0;i<e;i++){
        int wt,from,to;
        cin>>wt>>from>>to;
        adj[from][to]=wt;
    }

    for(int i=1;i<=n;i++){      //for each vertex as intermediate

        for(int j=1;j<=n;j++){      //all adj mat pos
            if(j==i)
                continue;

            for(int k=1;k<=n;k++){
                if(k==i || k==j)
                    continue;

                if(adj[j][i]==INT_MAX || adj[i][k]==INT_MAX)
                    continue;

                adj[j][k]=min(adj[j][k], adj[j][i]+adj[i][k]);
            }
        }
        
        // cout<<"\n";
        // for(int i=1;i<=n;cout<<"\n",i++)
        //     for(int j=1;j<=n;j++)
        //         cout<<((adj[i][j]==INT_MAX)?-1:adj[i][j])<<" ";

    }

    cout<<"\n\nFinal\n";
    for(int i=1;i<=n;cout<<"\n",i++)
        for(int j=1;j<=n;j++)
            cout<<((adj[i][j]==INT_MAX)?-1:adj[i][j])<<" ";

}