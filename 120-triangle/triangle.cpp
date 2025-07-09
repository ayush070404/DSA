class Solution {
public:

    int solve(int size , int row , int col , vector<vector<int>>& triangle, vector<vector<int>> &dp){

        if(row == size) return triangle[row][col];
        //   if(row> size|| col > size ) return 1e9;

        if(dp[row][col] != -1) return dp[row][col];

        int down = triangle[row][col] + solve(size, row+1 , col , triangle, dp);
        int diag = triangle[row][col] + solve(size ,row+1 , col+1 , triangle, dp);
        dp[row][col] = min(down , diag);
        
        return dp[row][col];
    }

    int minimumTotal(vector<vector<int>>& triangle) {
        int n = triangle.size();
        vector<vector<int>> dp(n , vector<int>(n , -1));
        return solve(n-1 , 0 ,0 , triangle , dp);
    }
};