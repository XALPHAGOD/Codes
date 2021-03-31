#include<iostream>
using namespace std;

int main()
{
	int m2=2,m3=3,m5=5,i,n,x,c2=0,c3=0,c5=0;	// 1 2 3 4 5 6 8 9 10 12 15 16 18 20 24 25 27 30 32 36 40 45 48 50 54 60 64 72 75
	cout<<"Enter n: ";				//2 4 6 8 10 12 16 18 20 24 30 32 36 40 48 50 54
	cin>>n;						//3 6 9 12 15 18 24 27 30 36 45 48 54 60 72 75 81
	int res[n];					//5 10 15 20 25 30 40 45 50 60 75 80 90 100 125 135
	res[0]=1;			 
	for(i=1;i<n;i++)		
	{
		x=min(m2,min(m3,m5));
		cout<<x<<" ";
		res[i]=x;
		if(res[i]==m2)
			m2=2*res[++c2];	
		if(res[i]==m3)
			m3=3*res[++c3];
		if(res[i]==m5)
			m5=5*res[++c5];
	}
	cout<<"Result="<<res[n-1];
}
