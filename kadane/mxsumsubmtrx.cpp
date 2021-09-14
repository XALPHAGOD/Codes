#include<bits/stdc++.h>
using namespace std;
int main(){
    int r,c;
    cin>>r>>c;
    int mat[r][c];
    for(int i=0;i<r;i++)
        for(int j=0;j<c;j++)
            cin>>mat[i][j];

    int temp[c];
    int ms=INT_MIN,sr=-1,sc=-1,er=-1,ec=-1;

    for(int l=0;l<r;l++){
        memset(temp,0,sizeof(temp));

        for(int lr=l;lr<r;lr++){
            int meh=0,msf=INT_MIN,tsc=0;

            for(int x=0;x<c;x++)
            {
                temp[x]+=mat[lr][x];

                meh+=temp[x];
                if(meh<temp[x])
                {
                    meh=temp[x];
                    tsc=x;
                }

                if(msf<meh)
                    msf=meh;
                
                if(ms<msf){
                    ms=msf;
                    sr=l;
                    er=lr;
                    sc=tsc;
                    ec=x;
                }
            }
        }
    }

    for(int i=sr;i<=er;cout<<"\n",i++)
        for(int j=sc;j<=ec;j++)
            cout<<mat[i][j]<<" ";

    cout<<ms;
}