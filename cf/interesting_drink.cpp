#include <bits/stdc++.h>
using namespace std;
int main(){
    long long n;
    cin>>n;
    long long price[n];
    for(long long i=0;i<n;i++)
        cin>>price[i];
    sort(price, price+n);
    long long t, money;
    cin>>t;
    long long res[t];
    for(int i=0;i<t;i++){
        cin>>money;
        long long low=0, high=n-1, mid, pos=0;
        while(low<=high){
            mid= low+ (high-low)/2;
            if(money>=price[mid])
            {
                pos=mid+1;
                low=mid+1;
            }
            else
                high=mid-1;
        }
        res[i]=pos;
    }
    for(int x: res)
        cout<<x<<"\n";
}