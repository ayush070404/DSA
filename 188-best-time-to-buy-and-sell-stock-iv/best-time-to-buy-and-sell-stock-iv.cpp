class Solution {
public:

    int solve(int ind, int buy , vector<int> &prices , int cap, int n , vector<vector<vector<int>>> &dp){

        if(cap == 0) return 0;
        if(ind == n) return 0;
        int profit = 0;

        if(dp[ind][buy][cap] != -1) return dp[ind][buy][cap];

         if(buy) {
            profit = max(-prices[ind] + solve(ind+1 , 0 , prices, cap, n, dp), 
                            0 + solve(ind+1, 1 , prices, cap, n, dp));
        }
        else{
            profit = max(prices[ind] +solve(ind+1 , 1, prices, cap-1, n, dp), 
                            0 + solve(ind+1 , 0 , prices , cap, n, dp));
        }

       dp[ind][buy][cap] = profit;

    return dp[ind][buy][cap];
    }

    int maxProfit(int k, vector<int>& prices) {
        int n = prices.size();
        vector<vector<vector<int>>> dp(n+1, vector<vector<int>>(2, vector<int>(k+1, -1)));

        return solve(0 , 1 , prices, k , n , dp); 
    }
};