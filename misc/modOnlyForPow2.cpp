#include<bits/stdc++.h>
using namespace std;
int main(){
    int val,size;
    cin>>val>>size;
    cout<<(val%size)<<" "<<(val & (size-1));        //only for size=2^p
}