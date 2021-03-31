import java.util.*;
class subseqprodlessk{
    public static void main(String[] args){
        int n,k;
        Scanner sc=new Scanner(System.in);
        n=sc.nextInt();
        k=sc.nextInt();
        int c=0;
        int[] arr=new int[n];
        for(int i=0;i<n;i++)
            arr[i]=sc.nextInt();

        int[][] dp=new int[k+1][n+1];       //product 1,2,3,....k possible or not

        for(int i=1;i<=k;i++)
        {
            for(int j=1;j<=n;j++)
            {
                dp[i][j]=dp[i][j-1];
                if(arr[j-1]<=i)
                    dp[i][j]+= dp[i/arr[j-1]][j-1] + 1;
            }

        }
        System.out.println(dp[k][n]);
    }
}