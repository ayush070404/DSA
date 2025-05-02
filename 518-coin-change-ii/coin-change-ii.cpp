class Solution {
public:

    int solve(int ind, vector<int> &arr, int val, vector<vector<int>> &dp) {
         if (ind == 0) {
            if (val % arr[0] == 0) return 1;  // Only one way using arr[0] multiple times
            return 0;
        }

        if (dp[ind][val] != -1) return dp[ind][val];

        int not_take = solve(ind - 1, arr, val, dp);
        int take = 0;
        if (arr[ind] <= val)
            take = solve(ind, arr, val - arr[ind], dp); // stay on same index

    return dp[ind][val] = not_take + take;
}

    int change(int amount, vector<int>& coins) {
        int n = coins.size();

        vector<vector<int>> dp(n , vector<int> (amount+1, -1));

        return solve(n-1, coins, amount, dp);
    }
};