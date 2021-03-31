long long merge(long long a[],long long l,long long m,long long r)
{
    long long c=0;
    long long i,j,k;
    long long ls=m-l+1,rs=r-m;
    long long m1[ls],m2[rs];
    for(i=0;i<ls;i++)
        m1[i]=a[i+l];
    for(i=0;i<rs;i++)
        m2[i]=a[i+m+1];
    i=0,j=0,k=l;
    while(i<ls && j<rs)
    {
        if(m1[i]<=m2[j])
            a[k]=m1[i++];
        else
        {
            a[k]=m2[j++];
            c+=ls-i;
        }
        k++;
    }
    while(i<ls)
    {
        a[k++]=m1[i++];
    }
    while(j<rs)
    {
        a[k++]=m2[j++];
    }
    return c;
}
long long partition(long long a[],long long l,long long r)
{
    long long c=0;
    if(l<r)
    {
        int mid=(l+r)/2;
        c+=partition(a,l,mid);
        c+=partition(a,mid+1,r);
        c+=merge(a,l,mid,r);
    }
    return c;
}

long long int inversionCount(long long a[], long long n)
{
    if(n<2)
        return 0;
    return partition(a,0,n-1);
}