#include<bits/stdc++.h>
using namespace std;
bool board[1001][1001],col[1001],diag1[2001],diag2[2001];
int n,cnt;
void printBoard(){
    for(int i=0;i<n;cout<<"\n",i++)
        for(int j=0;j<n;j++)
            if(board[i][j])
                cout<<"q ";
            else
                cout<<"x ";
    cnt++;
    cout<<"\n\n";
}
void solve(int row){
    if(row==n){
        printBoard();
        return;
    }

    for(int i=0;i<n;i++){
        if(col[i] && diag1[row+i] && diag2[row-i+n-1]){
            col[i]=false;
            diag1[row+i]=false;
            diag2[row-i+n-1]=false;
            board[row][i]=true;
            solve(row+1);
            col[i]=true;
            diag1[row+i]=true;
            diag2[row-i+n-1]=true;
            board[row][i]=false;
        }
    }
}
int main(){
    cin>>n;
    memset(board,false,sizeof(board));
    memset(col,true,sizeof(col));
    memset(diag1,true,sizeof(diag1));
    memset(diag2,true,sizeof(diag2));
    cnt=0;
    solve(0);
    cout<<cnt;
}