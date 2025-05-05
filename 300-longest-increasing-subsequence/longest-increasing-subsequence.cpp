class Solution {
public:

  

    int lengthOfLIS(vector<int>& arr) {
        int n = arr.size();
        vector<vector<int>> dp(n + 1, vector<int>(n + 1, 0));  // dp[ind][prevInd+1]
        for (int ind = n - 1; ind >= 0; ind--) {
        for (int prevInd = ind - 1; prevInd >= -1; prevInd--) {
            int notTake = dp[ind + 1][prevInd + 1];  // shifted prevInd
            int take = 0;

            if (prevInd == -1 || arr[ind] > arr[prevInd]) {
                take = 1 + dp[ind + 1][ind + 1];
            }

            dp[ind][prevInd + 1] = max(take, notTake);
        }
    }

    return dp[0][0];  // dp[0][0] corresponds to solve(0, -1)
    }
};