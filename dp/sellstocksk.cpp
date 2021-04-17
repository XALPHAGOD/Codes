#include<bits/stdc++.h>
using namespace std;
int main(){
    int n,k;
    cin>>n;
    int price[n];
    
    for(int i=0;i<n;i++)
        cin>>price[i];
    cin>>k;

    int dp[k+1][n];
    memset(dp,0,sizeof(dp));
    
    for(int t=1;t<=k;t++){
        
        int max_till_date=INT_MIN;     //1st day d=0, no profit   
        
        for(int d=1;d<n;d++){       

            max_till_date = max ( max_till_date , dp[t-1][d-1] - price[d-1] );
            
            dp[t][d] = max ( dp[t][d-1] , max_till_date + price[d] );
        }
    }
    cout<<dp[k][n-1];
}