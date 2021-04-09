#include<bits/stdc++.h>
using namespace std;
int dp[1001][1001];
int sum(vector<pair<int,int>> &vec, int s, int e){
    int su=0;
    for(int i=s;i<=e;i++)
        su+=vec[i].second;
    return su;
}
int solve(vector<pair<int,int>> &vec,int s,int e){
    if(s>e)
        return 0;
    if(s==e)
       return dp[s][s]=vec[s].second;
    if(dp[s][e]!=-1)
        return dp[s][e];
    int mincost=INT_MAX;
    for(int i=s;i<=e;i++)
    {
        mincost=min(mincost, solve(vec,s,i-1)+solve(vec,i+1,e));
    }
    return dp[s][e]=sum(vec,s,e)+mincost;
}
int main(){
    int n;
    cin>>n;
    vector<pair<int,int>> vec;
    for(int i=0;i<n;i++)
    {
        int x,y;
        cin>>x>>y;
        vec.push_back({x,y});
    }
    sort(vec.begin(),vec.end());
    dp[n][n];
    memset(dp,-1,sizeof(dp));
    cout<<solve(vec,0,n-1)<<"\n";
    // for(int i=0;i<n;cout<<"\n",i++)
    //     for(int j=0;j<n;j++)
    //         cout<<dp[i][j]<<" ";
}