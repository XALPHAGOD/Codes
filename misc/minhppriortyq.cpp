#include<iostream>
#include<cstring>
using namespace std;
static int arr[1000],size=0;
void heapify(int pos)
{
	int smallest=pos;
	int l=2*pos+1,r=2*pos+2,t;
	if(l<size && arr[l]<arr[smallest])
		smallest=l;
	if(r<size && arr[r]<arr[smallest])
		smallest=r;
	if(smallest!=pos)
	{
		t=arr[pos];
		arr[pos]=arr[smallest];
		arr[smallest]=t;
		heapify(smallest);
	}
		
}
void ins(int val)
{
	int i;
	if(size==0)
	{
		arr[0]=val;
		size++;
	}
	else
	{
		arr[size]=val;
		size++;
		for(i=size/2 -1;i>=0;i--)
			heapify(i);	
	}
}
void del(int val)
{
	int i;
	for(i=0;i<size;i++)
	{
		if(arr[i]==val)
			break;
	}
	if(i==size)
	{
		cout<<"Element not found";
		return;
	}
	arr[i]=arr[size-1];
	size--;
	for(i=size/2 -1;i>=0;i--)
		heapify(i);
}
int main()
{
	int n,ch;
	do
	{
		cout<<"\n1 to insert\n2 to delete\n3 to see all\n4 to extract top\n5 to exit\nEnter you choice: ";
		cin>>ch;
		switch(ch)
		{
			case 1: if(size==1000)
					cout<<"Queue is full";
				else
				{
					cout<<"Enter element: ";
					cin>>n;
					ins(n);
				}
				break;
			case 2: if(size<1)
					cout<<"Queue is empty";
				else
				{
					cout<<"Enter element: ";
					cin>>n;
					del(n);
				}
				break;
			case 3: if(size<1)
					cout<<"Queue is empty";
				else
				{
					for(n=0;n<size;n++)
						cout<<arr[n]<<" ";
				}
				break;
			case 4: if(size>0)
					del(arr[0]);
				else
					cout<<"Queue is empty";
				break;
			case 5: break;
			default: cout<<"Wrong choice";
		}
	}while(ch!=5);
}