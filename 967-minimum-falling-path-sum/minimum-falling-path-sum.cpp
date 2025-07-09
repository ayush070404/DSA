class Solution {
public:
    int minFallingPathSum(vector<vector<int>>& matrix) {
        int n = matrix.size();

        // Edge case: single row
        if (n == 1) return matrix[0][0];

        vector<vector<int>> dp(n, vector<int>(n, 0));

        // Base case: last row = matrix values
        for (int col = 0; col < n; col++) {
            dp[n - 1][col] = matrix[n - 1][col];
        }

        // Build DP table from bottom to top
        for (int row = n - 2; row >= 0; row--) {
            for (int col = 0; col < n; col++) {
                int down = matrix[row][col]+ dp[row + 1][col];
                int leftDiag, rightDiag;

                // Handle left diagonal
                if (col > 0) {
                    leftDiag = matrix[row][col]+dp[row + 1][col - 1];
                } else {
                    leftDiag = INT_MAX;
                }

                // Handle right diagonal
                if (col < n - 1) {
                    rightDiag = matrix[row][col]+ dp[row + 1][col + 1];
                } else {
                    rightDiag = INT_MAX;
                }

                dp[row][col] = min({down, leftDiag, rightDiag});
            }
        }

        // Result is the minimum in the top row
        int minSum = INT_MAX;
        for (int col = 0; col < n; col++) {
            minSum = min(minSum, dp[0][col]);
        }

        return minSum;
    }
};
