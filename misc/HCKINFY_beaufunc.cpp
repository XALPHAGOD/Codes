#include<bits/stdc++.h>
using namespace std;
void beau(long long &n,long long &c)
{
    long long d=10-n%10,i;
    c+=d;
    n+=d;
    while(n%10==0)
    {
        n/=10;
    }
}
int main()
{
    long long n,c=9;
    cin>>n;
    c=(n<10)?10:9;
    while(n>9)
    {
        beau(n,c);
    }
    cout<<c-1;
}