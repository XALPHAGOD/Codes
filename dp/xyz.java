import java.util.*;

public class xyz {
    public static void main(String[] args){
        Scanner sc=new Scanner(System.in);
        int n;
        n=sc.nextInt();
        int[] arr=new int[n];
        int[] dp=new int[n+1];
        int c=0;
        for(int i=0;i<n;i++)
            arr[i]=sc.nextInt();
        dp[0]=0;
        dp[1]=arr[0];       //only 1 element
        dp[2]=arr[0]+arr[1];        //only 2 elements
        for(int i=3;i<=n;i++)
            dp[i]=Integer.max(dp[i-1]   ,Integer.max(dp[i-2] + arr[i-1]   ,dp[i-3] + arr[i-2] + arr[i-1]));     //exclude ith element or i-1 th element or i-2 th element
        System.out.println(dp[n]);
    }
}
