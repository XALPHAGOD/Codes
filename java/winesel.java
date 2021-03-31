import java.util.*;
class winesel {
    public static int[][] dp=new int[100][100];
    public static int c=0,m=0;
    public static int calc(int s,int e,int[] arr,int y){
        c++;
        if(s==e)
            return dp[s][e]=y*arr[s];
        if(dp[s][e]!=0)
        {
            m++;
            return dp[s][e];
        }    
        return dp[s][e]=Integer.max(y*arr[s]+calc(s+1,e,arr,y+1),y*arr[e]+calc(s,e-1,arr,y+1));
    }
    public static void main(String[] args){
        int n;
        Scanner sc=new Scanner(System.in);
        n=sc.nextInt();
        int[] wine=new int[n];
        for(int i=0;i<n;i++)
            wine[i]=sc.nextInt();

        // int[][] dp=new int[n][n];

        // for(int s=0;s<n;s++)
        // {
        //     for(int e=s+1;e<n;e++)
        //     {
        //         if(s==e)
        //         {
        //             dp[s][s]=(n-s+e)*wine[s];
        //         }
        //         else
        //         {
        //             dp[s][e]=Integer.max(dp[s+1][e]+wine[s]*(e),dp[s][e-1]+wine[e]*(e));
        //         }
        //     }
        // }

        int prof=calc(0,n-1,wine,1);

        System.out.print(prof+" "+winesel.c+" "+winesel.m);
        // System.out.print(dp[n-1][n-1]);
    }
}
