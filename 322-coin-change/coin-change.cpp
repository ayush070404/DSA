class Solution {
public:

    int solve(int ind, vector<int> &coins, int amt, vector<vector<int>> &dp) {
        if (amt == 0) return 0;  
    
        if (ind == 0) {
            if (amt % coins[0] == 0) return amt / coins[0];
            return INT_MAX;  
        }

        if (dp[ind][amt] != -1) return dp[ind][amt];

        int not_take = solve(ind - 1, coins, amt, dp);

        int take = INT_MAX;
        if (coins[ind] <= amt) {
            int subproblem = solve(ind, coins, amt - coins[ind], dp);
            if (subproblem != INT_MAX) {  // Check if it's possible to use the coin
                take = 1 + subproblem;
            }
        }

        dp[ind][amt] = min(take, not_take);  

        return dp[ind][amt];
    }

    int coinChange(vector<int>& coins, int amount) {
        int n = coins.size();
        vector<vector<int>> dp(n, vector<int>(amount + 1, -1)); 
        
        int ans = solve(n - 1, coins, amount, dp);  

        if (ans == INT_MAX) return -1;  
        return ans;  // Return the result
    }
};
