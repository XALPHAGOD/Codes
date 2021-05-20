#include<bits/stdc++.h>
using namespace std;
void swap(int arr[],int i,int j){
    int t=arr[i];
    arr[i]=arr[j];
    arr[j]=t;
}
void Sort(int arr[],int n){
    int i=0,j=n-1;
    while(i<j){
        if(abs(arr[i])>=abs(arr[i+1])){
            if(abs(arr[i])>abs(arr[j])){
                swap(arr,i,j);
            }
        }
        else{
            swap(arr,i,i+1);
            if(abs(arr[i])>abs(arr[j])){
                swap(arr,i,j);
            }
            else
            {
                swap(arr,i,i+1);
                i++;
            }
        }
        j--;
    }
    for(int i=0;i<n;i++)
        cout<<arr[i]<<" ";
}
int main(){
    int n;
    cin>>n;
    int arr[n];
    for(int i=0;i<n;i++)
        cin>>arr[i];
    Sort(arr,n);
}