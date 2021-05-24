#include<bits/stdc++.h>
using namespace std;
int n,k,totsum;
bool flag=false;
void solve(int ind,vector<int> &arr,vector<pair<int,vector<int>>> &sums){
    if(ind==n){
        int cnt=0;
        for(int i=0;i<k;i++)
            if(sums[i].first==totsum)
                cnt++;

        if(cnt!=k)
            return;
        flag=true;
        for(int i=0;i<k;i++){
            for(int x:sums[i].second)
                cout<<x<<" ";
            if(i!=(k-1))
                cout<<"| ";
        }
        cout<<"\n";
        return;
    }

    for(int i=0;i<k;i++){
        if(sums[i].first==0){
            sums[i].first+=arr[ind];
            sums[i].second.push_back(arr[ind]);
            solve(ind+1,arr,sums);
            sums[i].first-=arr[ind];
            sums[i].second.pop_back();
            break;    
        }
        sums[i].first+=arr[ind];
        sums[i].second.push_back(arr[ind]);
        solve(ind+1,arr,sums);
        sums[i].first-=arr[ind];
        sums[i].second.pop_back();
    }
}
int main(){
    cin>>n>>k;
    vector<int> arr(n);
    totsum=0;
    for(int i=0;i<n;totsum+=arr[i],i++)
        cin>>arr[i];
    if(totsum%k || k>n)
    {
        cout<<-1;
        return 0;
    }
    if(k==1)
    {
        for(int i=0;i<n;i++)
            cout<<arr[i]<<" ";
        return 0;
    }
    totsum/=k;
    vector<pair<int,vector<int>>> sums(k);
    solve(0,arr,sums);
}