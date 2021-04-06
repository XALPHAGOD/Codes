#include<bits/stdc++.h>
using namespace std;
int dp[1001][1001];
int solve(int arr[], int s, int e, int k){
    if(s==e)        //only 1 element, no removal
        return 0;
    if(dp[s][e]!=(-1))      //already calculated
        return dp[s][e];
    if(arr[e]-arr[s]<=k)    //if range satisfies condition, no removal
        return 0;
    return dp[s][e]=1+ min(solve(arr, s+1, e, k),solve(arr, s, e-1, k));    // 1 elem removal+ min of removal from both halves
}
int main(){
    memset(dp,-1,sizeof(dp));
    int n,k;
    cin>>n>>k;
    int arr[n];
    for(int i=0;i<n;i++)
    {
        cin>>arr[i];
    }
    sort(arr,arr+n);
    cout<<solve(arr,0,n-1,k);
}