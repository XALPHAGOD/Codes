#include<bits/stdc++.h>
using namespace std;
int main(){
    string s;
    getline(cin, s);
    vector<int> freq(26, 0);
    queue<char> q;
    string res="";
    for(char ch: s){
        freq[ch-'a']++;
        if(freq[ch-'a']==1)
            q.push(ch);

        if(q.empty())
            res.push_back('#');
        else{
            while(!q.empty() && freq[q.front()-'a']>1){
                q.pop();
            }
            if(q.empty())
                res.push_back('#');
            else
                res.push_back(q.front());
        }
    }
    cout<<res;
}