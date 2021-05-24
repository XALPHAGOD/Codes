#include<bits/stdc++.h>
using namespace std;


int findAbsoluteParent(int n,vector<int> &absParent){
    while(absParent[n]!=-1)        //if absParent is set as i, change -1 to n
    {
        n=absParent[n];
    }
    return n;
}


int findAbsoluteParentPathCompression(int n,vector<int> &absParent){       //use recursion
    if(absParent[n]==-1)
        return n;
    return absParent[n]=findAbsoluteParentPathCompression(absParent[n],absParent);      //path compression
}


void setUnion(int x,int y,vector<int> &absParent,vector<int> &rank){
    int absParX= findAbsoluteParentPathCompression(x,absParent);
    int absParY= findAbsoluteParentPathCompression(y,absParent);
    if(absParX==absParY)
        return;
    if(rank[absParX]==rank[absParY]){
        absParent[absParX]=absParY;
        rank[absParY]++;
    }
    else if(rank[absParX]<rank[absParY]){
        absParent[absParX]=absParY;
    }
    else{
        absParent[absParY]=absParX;
    }
}


int main(){
    int n;
    cin>>n;
    vector<int> absParent(n,-1);       //for every i can also set absParent as i
    vector<int> rank(n,0);

}