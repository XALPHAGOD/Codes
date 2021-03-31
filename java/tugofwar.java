import java.util.*;
class tugofwar{
    public static int diff=Integer.MAX_VALUE;
    public static int count=0;
    public static void backtrack(int[] arr, int pos, int n, int sum, int taken, int sumtaken)
    {
        // if(pos==n)
        //     return;
        if(taken >= (n+1)/2 || pos==n){
            diff=Integer.min(diff, Math.abs(sum - 2*sumtaken));
            count++;
            System.out.println(Math.abs(sum - 2*sumtaken));
            return;
        }
        backtrack(arr, pos+1, n, sum, taken, sumtaken);
        backtrack(arr, pos+1, n, sum, taken+1, sumtaken+arr[pos]);
    }
    public static void main(String[] args)
    {
        int n;
        Scanner sc=new Scanner(System.in);
        n=sc.nextInt();
        int[] arr=new int[n];
        int sum=0;
        for(int i=0;i<n;sum+=arr[i],i++)
            arr[i]=sc.nextInt();
        // boolean[] take=new boolean[n];
        backtrack(arr, 0, n,sum, 0, 0);
        System.out.println("xxxxx"+diff+" "+count);
    }
}