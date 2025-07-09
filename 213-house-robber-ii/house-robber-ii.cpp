class Solution {
public:
    int solve (int start, int ind , vector<int> &nums , vector <int> &dp){
        if(ind < start) return 0;
        if(dp[ind] != -1) return dp[ind];

        int take = nums[ind] + solve(start , ind-2 , nums, dp);
        int not_pick = solve(start , ind -1 , nums ,dp);

        dp[ind] = max(take , not_pick);

        return dp[ind];
    }

    int rob(vector<int>& nums) {
        int n = nums.size();
        if(n == 1) return nums[0];
        vector <int> dp(n , -1);
        vector <int> dp2(n , -1);
        int case1 =  solve( 1 , n-1 , nums, dp);
        int case2 =  solve( 0 , n-2 , nums, dp2);

        return max(case1, case2);
    }
};