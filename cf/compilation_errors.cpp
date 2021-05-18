#include<bits/stdc++.h>
using namespace std;
int main(){
    long long n,x;
    cin>>n;
    long long e1=0,e2=0;
    for(int i=0;i<n;i++){
        cin>>x;
        e1^=x;
    }
    for(int j=0;j<n-1;j++){
        cin>>x;
        e1^=x;
        e2^=x;
    }
    for(int i=0;i<n-2;i++){
        cin>>x;
        e2^=x;
    }
    cout<<e1<<"\n"<<e2;
}