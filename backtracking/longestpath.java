import java.util.*;
import java.util.concurrent.TimeUnit;
class longestpath{
    public static int longest=-1;
    public static int r,c,sr,sc,dr,dc;
    public static void solve(int[][] mat,int sr,int sc,int cost,boolean[][] vis){
        if(sr==dr && sc==dc){
            longest=Math.max(longest,cost);
            return;
        }

        vis[sr][sc]=true;
        if(sc+1<c && mat[sr][sc+1]!=0 && !vis[sr][sc+1])
            solve(mat,sr,sc+1,cost+1,vis);

        if(sc-1>=0 && mat[sr][sc-1]!=0 && !vis[sr][sc-1])
            solve(mat,sr,sc-1,cost+1,vis);

        if(sr+1<r && mat[sr+1][sc]!=0 && !vis[sr+1][sc])
            solve(mat,sr+1,sc,cost+1,vis);

        if(sr-1>=0 && mat[sr-1][sc]!=0 && !vis[sr-1][sc])
            solve(mat,sr-1,sc,cost+1,vis);
        vis[sr][sc]=false;
    }
    public static int findLPath(int[][] mat,int sr,int sc,int dr,int dc){
        boolean[][] vis=new boolean[r][c];
        solve(mat,sr,sc,0,vis);
        return longest;
    }
    public static void main(String[] args){
        int mat[][] ={
        { 1, 1, 1, 1, 1, 1, 1, 1, 1, 1 },
        { 1, 1, 0, 1, 1, 0, 1, 1, 0, 1 },
        { 1, 1, 1, 1, 1, 1, 1, 1, 1, 1 }
        };
        r=3;
        c=10;
        sr=0;
        sc=0;
        dr=1;
        dc=7;
        System.out.println(findLPath(mat,sr,sc,dr,dc));
    }
}