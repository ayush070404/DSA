class Solution {
public:

    int solve(int ind , vector<int> &coins , int amt , vector<vector<int >> &dp){
        if(ind == 0) {
            if(amt == 0 ) return 0;
            if( amt % coins[0] == 0) return  amt /coins[0];
            return 1e9;
        }

        if(dp[ind][amt] != -1) return dp[ind][amt];

        int not_take = 0 + solve(ind -1 , coins , amt , dp);
        int take = INT_MAX;
        if(coins[ind] <= amt ) take = 1 + solve(ind , coins , amt - coins[ind], dp);

        dp[ind][amt] = min(take , not_take);

        return dp[ind][amt];
    }

    int coinChange(vector<int>& coins, int amount) {
        int n = coins.size();

        vector<vector<int>> dp(n , vector<int> (amount+1 , -1));

        int ans = solve( n-1 , coins , amount , dp);
        if(ans >=1e9 ) return -1;
        else return ans;
    }
};