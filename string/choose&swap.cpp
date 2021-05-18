#include<bits/stdc++.h>
using namespace std;
string chooseandswap(string str){

        bool fl[26],exists[26];
        memset(exists,false,sizeof(exists));

        for(char x:str)
            exists[x-'a']=true;

        // for(int i=0;i<26;i++)
        //     cout<<exists[i]<<" ";

        memset(fl,true,sizeof(fl));

        bool found=false;
        char x,y;
        
        for(int i=0;i<str.length();i++){
            if(fl[str[i]-'a']){
                for(int j=(str[i]-'a')-1;j>=0;j--){
                    if(exists[j] && fl[j]){
                        found=true;
                        x=str[i];
                        y='a'+j;
                    }
                }
                fl[str[i]-'a']=false;
            }
            if(found)
                break;
        }

        // cout<<x<<" "<<y<<" "<<found<<" ";
        
        for(int i=0;i<str.length();i++)
        {
            if(str[i]==x)
                str[i]=y;
            else if(str[i]==y)
                str[i]=x;
        }
        return str;
}
int main(){
    string s;
    getline(cin,s);
    cout<<chooseandswap(s);
}