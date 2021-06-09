#include<bits/stdc++.h>
using namespace std;
string s;
int n;
vector<int> fr(26, 0);
void solve(int ind, string temp){
    if(ind==n){
        cout<<temp<<"\n";
        return;
    }
    for(int i=0;i<26;i++){
        if(fr[i]){
            fr[i]--;
            solve(ind+1, temp+(char)(i+'a'));
            fr[i]++;
        }
    }
}
int main(){
    getline(cin, s);
    n= s.length();
    for(char ch: s)
        fr[ch-'a']++;
    cout<<"\n\n";
    solve(0, "");
}