import java.util.*;
class cntpalsubstrs{
    public static void main(String[] args){
        Scanner sc=new Scanner(System.in);
        String s=sc.nextLine();
        int n=s.length();
        int[][] dp=new int[n][n];
        int maxl=1,strstart=0,cnt=n;
        for(int gap=0;gap<n;gap++){
            for(int i=0,j=gap;j<n;i++,j++){
                if(gap==0)
                    dp[i][j]=1;
                else if(gap==1){
                    if(s.charAt(i)==s.charAt(j))
                    {
                        dp[i][j]=1;
                        cnt++;
                        if(maxl<j-i+1){
                            maxl=j-i+1;
                           strstart= i;
                        }
                    }    
                    else
                        dp[i][j]=0;
                }
                else{
                    if(s.charAt(i)==s.charAt(j) && dp[i+1][j-1]>0)
                    {
                        dp[i][j]=1+dp[i+1][j-1];
                        cnt++;
                        if(maxl<j-i+1){
                            maxl=j-i+1;
                           strstart= i;
                        }
                    }
                    else
                        dp[i][j]=0;
                }
            }
        }
        System.out.println(cnt+" "+s.substring(strstart,strstart+maxl));
    }
}