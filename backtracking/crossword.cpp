#include<bits/stdc++.h>
using namespace std;
int R,C,N;

bool canPlaceHorizontally(vector<vector<char>> &board,string word,int i,int j){
    if(j-1>=0 && board[i][j-1]!='+')
        return false;
    if((j+word.length())<C && board[i][j+word.length()]!='+')
        return false;
    if((j+word.length()-1)>=C)
        return false;
    for(int st=0;st<word.length();st++){
        if(!(board[i][j+st]=='-' || board[i][j+st]==word[st]))
            return false;
    }
    return true;
}

bool canPlaceVertically(vector<vector<char>> &board,string word,int i,int j){
    if(i-1>=0 && board[i-1][j]!='+')
        return false;
    if((i+word.length())<R && board[i+word.length()][j]!='+')
        return false;
    if((i+word.length()-1)>=R)
        return false;
    for(int st=0;st<word.length();st++){
        if(!(board[i+st][j]=='-' || board[i+st][j]==word[st]))
            return false;
    }
    return true;
}

vector<bool> placeHorizontally(vector<vector<char>> &board,string word,int i,int j){
    vector<bool> flag(word.length(),false);
    for(int st=0;st<word.length();st++){
        if(board[i][j+st]!='-')
            continue;
        flag[st]=true;
        board[i][j+st]=word[st];
    }
    return flag;
}

vector<bool> placeVertically(vector<vector<char>> &board,string word,int i,int j){
    vector<bool> flag(word.length(),false);
    for(int st=0;st<word.length();st++){
        if(board[i+st][j]!='-')
            continue;
        flag[st]=true;
        board[i+st][j]=word[st];
    }
    return flag;
}

void removeHorizontally(vector<vector<char>> &board,vector<bool> &flag,int i,int j){
    for(int st=0;st<flag.size();st++){
        if(flag[st])
            board[i][j+st]='-';
    }
}

void removeVertically(vector<vector<char>> &board,vector<bool> &flag,int i,int j){
    for(int st=0;st<flag.size();st++){
        if(flag[st])
            board[i+st][j]='-';
    }
}

void solve(vector<vector<char>> &board,string words[],int index){
    if(index==N){
        cout<<"\n\n";
        for(int i=0;i<R;cout<<"\n",i++)
            for(int j=0;j<C;j++)
                cout<<board[i][j]<<" ";
        return;
    }

    for(int i=0;i<R;i++){
        for(int j=0;j<C;j++){
            if(board[i][j]=='-' || board[i][j]==words[index][0]){
                if(canPlaceHorizontally(board,words[index],i,j)){
                    vector<bool> flag= placeHorizontally(board,words[index],i,j);
                    solve(board,words,index+1);
                    removeHorizontally(board,flag,i,j);
                }
                if(canPlaceVertically(board,words[index],i,j)){
                    vector<bool> flag= placeVertically(board,words[index],i,j);
                    solve(board,words,index+1);
                    removeVertically(board,flag,i,j);
                }
            }
        }
    }
}

int main(){
    cin>>R>>C;
    vector<vector<char>> board(R,vector<char>(C));
    for(int i=0;i<R;i++)
        for(int j=0;j<C;j++)
            cin>>board[i][j];

    cin>>N;
    char t= getchar();
    string words[N];
    for(int i=0;i<N;i++)
        getline(cin, words[i]);
    solve(board,words,0);
}