import java.util.*;

public class boxweights {
    public static void main(String[] args){
        Scanner sc=new Scanner(System.in);
        int n=sc.nextInt();
        int[] arr=new int[n];
        int[] presum=new int[n];
        for(int i=0;i<n;i++)
            arr[i]=sc.nextInt();
        Arrays.sort(arr);
        presum[0]=arr[0];
        for(int i=1;i<n;i++)
            presum[i]=arr[i]+presum[i-1];    
        int sum=presum[n-1];
        int low=0,high=n-1,mid;
        while(low<=high){
            mid= low+ (high-low)/2;
            if(presum[mid]<sum-presum[mid]){
                low=mid+1;
            }
            else{
                high=mid-1;
            }
        }
        if(low!=0){
            for(int i=low;i<n;i++)
                System.out.print(arr[i]+" ");
            System.out.println();
        }
        else
            System.out.println("Not Possible");
    }
    
}
