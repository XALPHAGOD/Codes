#include <bits/stdc++.h>
using namespace std;
int main()
{
	int dp[n],mr=arr[0];
    for(int i=0;i<n;i++)
        dp[i]=INT_MAX;
    dp[0]=0;
    for(int i=1;i<n;i++)
    {
        if(mr<i)
            break;
        mr=max(mr,arr[i]+i);
        for(int j=0;j<i;j++)
        {
            if(arr[j]+j>=i)
                dp[i]=min(dp[i],dp[j]+1);
        }
    }
    //for(int i=0;i<n;i++)
      //  cout<<dp[i]<<" ";
    //cout<<mr<<"x";
    if(mr<(n-1))
        return -1;
    if(dp[n-1]>0)
        return dp[n-1];
    return -1;
}