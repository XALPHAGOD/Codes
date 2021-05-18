#include<bits/stdc++.h>
using namespace std;
int main(){
    int n;
    cin>>n;
    int arr[n];
    int arrsum=0;
    for(int i=0;i<n;arrsum+=arr[i],i++)
        cin>>arr[i];
    int withdraw;
    cin>>withdraw;
    int reqsum=arrsum-withdraw;

    int sum=0;
    int st=0,en=-1;
    int ind=0;
    bool flag=false;
    int cnt=n+1;
    while(ind<n){
        sum+=arr[ind];
        if(sum>reqsum){
            while(sum>reqsum){
                sum-=arr[st++];
            }
        }
        if(sum<=reqsum){
            en=ind;
            if(sum==reqsum){
                flag=true;
                cnt=min(cnt,n-(en-st+1));
            }
        }
        ind++;
        // cout<<sum<<" "<<st<<" "<<en<<" "<<cnt<<"\n";
    }
    if(flag)
        cout<<cnt;
    else
        cout<<-1;
}