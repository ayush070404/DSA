class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        int n = nums.size();
        sort(nums.begin(), nums.end());
        vector<vector<int>> ans;

        for(int i = 0; i < n; i++) {
            // Skip duplicate nums[i]
            if (i > 0 && nums[i] == nums[i - 1]) continue;

            int left = nums[i];
            int l = i + 1, r = n - 1;

            while (l < r) {
                int mid = nums[l];
                int right = nums[r];

                int sum = left + mid + right;

                if (sum == 0) {
                    ans.push_back({left, mid, right});  /// how to push triplets;

                    // Skip duplicates for nums[l] and nums[r]
                    while (l < r && nums[l] == nums[l + 1]) l++;
                    while (l < r && nums[r] == nums[r - 1]) r--;

                    // l++;
                    r--;
                }
                else if (sum < 0) {
                    l++;  // Move left forward to increase sum
                }
                else {
                    r--;  // Move right backward to decrease sum
                }
            }
        }

        return ans;
    }
};
