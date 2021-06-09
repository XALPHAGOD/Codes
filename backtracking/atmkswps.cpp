#include<bits/stdc++.h>
using namespace std;
string s, maxi;
int n, cnt1=0, cnt2=0;
void setmaxi(){
    for(int i=0;i<n;i++){
        if(maxi[i]<s[i])
        {
            maxi= s;
            return;
        }
    }
}
void solve(int ind, int k){
    cnt1++;
    setmaxi();
    if(ind==n || k==0)
        return;
    cnt2++;

    solve(ind+1, k);
    for(int i=ind+1;i<n;i++){
        if(s[ind]<s[i]){
            swap(s[ind], s[i]);
            solve(ind+1, k-1);
            swap(s[ind], s[i]);
        }
    }
}
int main(){
    getline(cin, s);
    maxi= s;
    n= s.length();
    int k;
    cin>>k;
    solve(0, k);
    cout<<"\n\n"<<maxi<<"\n"<<cnt1<<" "<<cnt2;
}