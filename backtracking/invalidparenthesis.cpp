// use unordered_map for increased perform
#include<bits/stdc++.h>
using namespace std;
string s;
int n;
int getrem(string t){
    stack<char> st;
    for(char x: t){
        if(x=='(')
            st.push(x);
        else{
            if(st.size()==0 || st.top()==')')
                st.push(x);
            else
                st.pop();
        }
    }
    return st.size();
}

void solve(int ind, int rem, string t){
    if(ind==n || rem==0){
        if(rem)
            return;
        for(int i=ind;i<n;i++)
            t.push_back(s[i]);
        if(getrem(t))
            return;
        cout<<t<<"\n";
        return;
    }
    string x= "";
    for(int i=ind;i<n;i++){
        solve(i+1, rem-1, t+x);
        x.push_back(s[i]);
    }
}
int main(){
    getline(cin, s);
    n= s.length();
    int minrem= getrem(s);
    solve(0, minrem, "");
}