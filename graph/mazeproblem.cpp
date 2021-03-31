#include<iostream>
#include<cstring>
using namespace std;

static int R, C, SR, SC, ER, EC, r_rear=-1, r_front=0, c_rear=-1, c_front=0, SIZE=0, nodesleft=1, nodesnext=0, count=0;

static char mat[20][20];

static int rq[400], cq[400], rp[20][20], cp[20][20], pt[20][20];

bool visited[20][20], reached=false;

int rn[]={-1,+1,0,0};
int cn[]={0,0,+1,-1};

void renqueue(int val)
{
	rq[++r_rear]=val;
	SIZE++;	
}
void cenqueue(int val)
{
	cq[++c_rear]=val;	
}
int rdequeue()
{
	int x=rq[r_front++];
	SIZE--;
	return x;
}
int cdequeue()
{
	int x=cq[c_front++];
	return x;
}

void explore_neighbours(int r,int c)
{
	int i,rr,cc;
	for(i=0;i<4;i++)
	{
		rr=r+rn[i];
		cc=c+cn[i];
		
		if(rr<0 || rr>=R || cc<0 || cc>=C)
			continue;
	
		if(visited[rr][cc]==1)
			continue;
		
		if(mat[rr][cc]=='#')
			continue;
		
		rp[rr][cc]=r;
		cp[rr][cc]=c;
		renqueue(rr);
		cenqueue(cc);
		visited[rr][cc]=1;
		nodesnext++;	
	}
}

int solve()
{
	memset(visited,0,sizeof(visited));
	memset(rp,-1,sizeof(rp));
	memset(cp,-1,sizeof(cp));

	renqueue(SR);
	cenqueue(SC);
	visited[SR][SC]=1;
	
	int r,c;

	while(SIZE>0)
	{
		r=rdequeue();
		c=cdequeue();

		if(mat[r][c]=='e')
		{
			ER=r;
			EC=c;
			reached=true;
			break;
		}

		explore_neighbours(r,c);

		nodesleft--;
		if(nodesleft==0)
		{
			nodesleft=nodesnext;
			nodesnext=0;
			count++;	
		}		
	}
	if(reached)
		return count;
	return -1;
}

void findpath()
{
	memset(pt,0,sizeof(pt));
	int tr=ER,tc=EC,ta,tb;
	while(true)
	{
		if(tr==SR && tc==SC)
			break;
		pt[tr][tc]=1;
		ta=rp[tr][tc];
		tb=cp[tr][tc];
		tr=ta,tc=tb;
	}
	for(tr=0;tr<R;cout<<"\n",tr++)
		for(tc=0;tc<C;tc++)
		{
			if(mat[tr][tc]=='s' || mat[tr][tc]=='e' || mat[tr][tc]=='#')
				cout<<mat[tr][tc];
			else if(pt[tr][tc]!=0)
				cout<<"-";
			else 
				cout<<"x";
		}
}		

int main()
{	
	string s;
	int i,j;
	cout<<"Enter rows and columns: ";
	cin>>R>>C;
	cout<<"s for source, e for exit, # for wall, - for empty path \n";
	cout<<"Enter maze:\n";
	getline(cin,s);
	for(i=0;i<R;i++)
	{
		getline(cin,s);
		for(j=0;j<C;j++)
		{	
			mat[i][j]=s[j];
			if(mat[i][j]=='s')
			{
				SR=i;
				SC=j;
			}
	 	}
	}

	int ans=solve();
	cout<<"Ans= "<<ans<<"\nPath:\n";
	if(ans>0)
		findpath();	
}