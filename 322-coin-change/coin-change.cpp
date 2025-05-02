class Solution {
public:

    int coinChange(vector<int>& coins, int amount) {
        int n = coins.size();

        vector<vector<int>> dp(n , vector<int> (amount+1 , 0));

        for(int T =0 ; T<= amount ; T++){
            if(T % coins[0] == 0) dp[0][T] =T / coins[0];
            else dp[0][T] = INT_MAX;
        }
        


        for(int ind = 1 ; ind< n ; ind++){
            for(int amt = 0 ; amt <= amount ; amt++){

                int not_take = 0 + dp[ind-1][amt];
                int take = INT_MAX;
                if (coins[ind] <= amt && dp[ind][amt - coins[ind]] != INT_MAX)
                     take = 1 + dp[ind][amt - coins[ind]];


                dp[ind][amt] = min(take , not_take);
            }
        }
    int ans =  dp[n-1][amount];
    if(ans  >= INT_MAX) return -1;
    else return ans;
    }
};