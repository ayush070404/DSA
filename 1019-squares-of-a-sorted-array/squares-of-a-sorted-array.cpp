class Solution {
public:
    vector<int> sortedSquares(vector<int>& nums) {
        int n = nums.size();
        vector<int> ans(n);
        int l = 0, r = n - 1;
        int pos = n - 1;

        while (l <= r) {
            if (abs(nums[l]) > abs(nums[r])) {
                ans[pos] = nums[l] * nums[l];
                l++;
                pos--;
            } else {
                ans[pos] = nums[r] * nums[r];
                r--;
                pos--;
            }
        }

        return ans;
    }
};
