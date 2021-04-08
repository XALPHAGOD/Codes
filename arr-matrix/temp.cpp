#include<bits/stdc++.h>
using namespace std;
int main(){
    long long int n;
    cin>>n;
    vector<long long int> dp(n+1,0);
	dp[0]=1,dp[1]=0,dp[2]=0;
    for(int i=3;i<=n;i++)
        dp[i]+=dp[i-3];
    for(int i=5;i<=n;i++)
        dp[i]+=dp[i-5];
    for(int i=10;i<=n;i++)
        dp[i]+=dp[i-10];
    for(int i=0;i<=n;i++)
        cout<<dp[i]<<" ";
    cout<<"\n"<<dp[n];
}