import java.util.*;

public class allpaths {
    public static ArrayList<ArrayList<Integer>> ans;
    public static int r,c,cnt=0;
    public static void solve(int[][] mat,int mr,int mc,ArrayList<Integer> temp){
        if(mr==r && mc==c){
            ans.add(temp);
            return;
        }
        if(mr==r-1){
            ArrayList<Integer> x=new ArrayList<>(temp);
            for(int i=mc;i<c;i++){
                x.add(mat[mr][i]);
            }
            ans.add(x);
            cnt++;
            return;
        }
        if(mc==c-1){
            ArrayList<Integer> x=new ArrayList<>(temp);
            for(int i=mr;i<r;i++){
                x.add(mat[i][mc]);
            }
            ans.add(x);
            cnt++;
            return;
        }

        temp.add(mat[mr][mc]);
        solve(mat,mr,mc+1,temp);
        solve(mat,mr+1,mc,temp);
        temp.remove(temp.size()-1);
    }
    public static void main(String[] args){
        
        int mat[][] = { { 1, 2 },
                        { 4, 5 } };
        ans=new ArrayList<ArrayList<Integer>>();
        ArrayList<Integer> temp=new ArrayList<>();
        r=2;
        c=2;
        solve(mat,0,0,temp);
        System.out.println(ans);
        System.out.println(cnt);
    }
    
}
