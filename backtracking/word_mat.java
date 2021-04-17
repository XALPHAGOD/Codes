import java.util.*;
public class word_mat {
    static int R,C;
    public static int solve(String s,int ind,char[][] mat,int r,int c){
        if(ind==s.length()){
            System.out.println(r+" "+c);
            return 1;
        }
        int ans=0;
        if(r-1>=0 && mat[r-1][c]==s.charAt(ind)){
            mat[r-1][c]='0';
            ans+=solve(s,ind+1,mat,r-1,c);
            mat[r-1][c]=s.charAt(ind);
        }
        if(r+1<R && mat[r+1][c]==s.charAt(ind)){
            mat[r+1][c]='0';
            ans+=solve(s,ind+1,mat,r+1,c);
            mat[r+1][c]=s.charAt(ind);
        }
        if(c-1>=0 && mat[r][c-1]==s.charAt(ind)){
            mat[r][c-1]='0';
            ans+=solve(s,ind+1,mat,r,c-1);
            mat[r][c-1]=s.charAt(ind);
        }
        if(c+1<C && mat[r][c+1]==s.charAt(ind)){
            mat[r][c+1]='0';
            ans+=solve(s,ind+1,mat,r,c+1);
            mat[r][c+1]=s.charAt(ind);
        }
        return ans;
    }
    public static void main(String[] args){
        char[][] mat={
                        {'D','D','D','G','D','D'},
                        {'B','B','D','E','B','S'},
                        {'B','S','K','E','B','K'},
                        {'D','D','D','D','D','E'},
                        {'D','D','D','D','D','E'},
                        {'D','D','D','D','D','G'}
                    };
        String s="GEEKS";
        R=mat.length;
        C=mat[0].length;
        int ans=0;
        for(int i=0;i<R;i++){
            for(int j=0;j<C;j++){
                if(mat[i][j]==s.charAt(0))
                    ans+=solve(s,1,mat,i,j);
            }
        }
        System.out.println(ans);
    }
}
