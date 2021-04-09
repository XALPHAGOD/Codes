#include<bits/stdc++.h>
using namespace std;
pair<int,int> calc(vector<int> &arr,int n){
    int maxl=0,sr=-1;
    unordered_map<int,int> mp;
    mp[0]=-1;
    pair<int,int> x;
    int s=0;
    for(int i=0;i<n;i++){
        s+=arr[i];
        if(s==0 && maxl==0)
            mp[s]=i;
        if(mp.find(s)==mp.end()){
            mp[s]=i;
        }
        else{
            maxl=max(maxl,i-mp[s]);
            sr=mp[s]+1;
        }
    }
    x.first=maxl,x.second=sr;
    return x;
}
int main(){
    int r,c,sr=-1,er=-1,sc=-1,l=-1;
    cin>>r>>c;
    int mat[r][c];
    for(int i=0;i<r;i++)
        for(int j=0;j<c;j++)
            cin>>mat[i][j];
    cout<<"\n\n";
    int mxc=0;
    for(int i=0;i<r;i++){
        vector<int> temp(c,0);
        for(int j=i;j<r;j++){
            for(int k=0;k<c;k++){
                temp[k]+=mat[j][k];
            }
            pair<int,int> val=calc(temp,c);
            if(mxc<val.first*(j-i+1)){
                mxc=val.first*(j-i+1);
                sr=i;
                er=j;
                sc=val.second;
                l=val.first;
            }
        }
    }
    // cout<<mxc;

    if(mxc<1)
        cout<<"Not Possible";
    else{
        for(int i=sr;i<=er;cout<<"\n",i++){
            for(int j=sc;j<sc+l;j++){
                cout<<mat[i][j]<<" ";
            }
        }
    }
}