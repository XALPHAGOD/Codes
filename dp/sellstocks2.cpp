#include<bits/stdc++.h>
using namespace std;
int main(){
    int n;
    cin>>n;
    int arr[n];
    for(int i=0;i<n;i++)
        cin>>arr[i];
    
    int maxprof=0;
    int prof[n];
    prof[n-1]=0;
    int maxele=arr[n-1];
    for(int i=n-2;i>=0;i--){
        if(maxele<arr[i])
            maxele=arr[i];
        prof[i]=max(prof[i+1],maxele-arr[i]);       //if buy at arr[i] or max trans after
        maxprof=max(maxprof,prof[i]);
    }
    int minele=arr[0];
    for(int i=1;i<n-1;i++){
        if(minele>arr[i])
            minele=arr[i];
        prof[i]=max(prof[i-1],prof[i]+arr[i]-minele);     //sell at arr[i]
        maxprof=max(maxprof,prof[i]);
    }
    cout<<maxprof;
}