class Solution {
public:
    // int solve (int ind , vector<int> &nums , vector <int> &dp){
    //     if(ind == 0 ) return nums[ind];
    //     if(ind < 0 ) return 0;
    //     if(dp[ind] != -1) return dp[ind];

    //     int take = nums[ind] + solve(ind-2 , nums, dp);
    //     int not_pick = solve(ind -1 , nums ,dp);

    //     dp[ind] = max(take , not_pick);

    //     return dp[ind];
    // }

    int rob(vector<int>& nums) {
        int n = nums.size();
        vector <int> dp(n+1 , -1);
        // return solve(n-1 , nums, dp);

        dp[0] = nums[0];

        for(int ind =1 ; ind<n ; ind++){

            int take = nums[ind] ;
            if(ind>1) take += dp[ind-2];
            int not_pick = 0+ dp[ind-1];
            dp[ind] = max(take , not_pick);
        }
    return dp[n-1];
    }
};