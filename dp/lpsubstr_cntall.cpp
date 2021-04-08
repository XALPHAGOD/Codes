#include<bits/stdc++.h>
using namespace std;
int main(){
    string s;
    cin>>s;
    int c=0,maxl=0;
    for(int i=0;i<s.length();i++){
        int pre=i,nex1=i,nex2=i+1;
        while(pre>=0 && nex1<s.length()){
            if(s[pre]==s[nex1]){
                c++;
                maxl=max(maxl,nex1+1-pre);
                pre--;
                nex1++;
            }
            else{
                break;
            }
        }
        pre=i;
        while(pre>=0 && nex2<s.length()){
            if(s[pre]==s[nex2]){
                c++;
                maxl=max(maxl,nex2+1-pre);
                pre--;
                nex2++;
            }
            else{
                break;
            }
        }
    }
    cout<<c<<" "<<maxl;
}