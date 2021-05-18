#include<bits/stdc++.h>
using namespace std;
int main(){
    int n;
    cin>>n;
    int arr[n];
    for(int i=0;i<n;i++)
        cin>>arr[i];
    int temp[n];
    
    // cout<<INT_MAX;
    // memset(temp,0x3f,sizeof(temp));
    // for(int i=0;i<n;i++){
    //     int ind=lower_bound(temp,temp+n,arr[i])-temp;
    //     temp[ind]=arr[i];
    // }
    // int i=0;
    // while(temp[i]!=1061109567){     //0x3f === 1061109567
    //     cout<<temp[i++]<<" ";
    // }

    for(int i=0;i<n;i++)
        temp[i]=INT_MAX;

    for(int i=0;i<n;i++){
        int ind=lower_bound(temp,temp+n,arr[i])-temp;
        temp[ind]=arr[i];
    }
    int i=0;
    while(temp[i]!=INT_MAX){
        cout<<temp[i++]<<" ";
    }
}