#include<bits/stdc++.h>
using namespace std;
int main(){
    int n,k;
    cin>>n>>k;
    int h[n];
    int ind=0;
    int sum=0,mini=0;
    for(int i=0;i<n;i++){
        cin>>h[i];
        if(i<k){
            sum+=h[i];
            mini=sum;
        }
        else{
            sum+=h[i]-h[i-k];
            if(sum<mini){
                mini=sum;
                ind=i-k+1;
            }
        }
    }
    cout<<ind+1;
}