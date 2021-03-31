#include<bits/stdc++.h>
using namespace std;
int gcd(int a,int b)
{
    if(b==0)
        return a;
    return gcd(b,a%b);
}
int main()
{
    int n;
    cin>>n;
    int a[n];
    for(int i=0;i<n;i++)
        cin>>a[i];
    int dp[n+1];
    dp[n]=0;
    for(int i=n-1;i>=0;i--)
    {
        int mini=INT_MAX;
        for(int j=i;j<n;j++)
        {
            if(gcd(a[i],a[j])>1)
            {
                mini=min(mini,1+dp[j+1]);
            }
        }
        dp[i]=(a[i]==1)?(dp[i+1]+1):mini;
    }
    /*for(int i=0;i<=n;i++)
        cout<<dp[i]<<" ";*/
    cout<<"\n"<<dp[0];
}