#include<bits/stdc++.h>
using namespace std;
string smlnum(int sum,int dig){
    if(sum>9*dig)
        return "-1";
    char arr[dig];
    memset(arr,'0',sizeof(arr));
    for(int i=0;i<dig;i++){
        if(sum>9){
            arr[i]=9+'0';
            sum-=9;
        }
        else{
            if(i==(dig-1)){
                arr[i]=sum+'0';
            }
            else if((dig-i)>1){
                if(sum!=1){
                    arr[i]=sum-1+'0';
                    sum=1;
                }
            }
        }
    }
    string res;
    for(int i=dig-1;i>=0;i--)
        res.push_back(arr[i]);
    return res;
}
int main(){
    int sum=20,dig=3;
    cout<<smlnum(sum,dig);
}