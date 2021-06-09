#include<bits/stdc++.h>
using namespace std;

int n;

void dfs(int r,int c,vector<vector<int>> &dp,string s){
    if(r==n-1 && c==n-1){
        cout<<s<<"\n";
        return;
    }

    if(r==n-1)
        dfs(r,c+1,dp,s+'R');
    else if(c==n-1)
        dfs(r+1,c,dp,s+'D');
    else{
        if(dp[r][c+1]<dp[r+1][c])
            dfs(r,c+1,dp,s+'R');
        else if(dp[r+1][c]<dp[r][c+1])
            dfs(r+1,c,dp,s+'D');
        else{
            dfs(r,c+1,dp,s+'R');
            dfs(r+1,c,dp,s+'D');
        }
    }
}

typedef pair<pair<int,int>,string> pp;

void bfs(vector<vector<int>> &dp){
    queue<pp> q;
    q.push({{0,0},""});

    while(!q.empty()){
        pp x= q.front();
        q.pop();

        if(x.first.first==n-1 && x.first.second==n-1)
            cout<<x.second<<"\n";
        else if(x.first.first==n-1)
            q.push({{x.first.first,x.first.second+1},x.second+'R'});
        else if(x.first.second==n-1)
            q.push({{x.first.first+1,x.first.second},x.second+'D'});
        else{
            if(dp[x.first.first][x.first.second+1]<dp[x.first.first+1][x.first.second])
                q.push({{x.first.first,x.first.second+1},x.second+'R'});
            else if(dp[x.first.first][x.first.second+1]>dp[x.first.first+1][x.first.second])
                q.push({{x.first.first+1,x.first.second},x.second+'D'});
            else{
                q.push({{x.first.first,x.first.second+1},x.second+'R'});
                q.push({{x.first.first+1,x.first.second},x.second+'D'});
            }
        }        
    }
}

int main(){
    cin>>n;

    vector<vector<int>> arr(n, vector<int> (n)), dp(n, vector<int> (n));

    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            cin>>arr[i][j];
            dp[i][j]=0;
        }
    }

    for(int i=n-1;i>=0;i--){
        for(int j=n-1;j>=0;j--){
            if(i==n-1 && j==n-1)
                dp[i][j]=arr[i][j];
            else if(i==n-1)
                dp[i][j]=dp[i][j+1]+arr[i][j];
            else if(j==n-1)
                dp[i][j]=dp[i+1][j]+arr[i][j];
            else
                dp[i][j]=min(dp[i+1][j],dp[i][j+1])+arr[i][j];
        }
    }

    // dfs(0,0,dp,"");

    bfs(dp);

    // for(int i=0;i<n;cout<<"\n",i++){
    //     for(int j=0;j<n;j++){
    //         cout<<dp[i][j]<<" ";
    //     }
    // }
}