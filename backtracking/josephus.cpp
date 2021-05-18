#include<bits/stdc++.h>
using namespace std;
int solve(int n,int k){
    if(n==1)
        return 0;
    return (solve(n-1,k)+k)%n;
}
int  main(){
    int n,k;
    cin>>n>>k;
    cout<<solve(n,k)+1;
}