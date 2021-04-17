import java.util.*;
class inmat{
    public static void main(String[] args){
        Scanner sc=new Scanner(System.in);
        int m,n;
        m=sc.nextInt();
        n=sc.nextInt();
        int[][] inmat=new int[m][n];
        for(int i=0;i<m;i++)
            for(int j=0;j<n;j++)
                inmat[i][j]= sc.nextInt();

        int mini=Integer.MAX_VALUE,f=0;
        
        for(int i=0;i<m-3;i++){
            for(int j=0;j<n;j++){
                if(inmat[i][j]==inmat[i+1][j] && inmat[i+1][j]==inmat[i+2][j] && inmat[i+2][j]==inmat[i+3][j]){
                    f=1;
                    mini=Math.min(mini,inmat[i][j]);
                }
            }
        }
        
        for(int i=0;i<m;i++){
            for(int j=0;j<n-3;j++){
                if(inmat[i][j]==inmat[i][j+1] && inmat[i][j+1]==inmat[i][j+2] && inmat[i][j+2]==inmat[i][j+3]){
                    f=1;
                    mini=Math.min(mini,inmat[i][j]);
                }
            }
        }
        
        for(int i=0;i<m-3;i++){
            for(int j=0;j<n-3;j++){
                if(inmat[i][j]==inmat[i+1][j+1] && inmat[i+1][j+1]==inmat[i+2][j+2] && inmat[i+2][j+2]==inmat[i+3][j+3]){
                    f=1;
                    mini=Math.min(mini,inmat[i][j]);
                }
            }
        }
            
        for(int i=3;i<m;i++){
            for(int j=0;j<n-3;j++){
                if(inmat[i][j]==inmat[i-1][j+1] && inmat[i-1][j+1]==inmat[i-2][j+2] && inmat[i-2][j+2]==inmat[i-3][j+3]){
                    f=1;
                    mini=Math.min(mini,inmat[i][j]);
                }
            }
        }

        if(f==1)
            System.out.println(mini);
        else
            System.out.println(-1);
    }
}