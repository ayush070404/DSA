class Solution {
public:
    int minFallingPathSum(vector<vector<int>>& matrix) {
        int n = matrix.size();
        if (n == 1) return matrix[0][0]; // Edge case: single row
        
        vector<vector<int>> dp(n, vector<int>(n, 0));
        
        // Initialize the last row of dp with the values from the matrix
        for (int col = 0; col < n; ++col) {
            dp[n - 1][col] = matrix[n - 1][col];
        }
        
        // Fill the dp table from the second last row to the first row
        for (int row = n - 2; row >= 0; --row) {
            for (int col = 0; col < n; ++col) {
                int down = dp[row + 1][col];
                int diagLeft = (col > 0) ? dp[row + 1][col - 1] : INT_MAX;
                int diagRight = (col < n - 1) ? dp[row + 1][col + 1] : INT_MAX;
                
                dp[row][col] = matrix[row][col] + min({down, diagLeft, diagRight});
            }
        }
        
        // The answer is the minimum value in the first row of dp
        int minSum = INT_MAX;
        for (int col = 0; col < n; ++col) {
            minSum = min(minSum, dp[0][col]);
        }
        
        return minSum;
    }
};