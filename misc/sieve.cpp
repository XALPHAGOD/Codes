#include<bits/stdc++.h>
using namespace std;
void isprime(int n){
    if(n==0 || n==1)
        return;
    for(int i=2;i<=sqrt(n);i++)
        if(n%i==0)
            return;
    cout<<n<<" ";
}
int main(){
    int n;
    cin>>n;
    bool prime[n+1];
    memset(prime,true,sizeof(prime));
    prime[0]=prime[1]=false;
    for(int i=2;i*i<=n;i++){
        if(prime[i]){
            for(int j=i*i;j<=n;j+=i)
                prime[j]=false;
        }
    }

    for(int i=0;i<=n;i++)
        if(prime[i])
            isprime(i);
}