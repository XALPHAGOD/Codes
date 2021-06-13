#include<bits/stdc++.h>
using namespace std;

int main(){

    string s;
    getline(cin,s);
    int data[26];
    memset(data,0,sizeof(data));

    long long dp[s.length()];

    dp[0]=2;
    long long prev=2,cur;
    data[s[0]-'a']=1;

    for(int i=1;i<s.length();i++){
        // dp[i]=dp[i-1]*2-data[s[i]-'a'];
        // data[s[i]-'a']=dp[i-1];

        cur=prev*2-data[s[i]-'a'];
        data[s[i]-'a']=prev;
        prev=cur;

    }

    // for(int i=0;i<s.length();i++)
    //     cout<<dp[i]<<" ";
    //     cout<<"\n";
    // cout<<dp[s.length()-1];
       
    cout<<cur;
}