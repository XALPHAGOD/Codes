import java.util.*;

public class kthpermnatural {
    static int n,k,f;
    static void solve(int[] arr,int ind,ArrayList<Integer> ans){
        if(ind==n || k==0){
            if(k==0){
                f=1;
                for(int i:arr)
                    ans.add(i);
            }
            return;
        }
        for(int i=ind;i<n;i++){
            int x=arr[ind];
            arr[ind]=arr[i];
            arr[i]=x;
            if(ind!=i)
                k--;
            solve(arr,ind+1,ans);
            if(f==1)
                return;
            arr[i]=arr[ind];
            arr[ind]=x;
        }
    }
    public static void main(String[] args){
        Scanner sc=new Scanner(System.in);
        n=sc.nextInt();
        k=sc.nextInt();
        f=0;
        int[] arr=new int[n];
        for(int i=0;i<n;i++)    
            arr[i]=i+1;
        ArrayList<Integer> ans=new ArrayList<>();
        k--;
        solve(arr,0,ans);
        System.out.println(ans);
    }
}
