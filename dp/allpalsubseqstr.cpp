#include <bits/stdc++.h>
using namespace std;
int dp[1001][1001];
int solve(int st,int en,string s){
    if(st==en)
        return 1;
    if(st>en)
        return 0;
    if(dp[st][en]!=-1)
        return dp[st][en];
    return dp[st][en]= solve(st+1,en,s)+solve(st,en-1,s) + ((s[st]==s[en])?1:-solve(st+1,en-1,s));
}
int main(){
    string str;
    getline(cin,str);

    int dp[str.length()][str.length()];
    memset(dp,0,sizeof(dp));
    for(int gap=0;gap<str.length();gap++){
        for(int start=0,end=gap;end<str.length();start++,end++){
            if(gap==0)
                dp[start][end]=1;
            else
                dp[start][end]=dp[start][end-1]+dp[start+1][end]+((str[start]==str[end])?1:-dp[start+1][end-1]);
        }
    }
    cout<<dp[0][str.length()-1];

    // memset(dp,-1,sizeof(dp));
    // cout<<solve(0,str.length()-1,str);
}