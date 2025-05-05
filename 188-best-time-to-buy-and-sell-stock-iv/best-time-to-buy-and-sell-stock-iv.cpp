class Solution {
public:
    int maxProfit(int k, vector<int>& prices) {
        int n = prices.size();
        vector<vector<vector<int>>> dp(n+1, vector<vector<int>>(2, vector<int>(k+1, 0)));

        // return solve(0 , 1 , prices, 2 , n , dp);


        for(int i = 0 ; i< n ; i++){                            // for cap = 0
                for( int j = 0 ; j<= 1 ;j++){
                    dp[i][j][0] = 0;
                }
        }
        for(int i = 1 ; i<= k ; i++){                            // for ind = n
                for( int j = 0 ; j<= 1 ;j++){
                    dp[n][j][i] = 0;
                }
        }


        for(int ind = n-1 ; ind >= 0 ; ind--){
            for(int buy =0 ; buy <= 1; buy++){
                for(int cap =1; cap <= k; cap++){  // cap =0 should not be written as its accessing cap -1
                    int profit = 0;
                    if(buy) {
                    profit = max(-prices[ind] + dp[ind+1][0][cap], 
                                    0 +  dp[ind+1][1][cap]);
                    }
                    else{
                        profit =max(prices[ind] + dp[ind+1][1][cap-1], 
                                    0 +  dp[ind+1][0][cap]);
                    }

                     dp[ind][buy][cap] = profit;
                }
            }
        }

    return dp[0][1][k];

    }
};