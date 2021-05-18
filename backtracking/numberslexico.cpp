#include<bits/stdc++.h>
using namespace std;
void solve(int cur,int n){
    if(cur>n)
        return;
    cout<<cur<<"\n";
    for(int i=0;i<10;i++)
        solve(cur*10+i,n);
}
int main(){
    int n=200;
    for(int i=1;i<10;i++)
        solve(i,n);
}