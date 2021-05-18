#include<bits/stdc++.h>
using namespace std;
int main(){
    long long n,l;
    cin>>n>>l;
    vector<long long> arr;
    for(int i=0;i<n;i++)
    {
        long long x;
        cin>>x;
        arr.push_back(x);
    }
    sort(arr.begin(), arr.end());
    double maxi=max(arr[0], l-arr[n-1]);
    for(int i=1;i<n;i++)
        maxi=max(maxi, (arr[i]-arr[i-1])/2.0);
    printf("%.10lf\n",maxi);        //puta
}