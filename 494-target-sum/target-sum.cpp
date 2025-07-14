class Solution {
public:
    int count_subsets(int ind, int target, vector<int> &nums, vector<vector<int>> &dp) {
        if (ind == 0) {
            if (target == 0 && nums[0] == 0) return 2;
            if (target == 0 || target == nums[0]) return 1;
            return 0;
        }

        if (dp[ind][target] != -1) return dp[ind][target];

        int not_pick = count_subsets(ind - 1, target, nums, dp);
        int pick = 0;
        if (nums[ind] <= target)
            pick = count_subsets(ind - 1, target - nums[ind], nums, dp);

        return dp[ind][target] = pick + not_pick;
    }

    int findTargetSumWays(vector<int>& nums, int target) {
        int total_sum = accumulate(nums.begin(), nums.end(), 0);

        // Edge case: target is too large or invalid
        if ((target + total_sum) % 2 != 0 || (target + total_sum) < 0) return 0;

        int subset_sum = (target + total_sum) / 2;
        vector<vector<int>> dp(nums.size(), vector<int>(subset_sum + 1, -1));

        return count_subsets(nums.size() - 1, subset_sum, nums, dp);
    }
};
