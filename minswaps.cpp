int minSwap(int *arr, int n, int k) {
    // Complet the function
    int i,j,mini=n,ls=0,gr=0;
    for(i=0;i<n;i++)
        if(arr[i]<=k)
            ls++;
    
    
    for(i=0;i<ls;i++)
        if(arr[i]>k)
            gr++;
    i=0,j=ls-1;
    while(j<n)
    {
        mini=min(mini,gr);
        j++;
        if(arr[j]>k)gr++;
        if(arr[i]>k)gr--;
        i++;
    }
    return mini;
}