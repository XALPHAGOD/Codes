#include<bits/stdc++.h>
using namespace std;
int numIslands(vector<vector<char>>& grid) {
        // Code here
        int cnt=0;
        int row=grid.size();
        int col=grid[0].size();
        int dr[]={-1,-1,-1,0,0,1,1,1};
        int dc[]={-1,0,1,-1,1,-1,0,1};
        queue<pair<int,int>> q;
		int vis[row][col];
		memset(vis,0,sizeof(vis));
		for(int i=0;i<row;i++)
		{
			for(int j=0;j<col;j++)
			{
				if(grid[i][j]=='1' && vis[i][j]==0)
				{
					cnt++;
					vis[i][j]=1;
					q.push({i,j});
					while(!q.empty())
					{
						pair<int,int> x=q.front();
						q.pop();
						//vis[x.first][x.second]+=1;
						for(int k=0;k<8;k++)
						{
							int r=x.first+dr[k],c=x.second+dc[k];
							if(r>=0 && r<row && c>=0 && c<col && grid[r][c]=='1' && vis[r][c]==0)
							{
								vis[r][c]=vis[x.first][x.second]+1;
								q.push({r,c});
							}
						}
					}
				}
			}
		}
		cout<<"\n\n";
		for(int i=0;i<row;cout<<"\n",i++)
			for(int j=0;j<col;j++)
				cout<<vis[i][j]<<" ";
		cout<<"\n\n";
        return cnt;
    }
int main()
{
	int n,m;
	cin>>n>>m;
	vector<vector<char>> grid(n,vector<char>(m,'#'));
	for(int i=0;i<n;i++)
		for(int j=0;j<m;j++)
			cin>>grid[i][j];
			cout<<numIslands(grid);
}