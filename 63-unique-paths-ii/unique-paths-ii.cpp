class Solution {
public:
    int solve(int m, int n ,vector<vector<int>> &dp,vector<vector<int>>& grid ){
        if(m < 0 || n< 0) return 0;
        if(grid[m][n] == 1) return 0;
        if( m == 0 && n == 0) return 1;
        
        if( dp[m][n] != -1) return dp[m][n];
        
        int up = solve(m , n-1, dp, grid);

        int left = solve(m-1 , n, dp, grid);

        return dp[m][n] = up+ left;
    }
    int uniquePathsWithObstacles(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        if(m== 1 && n ==1 && grid[0][0] == 1) return 0;
       
        vector<vector<int>> dp(m, vector<int>(n, -1));
	    return solve(m-1 , n-1 , dp, grid);
        
    }
};

