class Solution {
public:
    int pivotIndex(vector<int>& nums) {
        int totalSum = accumulate(nums.begin(), nums.end(), 0);
        int leftSum = 0;

        for (int i = 0; i < nums.size(); ++i) {
            if (2 * leftSum + nums[i] == totalSum) {
                return i;
            }
            leftSum += nums[i];  // sliding left window sum
        }

        return -1;
    }
};
