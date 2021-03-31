import java.util.*;
class n_trailzerosfact{
    public static boolean check(int n,int c){
        int cnt=0,cpy=n;
        while((n/5)>=1){
            cnt+=n/5;
            n/=5;
        }
        // System.out.println(cpy+" "+cnt);
        if(cnt>=c)
            return true;
        return false;
    }
    public static void main(String[] args){
        int n;
        Scanner sc=new Scanner(System.in);
        n=sc.nextInt();
        int low=0,high=5*n,mid;
        while(low<high){
            mid=(low+high)/2;
            if(check(mid,n))
                high=mid;
            else
                low=mid+1;
        }
        System.out.print(high);
    }
}