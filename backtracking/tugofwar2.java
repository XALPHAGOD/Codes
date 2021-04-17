import java.util.*;

class tugofwar2
{
    public static int n,diff,sum,cnt;
    public static boolean[] poss;

    public static void copy(boolean[] flag,int n){
        for(int i=0;i<n;i++)
            poss[i]=flag[i];
    }
    public static void solve(int[] arr,int ind,int taken,int takensum,boolean[] flag){
        if(ind==n)
            return;
        
        if((n-ind)<((n+1)/2-taken))     //rem elems < elems reqd to be taken
            return;

        if(taken==(n+1)/2){
            if(Math.abs(sum-2*takensum)<diff)
            {
                diff=Math.abs(sum-2*takensum);
                copy(flag,n);
            }
            return;
        }
        cnt++;

        solve(arr,ind+1,taken,takensum,flag);       //curr elem not included

        flag[ind]=true;
        solve(arr,ind+1,taken+1,takensum+arr[ind],flag);        //curr elem included
        flag[ind]=false;
    }

    public static void main(String args[])
    {   
        Scanner sc=new Scanner(System.in);
        cnt=0;
        diff=Integer.MAX_VALUE;
        sum=0;

        n=sc.nextInt();
        int[] arr=new int[n];
        for(int i=0;i<n;sum+=arr[i],i++)
            arr[i]=sc.nextInt();

        poss=new boolean[n];
        boolean[] flag=new boolean[n];

        int ind=0,taken=0,takensum=0;
        solve(arr,ind,taken,takensum,flag);

        for(int i=0;i<n;i++)
            if(poss[i])
                System.out.print(arr[i]+" ");
        System.out.println();
        for(int i=0;i<n;i++)
            if(!poss[i])
             System.out.print(arr[i]+" ");
        System.out.println();        
        System.out.println(diff+" "+cnt);
    }
}