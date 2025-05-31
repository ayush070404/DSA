class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int n = nums.size();
        int ans = INT_MIN;

        for (int l = 0; l < n; l++) {
            int product = 1; // reset for new starting point
            for (int r = l; r < n; r++) {
                product *= nums[r];
                ans = max(ans, product);
            }
        }
        return ans;
    }
};
