class Solution {
public:
    int solve(int ind, int target, vector<int>& nums, unordered_map<string, int>& dp) {
        string key = to_string(ind) + "_" + to_string(target);
        if (dp.count(key)) return dp[key];

        if (ind == 0) {
            int cnt = 0;
            if (nums[0] == target) cnt++;
            if (-nums[0] == target) cnt++;
            return dp[key] = cnt;
        }

        int take = solve(ind - 1, target - nums[ind], nums, dp);
        int not_take = solve(ind - 1, target + nums[ind], nums, dp);

        return dp[key] = take + not_take;
    }

    int findTargetSumWays(vector<int>& nums, int target) {
        unordered_map<string, int> dp;
        return solve(nums.size() - 1, target, nums, dp);
    }
};
