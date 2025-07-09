class Solution {
public:
    int solve(int row, int col, vector<vector<int>>& grid , vector<vector<int>> &dp) {
        const int INF = 1e9;  // Safe upper bound

        if (row < 0 || col < 0) return INF;

        if (row == 0 && col == 0) return grid[0][0];
        if(dp[row][col] != -1) return dp[row][col];

        int up = grid[row][col] + solve(row - 1, col, grid,dp);
        int left = grid[row][col] + solve(row, col - 1, grid, dp);

        // Return the minimum of the two
        return dp[row][col] = min(up, left);
    }

    int minPathSum(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        vector<vector<int>> dp(m , vector<int>(n , -1));
        dp[0][0] = grid[0][0];

        for(int row = 0 ; row < m ; row++){

            for(int col = 0 ; col < n ; col++){
                int up =1e9 , left =1e9;
                if(row == 0 && col == 0) continue;
                
                else{
                     if(row>=1) up = grid[row][col] + dp[row - 1][col];
                     if(col >=1) left = grid[row][col] + dp[row][col-1];
                }
                dp[row][col] = min(up, left);
            }
        }
        return dp[m-1][n-1];
        // return solve(m-1 , n-1 , grid, dp);
    }
};