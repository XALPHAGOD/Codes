#include<bits/stdc++.h>
using namespace std;

string a,b,c;
bool taken[10];
unordered_map<char,int> mp;
vector<char> vec;
int N;

int check(string s){
    int val=0;
    for(char c:s)
        val=val*10+mp[c];
    return val;
}

void solve(int index){
    if(index==N){
        if((check(a)+check(b))==check(c))
        {
            cout<<"\n";
            for(int i=0;i<N;i++)
                cout<<vec[i]<<mp[vec[i]]<<" ";
        }
        return;
    }
    for(int i=0;i<=9;i++){
        if(!taken[i]){
            taken[i]=true;
            mp[vec[index]]=i;
            solve(index+1);
            mp[vec[index]]=-1;
            taken[i]=false;
        }
    }
}

int main(){
    getline(cin,a);
    getline(cin,b);
    getline(cin,c);
    set<char> st;
    for(char ch:a)
        st.insert(ch);
    for(char ch:b)
        st.insert(ch);
    for(char ch:c)
        st.insert(ch);
    if(st.size()>10)
        puts("Not Possible");
    else
    {
        for(auto x:st){
            vec.push_back(x);
            mp[x]=-1;
        }
        N=vec.size();
        solve(0);
    }
}