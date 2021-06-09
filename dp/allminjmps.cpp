#include<bits/stdc++.h>
using namespace std;

int n;

int main(){
    cin>>n;

    vector<int> arr(n), dp(n,INT_MAX);

    for(int i=0;i<n;i++)
        cin>>arr[i];

    int ind=0, pmr=0, mr=0, steps=1;
    while(ind<=mr && ind<n){
        dp[ind]=steps;
        mr=max(mr,ind+arr[ind]);
        if(ind==pmr){
            if(mr>=n)
                break;
            steps++;
            pmr=mr;
        }
        ind++;
    }

    // cout<<steps<<" "<<ind<<"\n";

    // for(int x:dp)
    //     cout<<x<<" ";
    // cout<<"\n";

    queue<pair<int,string>> q;
    q.push({0,""});

    while (!q.empty())
    {
        pair<int,string> x=q.front();
        q.pop();

        if(x.first>=(n-1)){
            cout<<x.second<<n-1<<"\n";
            continue;
        }

        for(int i=x.first+1;i<=x.first+arr[x.first] && i<n;i++){
            if(dp[i]>dp[x.first]){
                q.push({i,x.second+to_string(x.first)+"->"});
            }
        }
    }
    
}