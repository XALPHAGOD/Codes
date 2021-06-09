#include<bits/stdc++.h>
using namespace std;
int main(){
    int n;
    cin>>n;

    vector<pair<int,int>> arr;
    int x, y, dp[n], maxi=1;

    for(int i=0;i<n;dp[i]=1, i++){
        cin>>x>>y;
        arr.push_back({x,y});
    }

    sort(arr.begin(), arr.end());

    for(int i=1;i<n;i++){
        for(int j=i-1;j>=0;j--){
            if(arr[j].second<arr[i].second){
                dp[i]= max(dp[i], dp[j]+1);
                maxi= max(maxi, dp[i]);
            }
        }
    }

    for(int i=0;i<n;i++)
        cout<<dp[i]<<" ";

    cout<<"\n";

    cout<<maxi;
}