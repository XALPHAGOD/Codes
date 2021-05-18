#include <bits/stdc++.h>
using namespace std;
int main(){
    int n;
    cin>>n;
    int fr[5];
    memset(fr,0,sizeof(fr));
    for(int i=0;i<n;i++)
    {
        int x;
        cin>>x;
        fr[x]++;
    }
    int cnt=fr[4]+fr[3]+fr[2]/2;
    fr[1]-=(fr[1]>fr[3])?fr[3]:fr[1];
    fr[2]%=2;
    if(fr[2])
    {
        cnt++;
        fr[1]-=(fr[1]>2)?2:fr[1];
    }
    cnt+=fr[1]/4;
    if(fr[1]%4)
        cnt++;
    cout<<cnt;
}