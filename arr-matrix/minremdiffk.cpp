#include<bits/stdc++.h>
using namespace std;
int check(int arr[], int low, int high, int key, int k){
    int mid, pos= low-1;
    while(low<=high){
        mid= low+ (high-low)/2;
        if(arr[mid]-key<=k){
            pos= mid;
            low= mid+1;
        } 
        else
            high=mid-1;
        // cout<<arr[mid]<<" "<<low<<" "<<pos<<"\n";
    }
    return pos;
}
int main(){
    int n,k;
    cin>>n>>k;
    int arr[n];
    for(int i=0;i<n;i++)
    {
        cin>>arr[i];
    }
    sort(arr,arr+n);
    int mini= n;
    // cout<<check(arr, 2, n-1, 3, 0);
    for(int i=0;i<n-1;i++){
        int temp=check(arr,i+1,n-1,arr[i],k);
        if(temp!=i)
            mini=min(mini,n-(temp-i+1));
        // cout<<temp<<" ";
    }
    cout<<mini;
}