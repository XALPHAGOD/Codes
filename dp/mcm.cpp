#include <bits/stdc++.h>
using namespace std;
int dp[1001][1001];
int mcm(int i, int j, int mat[]){
    if(i==j)
        return 0;
    if(dp[i][j]!=-1)
        return dp[i][j];
    
    int mini= INT_MAX;

    for(int x=i;x<j;x++){       //every poss parti
        mini=min(mini, mcm(i,x,mat)+ mcm(x+1,j,mat)+ mat[i]*mat[x+1]*mat[j+1]); 
    }
    return dp[i][j]=mini;
}
int main(){
    int n;
    cin>>n;
    int mat[n+1];
    for(int i=0;i<=n;i++)
        cin>>mat[i];
    memset(dp,-1,sizeof(dp));
    cout<<mcm(0,n-1,mat);
}