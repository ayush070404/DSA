class Solution {
public:


    int solve(int ind , vector<int> &coins , int amt , vector<vector<int >> &dp){
        if(ind == 0) {
            if(amt == 0 ) return 1;
            if( amt % coins[0] == 0) return 1;
            return 0;  // to prevent oveflow by INT_MAX;
        }

        if(dp[ind][amt] != -1) return dp[ind][amt];

        int not_take =  solve(ind -1 , coins , amt , dp);
        int take = 0;
        if(coins[ind] <= amt ) take = solve(ind , coins , amt - coins[ind], dp);

        dp[ind][amt] = take + not_take;

        return dp[ind][amt];
    }

    int change(int amount, vector<int>& coins) {
         int n = coins.size();

        vector<vector<int>> dp(n , vector<int> (amount+1 , -1));

        int ans = solve( n-1 , coins , amount , dp);
        // if(ans >=1e9 ) return 0;   // if we can't find the denomination
        return ans;
    }
};