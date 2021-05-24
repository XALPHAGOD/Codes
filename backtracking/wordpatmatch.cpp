#include<bits/stdc++.h>
using namespace std;
string mp[26];
int sl,pl,crx1=0,crx2=0;
void solve(int strind,int patind,string &str,string &pat){
    crx1++;
    if((strind==sl && patind!=pl)||(strind!=sl && patind==pl))
        return;
    if(strind==sl && patind==pl){
        for(int i=0;i<26;i++)
            if(mp[i]!="#")
                cout<<(char)(i+'a')<<"-> "<<mp[i]<<"   ";
        
        cout<<"\n";
        return;
    }

    string prev=mp[pat[patind]-'a'];
    // cout<<pat[patind]<<mp[pat[patind]-'a']<<" ";
    if(prev!="#"){
        if((sl-strind)<prev.length())
            return;
        for(int i=0;i<prev.length();i++){
            if(str[strind+i]!=prev[i])
                return;
        }
        // cout<<"x";
        solve(strind+prev.length(),patind+1,str,pat);
    }
    else{
        string t="";
        for(int i=strind;i<sl;i++){
            t.push_back(str[i]);
            mp[pat[patind]-'a']=t;
            solve(i+1,patind+1,str,pat);
        }
        mp[pat[patind]-'a']=prev;
    }
    crx2++;
}
int main(){
    string str,pat;
    getline(cin,str);
    getline(cin,pat);
    sl=str.length();
    pl=pat.length();
    // cout<<str<<sl<<pat<<pl;
    for(int i=0;i<26;i++)
        mp[i]="#";
    solve(0,0,str,pat);
    cout<<crx1<<" "<<crx2;
}