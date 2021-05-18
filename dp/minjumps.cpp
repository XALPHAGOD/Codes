#include <bits/stdc++.h>
using namespace std;
int main()
{
    int n;
    cin>>n;
    int arr[n];
    for(int i=0;i<n;i++)
        cin>>arr[i];
	
    int dp[n];
    int stepsLeft=1,mR=0,stepsRequired=0,flag=0;
    for(int i=0;i<n;i++){
        stepsLeft--;
        mR=max(mR, arr[i]+i);
        // cout<<stepsRequired<<" ";
        if(mR==i)
            break;
        if(mR>=(n-1)){
            flag=1;
            break;
        }
        if(stepsLeft==0){
            stepsLeft=mR-i;
            stepsRequired++;
        }
    }
    // cout<<"\n";
    if(flag)
        cout<<stepsRequired+1;
    else
        cout<<-1;
}