class Solution {
public:

    // int solve(int ind, int buy, vector<int> &prices, int n, vector<vector<int>> &dp){

    //     if(ind== n) return 0;
    //     if(dp[ind][buy] !=-1) return dp[ind][buy];
    //     int profit = 0;

    //     if(buy){

    //         profit= max(-prices[ind] + solve(ind+1, 0, prices, n, dp),
    //                     0 + solve(ind+1 , 1, prices, n, dp));
    //     }

    //     else{
    //         profit= max(prices[ind] + solve(ind+1, 1, prices, n, dp),
    //                     0 + solve(ind+1 , 0, prices, n, dp));
    //     }
        
    //     dp[ind][buy] = profit;
    //     return dp[ind][buy];
    // }

    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        vector<vector<int>> dp(n +1 , vector<int> (2 , 0));
        
        int profit = 0;
        for(int ind = n-1 ; ind>= 0; ind--){
            for(int buy = 0; buy <= 1; buy++){
                if(buy){

                    profit= max(-prices[ind] + dp[ind+1][0],
                                0 + dp[ind+1][1]);
                }

                else{
                    profit= max(prices[ind] + dp[ind+1][1],
                                0 + dp[ind+1][0]);
                }
            
                dp[ind][buy] = profit;
            }
        }

    return dp[0][1]; // why not dp[0][1] --> causing intially we are starting with nothing so, can buy
    }
};