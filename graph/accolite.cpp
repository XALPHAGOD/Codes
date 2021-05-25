#include<bits/stdc++.h>
using namespace std;
// string s;
// vector<int> fr;
// int maxfr=0;
// char mch;
// bool cycle=false;
// int cnt1=0,cnt2=0;
// void dfs(int node,vector<vector<int>> &adj,vector<bool> &vis){
//     cnt1++;
//     vis[node]=true;
//     fr[s[node]-'a']++;
//     if(fr[s[node]-'a']>maxfr){
//         maxfr=fr[s[node]-'a'];
//         mch=s[node];
//     }

//     for(int i:adj[node]){
//         if(vis[i]){
//             cycle=true;
//             return;
//         }
//         dfs(i,adj,vis);
//         if(cycle)
//             return;
//     }
//     vis[node]=false;
//     fr[s[node]-'a']--;
//     cnt2++;
// }
// int main(){
//     int n,e;
//     cin>>n>>e;
//     char t=getchar();
//     getline(cin,s);
//     vector<vector<int>> adj(n);
//     for(int i=0;i<e;i++)
//     {
//         int x,y;
//         cin>>x>>y;
//         adj[x-1].push_back(y-1);
//     }

//     vector<bool> vis(n);
//     for(int i=0;i<n;i++){
//         fr.clear();
//         fr.resize(26,0);
//         dfs(i,adj,vis);
//         if(cycle)
//             break;
//     }
//     if(cycle)
//         cout<<"-1";
//     else
//         cout<<maxfr;//<<" "<<mch<<"\n"<<cnt1<<" "<<cnt2;
// }

int main(){
    int n,e;
    cin>>n>>e;
    char x=getchar();
    string s;
    getline(cin,s);

    vector<vector<int>> fr(n, vector<int>(26));
    vector<int> indeg(n,0);
    vector<vector<int>> adj(n);

    for(int i=0;i<e;i++){
        int x,y;
        cin>>x>>y;
        adj[x-1].push_back(y-1);
        indeg[y-1]++;
    }

    queue<int> q;
    for(int i=0;i<n;i++)
        if(indeg[i]==0)
            q.push(i);

    int cnt=n;
    while(!q.empty()){
        int node= q.front();
        q.pop();
        cnt--;

        fr[node][s[node]-'a']++;

        for(int i:adj[node]){
            for(int j=0;j<26;j++){
                fr[i][j]=max(fr[i][j], fr[node][j]);
            }
            indeg[i]--;
            if(indeg[i]==0)
                q.push(i);
        }
    }

    if(cnt){
        puts("-1");
        return 0;
    }

    int maxi=0;
    for(int i=0;i<n;i++){
        for(int j=0;j<26;j++){
            maxi=max(maxi,fr[i][j]);
        }
    }
    cout<<maxi;
}