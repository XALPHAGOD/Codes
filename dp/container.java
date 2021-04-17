import java.util.*;
class container{        //similar to k transactions ???
    static int findMax(int[] arr,int s,int e){
        int maxi=arr[s];
        for(int i=s+1;i<=e;i++)
            maxi=Math.max(maxi,arr[i]);
        return maxi;
    }
    public static void main(String[] args){
        Scanner sc=new Scanner(System.in);
        int n=sc.nextInt();
        int[] arr=new int[n];
        for(int i=0;i<n;i++)
            arr[i]=sc.nextInt();
        int k=sc.nextInt();
        int[][] dp=new int[k][n];
        int fm=findMax(arr,0,n-1);
        for(int i=0;i<n;i++)
            dp[0][i]=fm;
        for(int i=2;i<=k;i++){

        }
    }
}