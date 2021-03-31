import java.util.*;        //Arrays.sort(arr); Arrays.sort(arr,Collections.reverseOrder()); Arrays.toString(arr);
class driver{
    public static void main(String args[])
    {
        int n,sum=0;
        Scanner sc=new Scanner(System.in);
        n=sc.nextInt();
        int a[]=new int[n];
        for(int i=0;i<n;i++)
            sum+=a[i]=sc.nextInt();
        boolean dp[][]=new boolean[n+1][sum/2+1];
        dp[0][0]=true;                      //  0 1 2 3 4 5
        for(int i=1;i<=n;i++)               //1 t t f f f f
        {                                   //2 t t t t f f
            for(int j=0;j<=sum/2;j++)       //7 t t t t f f
            {   
                dp[i][j]=dp[i-1][j];
                if(j>=a[i-1])
                    dp[i][j]|=dp[i-1][j-a[i-1]];
            }
        }

        // for(int i=0;i<=n;System.out.println(),i++)
        //     for(int j=0;j<=sum/2;j++)
        //         System.out.print(dp[i][j]+" ");

        int mini=Integer.MAX_VALUE;
        for(int i=sum/2;i>=0;i--)
            if(dp[n][i])                        //7 2 6 3 5
                mini=Integer.min(mini,sum-2*i); //7 2 4 1 9
        System.out.println(mini);
    }
}