#include<bits/stdc++.h>
using namespace std;
int main(){
    int n=10;
    int arr[n];
    for(int i=0;i<n;i++){
        arr[i]=rand() % 1000;
    }
    for(int i:arr)
        cout<<i<<" ";
    int st=0,en=n-1;
    while (st<en)
    {
        for(int i=st;i<en;i++){
            if(arr[i]>arr[i+1]){
                int t=arr[i];
                arr[i]=arr[i+1];
                arr[i+1]=t;
            }
        }
        en--;
        for(int i=en;i>st;i--){
            if(arr[i]<arr[i-1]){
                int t=arr[i];
                arr[i]=arr[i-1];
                arr[i-1]=t;
            }
        }
        st++;
    }
    cout<<"\n\n";
    for(int i:arr)
        cout<<i<<" ";
}