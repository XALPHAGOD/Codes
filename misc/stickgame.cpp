#include<iostream>
#include<cstring>
#include<time.h>
using namespace std;
int main()
{	
	int n,x,inp;
	do
	{
		cout<<"Enter sticks(>=10): ";
		cin>>n;
	}while(n<10);
	while(true)
	{
		cout<<"Who goes first?(1 you,2 me): ";
		cin>>x;
		if(x>0 && x<3)
			break;
	}
	do
	{
		if(x==1)
		{
			while(true)
			{
				cout<<"Enter sticks from 1 to 5: ";	
				cin>>inp;
				if(inp>0 && inp<6)
					break;
			}
			x=2;	 
		}
		else
		{	
			srand(n);
			inp=1+rand()%5;
			if(n<=6)
				inp=n-1;
			else if(n<=12)
				inp=n-7;
			if(inp==1)
				cout<<"I pick 1 stick\n";
			else
				cout<<"I pick "<<inp<<" sticks\n";	
			x=1;	
		}
		n-=inp;
		cout<<"Remaining sticks= "<<n<<"\n";
	}while(n>1);
	cout<<"You Lose!!!";
}							
							
							
							