#include<bits/stdc++.h>
using namespace std;
int main(){
    int n;
    cin>>n;
    getchar();
    vector<string> dic(n);
    string s;
    for(int i=0;i<n;dic.push_back(s),i++)
        getline(cin,s);
    getline(cin,s);
    vector<int> dp(s.length(),0);
    for(int i=0;i<s.length();i++)
    {
        for(int j=0;j<=i;j++)
        {
            // cout<<s.substr(j,i+1-j)<<"\n";
            if(find(dic.begin(), dic.end(), s.substr(j,i+1-j))!=dic.end())
            {
                // cout<<s.substr(j,i+1-j)<<"\n";
                if(j==0)
                    dp[i]=1;
                else
                    dp[i]+=dp[j-1];
            }
        }
        // cout<<dp[i]<<" ";
    }
    cout<<dp[s.length()-1];
}