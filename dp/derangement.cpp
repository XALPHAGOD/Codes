#include<bits/stdc++.h>
using namespace std;
int main(){
    int n;
    cin>>n;
    int dp[n+1];        //space optimization like fibonacci
    dp[0]=1;
    dp[1]=0;
    dp[2]=1;
    for(int i=3;i<=n;i++)
        dp[i]=(i-1)*(dp[i-2]+dp[i-1]);
    cout<<dp[n];
}
/*
for all n
take one elem out of those n
n-1 possible pos, so we multipy by n-1
pick a valid position for that elem
Case 1: swap the elem in pos with our picked elem, after swap, both of them satisfy derangement, have to derange remaining n-2 elems
Case 2: if we place only our picked elem at the pos but not the other elem initially present at pos, 
only our picked elem satisfy derangement, have to derange remaining n-1 elems
*/