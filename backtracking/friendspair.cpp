#include<bits/stdc++.h>
using namespace std;
int n,cnt=0,cnt1=0;
void solve(int ind,vector<vector<int>> &pairs){
    cnt++;
    if(ind==n){
        for(int i=0;i<n;i++){
            if(pairs[i].size()==0)
                break;
            cout<<"(";
            for(int x=0;x<pairs[i].size();x++){
                if(x==pairs[i].size()-1)
                {
                    cout<<pairs[i][x];
                    break;
                }
                cout<<pairs[i][x]<<",";
            }
            cout<<") ";
        }
        cout<<"\n";
        return;
    }
    for(int i=0;i<n;i++){
        if(pairs[i].size()==2)
            continue;
        if(pairs[i].size()==0){
            pairs[i].push_back(ind+1);
            solve(ind+1,pairs);
            pairs[i].pop_back();
            break;
        }
        pairs[i].push_back(ind+1);
        solve(ind+1,pairs);
        pairs[i].pop_back();
    }
    cnt1++;
}
int main(){
    cin>>n;
    vector<vector<int>> pairs(n);
    solve(0,pairs);
    cout<<cnt<<" "<<cnt1;
}