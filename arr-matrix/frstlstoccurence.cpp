#include <iostream>
using namespace std;

int main() {
	//code
	int t;
	cin>>t;
	while(t--)
	{
	    int n,k;
	    cin>>n>>k;
	    int a[n];
	    for(int i=0;i<n;i++)
	    {
	        cin>>a[i];
	    }
	    int fis,las,low=0,high=n-1,mid;
	    while(low<=high)
	    {
	        mid=low+(high-low)/2;
	        if(a[mid]>=k)
	        {
	            high=mid-1;
	            fis=mid;
	        }
	        else
	            low=mid+1;
	    }
	    low=0,high=n-1;
	    while(low<=high)
	    {
	        mid=low+(high-low)/2;
	        if(a[mid]<=k)
	        {
	            low=mid+1;
	            las=mid;
	        }
	        else
	            high=mid-1;
	    }
	    if(a[fis]!=k || a[las]!=k)
	        puts("-1");
	    else
	        cout<<fis<<" "<<las<<"\n";
	}
	return 0;
}