#include<bits/stdc++.h>
using namespace std;
vector<string> words;
int sl,cnt=0;

void solve(int ind, string &s,string temp){
    cnt++;

    if(ind==sl){
        cout<<temp<<"\n";
        return;
    }

    string x="";
    for(int i=ind;i<sl;i++){
        x.push_back(s[i]);

        if(find(words.begin(), words.end(), x)!=words.end()){
            solve(ind+x.length(), s, temp+x+" ");
        }
    }
}
int main(){
    string s;
    getline(cin, s);

    int n;
    cin>>n;
    char x= getchar();

    for(int i=0;i<n;i++){
        string w;
        getline(cin, w);

        words.push_back(w);
    }
    cout<<"\n";
    sl= s.length();
    solve(0, s, "");
    cout<<cnt;
}