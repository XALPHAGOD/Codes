#include<bits/stdc++.h>
using namespace std;
int main(){
    int m,n;
    cin>>m>>n;
    int arr[m][n];
    for(int i=0;i<m;i++)
        for(int j=0;j<n;j++)
            cin>>arr[i][j];

    int maxi=0;
    for(int col=n-2;col>=0;col--)
    {
        for(int row=0;row<m;row++)
        {
            if(row==0)
            {
                arr[row][col]+=max(arr[row][col+1],arr[row+1][col+1]);
            }
            else if(row==(m-1))
            {
                arr[row][col]+=max(arr[row][col+1],arr[row-1][col+1]);
            }
            else
            {
                arr[row][col]+=max({arr[row-1][col+1],arr[row][col+1],arr[row+1][col+1]});
            }
            if(col==0)
                maxi=max(maxi,arr[row][0]);
        }
    }
    cout<<maxi;
}