int findLongestConseqSubseq(int arr[], int n)
{
    vector<int> m(100001,0);
    int ml=-1;
    for(int i=0;i<n;i++)
    {
        m[arr[i]]=1;
        ml=max(ml,arr[i]);
    }
    int i=0,maxi=1,curr=0;
    while(i<=ml)
    {
        while(i<=ml && m[i])
        {
            i++;
            curr++;
        }
        maxi=max(maxi,curr);
        curr=0;
        while(i<=ml && !m[i])
        {
            i++;
        }
    }
    return maxi;
  //Your code here
}