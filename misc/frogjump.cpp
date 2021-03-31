#include <bits/stdc++.h>
using namespace std;
int main()
{
	int t;
	cin>>t;
	while(t--)	
	{
		int n,jmps=0,minj; 
		cin>>n;
		int wt[n],l[n],pos[n];
		for(int i=0;i<n;pos[wt[i]-1]=i,i++)cin>>wt[i];
		for(int i=0;i<n;i++)cin>>l[wt[i]-1];
		
			
		for(int i=1;i<n;i++)
		{
			if(pos[i]<=pos[i-1])
			{
				minj=(pos[i-1]-pos[i])/l[i]+1;
				jmps+=minj;
				pos[i]+=minj*l[i];
			}	
		}

		/*for(int i=0;i<n;i++)cout<<pos[i]<<" ";
		cout<<"\n\n";*/
		cout<<jmps<<endl;
	}		
}
