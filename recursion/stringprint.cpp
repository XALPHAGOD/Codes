#include <bits/stdc++.h>
using namespace std;
void printString(string s,int index,string temp,int cnt){
    if(index==s.length()){
        if(cnt)
            cout<<temp<<cnt<<"\n";
        else
            cout<<temp<<"\n";
        return;
    }
    if(cnt)
        printString(s,index+1,temp+(char)(cnt+'0')+s[index],0);
    else
        printString(s,index+1,temp+s[index],cnt);
    
    
    printString(s,index+1,temp,cnt+1);
}
int main(){
    string s;
    getline(cin,s);
    string temp="";
    printString(s,0,temp,0);
}