#include<bits/stdc++.h>
using namespace std;
bool prime[1000001];
void sieve()
{
    prime[0]=prime[1]=1;
    for(int i=2;i*i<=1000000;i++)
    {
        if(!prime[i])
        {
            for(int j=i*i;j<=1000000;j+=i)
                prime[j]=1;
        }
    }   
}
int gcd(int a,int b)
{
    if(b==0)
        return a;
    return gcd(b,a%b);
}
int main()
{
    sieve();
    int a,b,m;
    cin>>a>>b;
    int fl=gcd(a,b);
    int f1=a/fl,f2=b/fl,st=0;
    int cf1=f1,cf2=f2;
    for(int i=2;i<=f1;i++)
    {
        if(cf1>1 && !prime[i])
        {
            while(cf1%i==0)
            {
                cf1/=i;
                st++;
            }
        }
        if(cf1<=1)
            break;
    }
    for(int i=2;i<=f2;i++)
    {
        if(cf2>1 && !prime[i])
        {
            while(cf2%i==0)
            {
                cf2/=i;
                st++;
            }
        }
        if(cf2<=1)
            break;
    }
    cout<<st<<" "<<fl;
}