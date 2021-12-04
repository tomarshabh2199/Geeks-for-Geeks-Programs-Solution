//Initial Template for Java
import java.util.*;
import java.io.*;
import java.lang.*;

 // } Driver Code Ends
//User function Template for Java
class Solution
{
    static long dp[];
    static long driver(int n){
        if(dp[n]!=0){
             return dp[n];
        }
     long sum=0;
     for(int i=1;i<=n;i++){
         sum+=((driver(i-1))*(driver(n-i)))%1000000007;
       }
        dp[n]=sum%1000000007;
        return dp[n];
}

static int numTrees(int n)
{
    dp=new long[n+1];
    Arrays.fill(dp,0);

   if(n==0 || n==1){
       return 1;
     }
   else{
        dp[0]=1;
        dp[1]=1;

    int sum=0;
    return (int)driver(n);
//return sum;
}
}
}

// { Driver Code Starts.

class GFG
{
    public static void main(String args[])
    {
        Scanner sc = new Scanner(System.in);
        int t = sc.nextInt();
        
        while(t-- > 0)
        {
            int n =sc.nextInt();
            Solution T = new Solution();
            System.out.println(T.numTrees(n));
        }
    }
}
  // } Driver Code Ends