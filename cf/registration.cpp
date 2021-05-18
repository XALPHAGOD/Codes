#include<bits/stdc++.h>
using namespace std;
int main(){
    unordered_map<string, int> mp;
    int n;
    cin>>n;
    getchar();
    string res[n];
    for(int i=0;i<n;i++){
        string x;
        getline(cin, x);
        if(mp.find(x)==mp.end())
        {
            mp[x]=1;
            res[i]= "OK";
        }    
        else{
            res[i]= x+to_string(mp[x]);
            mp[x]++;
        }
    }
    for(int i=0;i<n;i++)
        cout<<res[i]<<"\n";
}