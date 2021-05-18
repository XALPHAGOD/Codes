#include <bits/stdc++.h>
using namespace std;
int count_bits(int n){
    int bits=0;
    while(n){
        bits++;
        n&=n-1;
    }
    return bits;
}
int main(){
    int n;
    cin>>n;
    cout<<count_bits(n);
}