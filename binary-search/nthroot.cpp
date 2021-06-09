#include<bits/stdc++.h>
using namespace std;
int main(){
    double n,m,p;
    cin>>n>>m>>p;
    int pr=1;
    for(int i=1;i<=p;i++)
        pr/=10;

    double low=0,high=m,mid;
    while((high-low)>pr){
        mid=low+(high-low)/2.0;
        double v=1.0;
        for(int i=1;i<=n;i++)
            v*=mid;
        if(v==m)
            break;
        else if(v>m)
            high=mid;
        else
            low=mid;
    }
    int x= ceil(mid);
    int f=1;
    for(int i=1;i<=n;i++)
        f*=x;
    if(f==m)
        cout<<x;
    else{
    pr=1;
    for(int i=1;i<=p;i++)
        pr*=10;
    int x= mid*pr;
    mid= double(x)/pr;
    cout<<mid;
    }
}