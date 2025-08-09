//Given a grid of size m x n, the task is to determine the number of distinct paths from the top-left corner to the bottom-right corner. 
//At each step, one can either move down or right. Given the integers m and n, return the number of unique paths from the top-left corner
//to the bottom-right corner.

// Note: The test cases are designed such that the answer will always fit within a 32-bit integer.

//solution

## Memoziation (top-dowm)

class Solution {
  public:
   
   int solve(int m, int n,vector<vector<int>> &dp)
   {
         if (m <= 0 || n <= 0)
      return 0;
      
      if(dp[m][n]!=-1)
      return dp[m][n];
      
      if(m==1 && n==1)
      return 1;
      
      return dp[m][n]= solve(m-1,n,dp)+solve(m,n-1,dp);
   }
   
    int numberOfPaths(int m, int n) {
        // Code Here
    vector<vector<int>>dp(m+1,vector<int>(n+1,-1));
    return solve(m,n,dp);
    }
};
 TC=O(m*n)
 SC=O(m*n)

## tabulation (bottom-up)


class Solution {
  public:
    int numberOfPaths(int m, int n) {
        // Code Here
    vector<vector<int>>dp(m+1,vector<int>(n+1,-1));
    // marking the 1st column cells with path 1
    for(int i=0;i<m;i++)
    dp[i][0]=1;
    
    // marking the 1st row cells with path 1

    for(int j=0;j<n;j++)
    dp[0][j]=1;
    
    for(int i=1;i<m;i++)
    {
        for(int j=1;j<n;j++)
        dp[i][j]=dp[i-1][j]+dp[i][j-1];
    }
    return dp[m-1][n-1];
    }
};
 TC=O(m*n)
 SC=O(m*n)

# Space Optimization


class Solution {
  public:
    int numberOfPaths(int m, int n) {
        // Code Here
   int dp[n]={1};
   
   dp[0]=1;
   
   for(int i=0;i<m;i++)
   {
       for(int j=1;j<n;j++)
       dp[j]+=dp[j-1];
   }
   return dp[n-1];
    }
};
 TC=O(m*n)
 SC=O(n)
